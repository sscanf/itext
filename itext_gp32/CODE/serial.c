/*
** ###################################################################
**
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**
**     Filename  : SERIAL.C
**
**     Project   : itext_gp32
** 
**     Processor : MC68HC908GP32CFB
**
**     Beantype  : SynchroMaster
**
**     Version   : Bean 02.154, Driver 01.42, CPU db: 2.89.000
**
**     Compiler  : Metrowerks HC08 C Compiler
**
**     Date/Time : 19/01/2007, 19:14
**
**     Abstract  :
**
**         This bean "SynchroMaster" implements MASTER part of synchronous
**         serial master-slave communication.
**
**     Settings  :
**
**         Synchro type                : MASTER
**
**         Serial channel              : SPI
**
**         Protocol
**             Init baud rate          : 6_510us
**             Clock edge              : falling
**             Width                   : 8 bits (always)
**             Empty character         : 0
**             Empty char. on input    : RECEIVED
**
**         Registers
**             Input buffer            : SPDR      [18]
**             Output buffer           : SPDR      [18]
**             Control register        : SPCR      [16]
**             Mode register           : SPCR      [16]
**             Baud setting reg.       : SPSCR     [17]
**
**
**
**         Used pins                   : 
**       ----------------------------------------------------------
**            Function    | On package |    Name
**       ----------------------------------------------------------
**             Input      |     13     |  PTD1_MISO
**             Output     |     14     |  PTD2_MOSI
**             Clock      |     15     |  PTD3_SPSCK
**       ----------------------------------------------------------
**
**     Contents  :
**
**         RecvChar              - byte SERIAL_RecvChar(SERIAL_TComData *Chr);
**         SendChar              - byte SERIAL_SendChar(SERIAL_TComData Chr);
**         CharsInRxBuf          - byte SERIAL_CharsInRxBuf(word *Chr);
**         GetCharsInRxBuf       - word SERIAL_GetCharsInRxBuf(void);
**         SetShiftClockPolarity - byte SERIAL_SetShiftClockPolarity(byte Edge);
**         SetIdleClockPolarity  - byte SERIAL_SetIdleClockPolarity(byte Level);
**
**
**     (c) Copyright UNIS, spol. s r.o. 1997-2002
**
**     UNIS, spol. s r.o.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
**
** ###################################################################
*/


/* MODULE SERIAL. */

#include "SERIAL.h"
#include "SHIFT_SH.h"
#include "OSD_LD.h"
#include "OSD_MUTE.h"

#define OVERRUN_ERR      1             /* Overrun error flag bit   */
#define CHAR_IN_RX       8             /* Char is in RX buffer     */
#define FULL_TX          16            /* Full transmit buffer     */
#define RUNINT_FROM_TX   32            /* Interrupt is in progress */
#define FULL_RX          64            /* Full receive buffer      */

static bool EnUser;                    /* Enable/Disable SPI */
static byte SerFlag;                   /* Flags for serial communication */
                                       /* Bits: 0 - OverRun error */
                                       /*       1 - Unused */
                                       /*       2 - Unused */
                                       /*       3 - Char in RX buffer */
                                       /*       4 - Full TX buffer */
                                       /*       5 - Running int from TX */
                                       /*       6 - Full RX buffer */
                                       /*       7 - Unused */
static byte BufferWrite;               /* Output char SPI commmunication */

/*
** ===================================================================
**     Method      :  HWEnDi (bean SynchroMaster)
**
**     Description :
**         This method is internal. It is used by Processor Expert
**         only.
** ===================================================================
*/
static void HWEnDi(void)
{
  if (EnUser) {                        /* Enable device? */
    SPCR_SPE = 1;                      /* Enable device */
    if (SerFlag & FULL_TX) {           /* Is any char in transmit buffer? */
      SPDR = BufferWrite;              /* Store char to transmitter register */
    SerFlag &= ~FULL_TX;               /* Zeroize FULL_TX flag */
    }
  }
  else {
    SPCR_SPE = 0;                      /* Disable device */
  }
}

