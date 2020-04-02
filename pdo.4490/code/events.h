/*
** ###################################################################
**
**     Filename  : Events.H
**
**     Project   : itext_gp32
** 
**     Processor : MC68HC908GP32CFB
**
**     Beantype  : Events
**
**     Version   : Driver 01.01
**
**     Compiler  : Metrowerks HC08 C Compiler
**
**     Date/Time : 29/12/05, 9:18
**
**     Abstract  :
**
**         This is user's event module.
**         Put your event handler code here.
**
**     Settings  :
**
**
**     Contents  :
**
**         Cpu_OnSwINT - void Cpu_OnSwINT(void);
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

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

void Cpu_OnSwINT(void);
/*
** ===================================================================
**     Event       :  Cpu_OnSwINT (module Events)
**
**     From bean   :  Cpu [MC68HC908GP32_44]
**     Description :
**         This software event is called after software reset.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/


/* END Events */
#endif /* __Events_H*/

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 03.23 for 
**     the Motorola HC08 series of microcontrollers.
**
** ###################################################################
*/
