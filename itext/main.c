#pragma CREATE_ASM_LISTING ON
/* terminal.wnd */

#include <stdlib.h>
#include <hidef.h>
#include <ctype.h>

#include <hc05c2_r.h>

#include "osd.h"

#pragma DATA_SEG SHORT  DS_RegsHC05
TS_RegsHC05 RegsHC05;

#pragma DATA_SEG DEFAULT

#define lda 0xD6        /* indexed long */
#define sta 0xD7        /* indexed long */
#define jmp 0xCC        /* ext */
#define rts 0x81

#define CCR (*((unsigned char*)(0x1fdf)))
extern char _SEX[4], _LEX[4], _JSR[3];

#define TOTAL_CUC 6

void DoCuc();
void main()
{
}

extern interrupt void SPI()
{
}

extern interrupt void TIMER()
{
}

extern interrupt void IRQ()
{
}

extern interrupt  void SWI()
{
}

extern interrupt void SCI()
{
}

void reset()
{
   CCR = (unsigned char)0xc2;
	//Esto está extraido del módulo que STARTUPX.C que viene con el compilador
	//Inicializa el entorno para que el C funcione correctamente.
	 _LEX[0]= lda; _LEX[3]= rts; _SEX[0]= sta; _SEX[3]= rts;
	 _JSR[0]= jmp;  

	DDRC = 0x83;
	DDRA = 0xff;
	DDRB = 0xfe;

	PORTC=0xff;
	OSD_Reset();

	OSD_ScreenPos (16,26);
	OSD_FullMode (FALSE);
	OSD_BlinkOption (TRUE);
	OSD_BlinkPeriod (MODE_BLINK_75);

	OSD_TextPos (0,0);
	OSD_PrintStr ("1234567890123456789012345678");
	OSD_PrintStr ("2234567890123456789012345678");
	OSD_PrintStr ("3234567890123456789012345678");
	OSD_PrintStr ("4234567890123456789012345678");
	OSD_PrintStr ("5234567890123456789012345678");
	OSD_PrintStr ("6234567890123456789012345678");
	OSD_PrintStr ("7234567890123456789012345678");
	OSD_PrintStr ("8234567890123456789012345678");
	OSD_PrintStr ("9234567890123456789012345678");
	OSD_PrintStr ("0234567890123456789012345678");
	OSD_PrintStr ("1234567890123456789012345678");


//	DoCuc();

	for (; ; );
	
}

void DoCuc()
{
	char n;	
	int constX;
	int constY;
	int i;

	char posX[7];
	char posY[7];
	char idx=0;

	for (n=0;n<7; n++)
	{
		posX[n]=0;
		posY[n]=0;
	}

	constX=1;
	constY=1;
	idx=1;

	while (1)
	{
		OSD_TextPos (posX[0],posY[0]);
		OSD_PrintExChar (0x77,0);
		
		posX[idx]=posX[0];
		posY[idx]=posY[0];
		
		if (idx==TOTAL_CUC)
		{
			OSD_TextPos (posX[1],posY[1]);
			OSD_PrintStr (" ");
			
			for (n=2;n<TOTAL_CUC+1;n++)
			{
				posX[n-1]=posX[n];
				posY[n-1]=posY[n];
			}
			idx=TOTAL_CUC;
			
		}
		else
			idx++;

		posX[0]+=constX;
		posY[0]+=constY;

		if (posX[0]>26) constX=-1;
		if (posX[0]<1) constX=1;
		if (posY[0]>9) constY=-1;
		if (posY[0]<1) constY=1;

		for (i=0;i<3000 ;i++ );
	}
}