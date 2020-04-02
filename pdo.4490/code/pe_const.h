/*
** ###################################################################
**
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**
**     Filename  : PE_Const.H
**
**     Project   : itext_gp32
** 
**     Processor : MC68HC908GP32CFB
**
**     Beantype  : PE_Const
**
**     Version   : Driver 01.00
**
**     Compiler  : Metrowerks HC08 C Compiler
**
**     Date/Time : 29/12/05, 9:18
**
**     Abstract  :
**
**         This bean "PE_Const" contains internal definitions
**         of the constants.
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

#ifndef __PE_Const_H
#define __PE_Const_H

/* Constants for detecting running mode */
#define HIGH_SPEED        0            /* High speed */
#define LOW_SPEED         1            /* Low speed */
#define SLOW_SPEED        2            /* Slow speed */

/* Reset cause constants */
#define RSTSRC_POR        128          /* Power-on reset        */
#define RSTSRC_PIN        64           /* External reset bit    */
#define RSTSRC_COP        32           /* COP reset             */
#define RSTSRC_ILOP       16           /* Illegal opcode reset  */
#define RSTSRC_ILAD       8            /* Illegal address reset */
#define RSTSRC_MODRST     4            /* Normal Monitor Mode Entry Reset*/
#define RSTSRC_MENRST     4            /* Forced Monitor Mode Entry Reset*/
#define RSTSRC_LVI        2            /* Low voltage inhibit reset */

#endif /* _PE_Const_H */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 03.23 for 
**     the Motorola HC08 series of microcontrollers.
**
** ###################################################################
*/
