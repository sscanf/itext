/*
** ###################################################################
**
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**
**     Filename  : PE_Types.H
**
**     Project   : itext_gp32
** 
**     Processor : MC68HC908GP32CFB
**
**     Beantype  : PE_Types
**
**     Version   : Driver 01.03
**
**     Compiler  : Metrowerks HC08 C Compiler
**
**     Date/Time : 29/12/05, 9:18
**
**     Abstract  :
**
**         This bean "PE_Types" contains internal definitions
**         of the types.
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

#ifndef __PE_Types_H
#define __PE_Types_H

#define  FALSE  0
#define  TRUE   1

/*Types definition*/
typedef unsigned char bool;
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];
typedef void (*tIntFunc)(void);
/*typedef void (*__far tFarPtr)(void);*/

#define in16(var,l,h)  var = ((word)(l)) | (((word)(h)) << 8)
#define out16(l,h,val) { l = (byte)val; h = (byte)(val >> 8); }

#define output(P, V) P = (V)
#define input(P) (P)

#define __DI()  { asm sei; }      /* Disable interrupts  */
#define __EI()  { asm cli; }      /* Enable interrupts */
#define SaveStatusReg()     { asm PSHA; asm TPA; asm SEI; asm STA CCR_reg; asm PULA; } /* This macro is used by Processor Expert. It saves CCR register and disable global interrupts. */
#define RestoreStatusReg()  { asm PSHA; asm LDA CCR_reg; asm TAP; asm PULA; } /* This macro is used by Processor Expert. It restores CCR register saved in SaveStatusReg(). */
#define EnterCritical()     SaveStatusReg()
#define ExitCritical()      RestoreStatusReg()

typedef struct {          /* Black&White Image  */
  word width;             /* Image width  */
  word height;            /* Image height */
  byte *pixmap;           /* Image pixel bitmap */
  word size;              /* Image size   */
  char *name;             /* Image name   */
} TIMAGE;
typedef TIMAGE* PIMAGE ; /* Pointer to image */

/* 16-bit register (Motorola format - big indian) */
typedef union {
   word w;
   struct {
     byte high,low;
   } b;
} TWREG;

#endif /* __PE_Types_H */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 03.23 for 
**     the Motorola HC08 series of microcontrollers.
**
** ###################################################################
*/