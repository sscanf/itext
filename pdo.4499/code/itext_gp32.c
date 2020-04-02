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
#include <string.h>.
//                 ............................|...........................|......................
const char str[]={"ESTO ES UNA DEMOSTRACION DE UN TEXTO CON DESPLAZAMIENTO HACIA LA IZQUIERDA .... "};
char buff[29];

void main(void)
{
	char n;
	char head=0;
	char tail=0;
	
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
		DDRD = 0xff;
		DDRB = 0xfe;
		OSD_CTRL_PORT |= BIT_OSD_CSU;
		OSD_SERIAL_PORT |=BIT_OSD_CLOCK;
		
		
		OSD_Reset();
		OSD_ScreenPos (20,40); // OSD_ScreenPos (6,2);
		OSD_CharMode (10);
		OSD_FullMode (FALSE);
		OSD_VideoFullPageMode (FALSE);

  	OSD_TextPos (0,10);
  	OSD_PrintStr (str);	//Presentamos el texto durante 1 segundo antes de hacer
  	delay_ms (255);			//desplazamiento
  	delay_ms (255);
  	delay_ms (255);
  	delay_ms (255);
  	
		head=0;
		while (TRUE)
		{		
		  	OSD_TextPos (0,10);
	
				tail=head;
				for (n=0;n<28;n++)
				{
					buff[n]=str[head++];
					if (head>strlen (str)-1)
					 head=0;
				}
				
				head=tail+1;
				if (head>strlen (str)) head=0;
				
				buff[29]=0;
		  	OSD_PrintStr (buff);
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