/*
** ===================================================================
**     Method      :  SERIAL_RecvChar (bean SynchroMaster)
**
**     Description :
**         If any data received, this method returns one character,
**         otherwise it returns error code (it does not wait for
**         data).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - No data in receiver
**                           ERR_OVERRUN - Overrun error was detected
**                           from last char or block receiving
**                           ERR_FAULT - Fault error was detected
**                           from last char or block receiving. This
**                           error may not be supported on some CPUs
**                           (see generated code).
** ===================================================================
*/
byte SERIAL_RecvChar(byte *Chr)
{
  byte Status;

  Status = SPSCR;                      /* Read the device error register */
  *Chr = SPDR;                         /* Read data from receiver */
  if (!(Status & 128))                 /* Is not received char? */
    return ERR_RXEMPTY;                /* If yes then error is returned */
  if (Status & 32)                     /* Is the overrun error flag set? */
    return ERR_OVERRUN;                /* If yes then error is returned  */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  SERIAL_SendChar (bean SynchroMaster)
**
**     Description :
**         Send one character to the channel.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/
byte SERIAL_SendChar(byte Chr)
{
  if ((!SPSCR_SPTE)||(SerFlag&FULL_TX)) { /* Is last character send? */
    return ERR_TXFULL;                 /* If no then return error */
  }
  if(EnUser) {                         /* Is device enabled? */
    SPDR = Chr;                        /* If yes, send character */
  }
  else {
    BufferWrite = Chr;                 /* If no, save character */
    SerFlag |= FULL_TX;                /* ...and set flag */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  SERIAL_CharsInRxBuf (bean SynchroMaster)
**
**     Description :
**         Return number of characters in the input buffer.
**         (deprecated method)
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to number of characters in the
**                           input buffer
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte SERIAL_CharsInRxBuf(word *Chr)
{
  *Chr = SPSCR_SPRF;                   /* Return number of chars in receive buffer */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  SERIAL_GetCharsInRxBuf (bean SynchroMaster)
**
**     Description :
**         Return number of characters in the input buffer.
**         Note: If the Interrupt service is disabled, and the
**         Ignore empty character is set to yes, and a character has
**         been received, then this method returns 1 although it was
**         an empty character.
**     Parameters  : None
**     Returns     :
**         ---             - Number of characters in the input
**                           buffer.
** ===================================================================
*/
word SERIAL_GetCharsInRxBuf(void)
{
  return SPSCR_SPRF;                   /* Return number of chars in receive buffer */
}

/*
** ===================================================================
**     Method      :  SERIAL_SetShiftClockPolarity (bean SynchroMaster)
**
**     Description :
**         Set the shift clock polarity in runtime. Output data will
**         be shifted on the selected edge polarity.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Edge            - Edge polarity.
**                           0-falling edge
**                           1-rising edge
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED -  Device is disabled
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte SERIAL_SetShiftClockPolarity(byte Edge)
{
  if(Edge > 1)
    return ERR_RANGE;
  EnUser=FALSE;
  HWEnDi();                            /* Disable device */
  SPCR_CPHA = SPCR_CPOL ^ Edge;        /* Set phase bit */
  EnUser=TRUE;
  HWEnDi();                            /* Enable device */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  SERIAL_SetIdleClockPolarity (bean SynchroMaster)
**
**     Description :
**         Set the idle clock polarity in runtime. If communication
**         does not run, clock signal will have required level.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Level           - Idle clock polarity:
**                           0-low
**                           1-high
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED -  Device is disabled
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte SERIAL_SetIdleClockPolarity(byte Level)
{
  if(Level > 1)
    return ERR_RANGE;
  if(SPCR_CPOL != Level) {
    EnUser=FALSE;
    HWEnDi();                          /* Disable device */
    SPCR ^= 24;                        /* Invert polarity and phase bit */
    EnUser=TRUE;
    HWEnDi();                          /* Enable device */
  }
  if (Level)                           /* Set the idle clock polarity for the disable state of the SynchroMaster */
    PTD |= 8;
  else
    PTD &= ~8;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  SERIAL_Init (bean SynchroMaster)
**
**     Description :
**         This method is internal. It is used by Processor Expert
**         only.
** ===================================================================
*/
void SERIAL_Init(void)
{
  SPCR = 0;                            /* Reset the device register */
  #pragma MESSAGE DISABLE C4002        /* Disable warning C4002 "Result not used" */
  SPDR;                                /* Read the device register */
  /* SPSCR: SPRF=0,ERRIE=0,OVRF=0,MODF=0,SPTE=0,MODFEN=0,SPR1=1,SPR0=0 */
  SPSCR = 2;                           /* Set the baud rate register */
  /* SPCR: SPRIE=0,??=0,SPMSTR=1,CPOL=1,CPHA=1,SPWOM=0,SPE=0,SPTIE=0 */
  SPCR = 56;                           /* Set the clock edge to rising */
  SerFlag = 0;                         /* Reset all flags */
  EnUser = TRUE;                       /* Enable device */
  HWEnDi();                            /* Enable/disable device according to the status flags */
}

/* END SERIAL. */

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 03.23 for 
**     the Motorola HC08 series of microcontrollers.
**
** ###################################################################
*/