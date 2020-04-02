/*
** ###################################################################
**
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**
**     Filename  : SHIFT_SH.C
**
**     Project   : itext_gp32
** 
**     Processor : MC68HC908GP32CFB
**
**     Beantype  : BitIO
**
**     Version   : Bean 02.021, Driver 02.15, CPU db: 2.89.000
**
**     Compiler  : Metrowerks HC08 C Compiler
**
**     Date/Time : 17/01/2007, 19:14
**
**     Abstract  :
**
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This bean is set to work in Output direction only.
**         Methods of this bean are mostly implemented as a macros 
**         (if supported by target language and compiler).
**
**     Settings  :
**
**         Used pin                    : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       24            |  PTB2_AD2
**             ----------------------------------------------------
**
**         Port name                   : PTB
**
**         Bit number (in port)        : 2
**         Bit mask of the port        : 4
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 1
**         Initial pull option         : off
**
**         Port data register          : PTB       [1]
**         Port control register       : DDRB      [5]
**
**         Optimization for            : speed
**
**     Contents  :
**
**         GetVal - bool SHIFT_SH_GetVal(void);
**         PutVal - void SHIFT_SH_PutVal(bool Output);
**         ClrVal - void SHIFT_SH_ClrVal(void);
**         SetVal - void SHIFT_SH_SetVal(void);
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

#include "SHIFT_SH.h"

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

/*
** ===================================================================
**     Method      :  SHIFT_SH_GetVal (bean BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This bean is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---        - Input value (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
** ===================================================================
*/
/*
bool SHIFT_SH_GetVal(void)

**  This method is implemented as a macro. See SHIFT_SH.h file.  **

*/

/*
** ===================================================================
**     Method      :  SHIFT_SH_PutVal (bean BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Value      - Output value (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
**     Returns     : Nothing
** ===================================================================
*/
void SHIFT_SH_PutVal(byte Value)
{
  if (Value) {                         /* Is it one to be written? */
    PTB |= 4;                          /* Set bit on port */
  }
  else {                               /* Is it zero to be written? */
    PTB &= ~4;                         /* Clear bit on port */
  }
}

/*
** ===================================================================
**     Method      :  SHIFT_SH_SetVal (bean BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void SHIFT_SH_SetVal(void)

**  This method is implemented as a macro. See SHIFT_SH.h file.  **
*/

/*
** ===================================================================
**     Method      :  SHIFT_SH_ClrVal (bean BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void SHIFT_SH_ClrVal(void)

**  This method is implemented as a macro. See SHIFT_SH.h file.  **
*/

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 03.23 for 
**     the Motorola HC08 series of microcontrollers.
**
** ###################################################################
*/