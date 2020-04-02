/*
** ###################################################################
**
**     Filename  : Events.C
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
/* MODULE Events */

#pragma MESSAGE DISABLE C1420 /* WARNING C1420: Result of function-call is ignored */


/*Including used modules for compilling procedure*/
#include "Cpu.h"
#include "Events.h"

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

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
void Cpu_OnSwINT(void)
{
  /* Write your code here ... */
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 03.23 for 
**     the Motorola HC08 series of microcontrollers.
**
** ###################################################################
*/
