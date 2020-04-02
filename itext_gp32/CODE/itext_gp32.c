/*
** ###################################################################
**
**     Filename  : itext_gp32.C
**
**     Project   : itext_gp32
** 
**     Processor : MC68HC908GP32CFB
**
**     Version   : Driver 01.04
**
**     Compiler  : Metrowerks HC08 C Compiler
**
**     Date/Time : 29/12/05, 9:18
**
**     Abstract  :
**
**         Main module. 
**         Here is to be placed user's code.
**
**     Settings  :
**
**
**     Contents  :
**
**         No public methods
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
/* MODULE itext_gp32 */


/* Including used modules for compilling procedure */
#include "Cpu.h"
#include "Events.h"
#include "osd.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "delay.h"
#include <stdio.h>
#include <ctype.h>

#define SHIFT_SH	PTB_PTB2


unsigned int SerialIn (void)
{
	unsigned int word=0;
	char n;

	SHIFT_SH = FALSE;
		OSD_SERIAL_PORT &=~BIT_OSD_CLOCK;
		OSD_SERIAL_PORT |=BIT_OSD_CLOCK;
	SHIFT_SH = TRUE;

	for (n=0;n<16;n++ )
	{		
		(word>>=1)&0x7fff;

		if (OSD_SERIAL_PORT & BIT_OSD_DATAIN)
			word |=0x8000;

		OSD_SERIAL_PORT &=~BIT_OSD_CLOCK;
		OSD_SERIAL_PORT |=BIT_OSD_CLOCK;
			
	}
	return word;
}

void main(void)
{
	char strDigitos[10];
	unsigned int dig;
	byte digitos[4];

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/	
	
	DDRD = 0xfd;
	DDRB = 0xfe;
	OSD_CTRL_PORT |= BIT_OSD_CSU;
	OSD_SERIAL_PORT |= BIT_OSD_CLOCK;
	SHIFT_SH = TRUE;

		
		OSD_Reset();
		OSD_ScreenPos (20,40); // OSD_ScreenPos (6,2);
		OSD_CharMode (10);
		OSD_FullMode (FALSE);
		OSD_VideoFullPageMode (FALSE);		
		
		for (;;)
		{
			OSD_TextPos (0,10);
					
			dig = SerialIn();

			digitos[3]=HINIBBLE(HIBYTE(dig));	//1000
			digitos[2]=LONIBBLE(HIBYTE(dig)); //100
			digitos[1]=HINIBBLE(LOBYTE(dig)); //10
			digitos[0]=LONIBBLE(LOBYTE(dig));	//1
			
			
			sprintf(strDigitos,"%d%d%d.%d M",
				digitos[3]%10,digitos[2]%10,digitos[1]%10,digitos[0]%10);
			
			OSD_PrintStr (strDigitos);
	  	delay_ms (50);
		}

#ifndef PE_OS_OSEK_SUPPORT
  for(;;){}
#else
  StartOS(Mode);                       /* Jump to OSEKturbo OS startup */
  /*DO NOT WRITE CODE BELOW THIS LINE*/
#endif PE_OS_OSEK_SUPPORT
}

/* END itext_gp32 */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 03.23 for 
**     the Motorola HC08 series of microcontrollers.
**
** ###################################################################
*/
