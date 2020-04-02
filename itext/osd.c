#include "osd.h"

#define ZOOM_REGISTER           0xcc
#define COLOR_REGISTER          0xcd
#define CONTROL_REGISTER        0xce
#define POSITION_REGISTER       0xcf
#define MODE_REGISTER           0xd0
#define PAGE_ADDRESS            0x0
#define DATA_REGISTER           0x1000
#define ROW_ATTRIBUTES          0xc0
#define REQUEST                 0xec

#define Tui	unsigned int
#define Tuc unsigned char
void OSD_SendWord (int  word);

union {
  struct {
	 Tui	_PageMode	:1;
	 Tui	_CharMode	:1;
	 Tui	_display	:1;
	 Tui	_c3			:1;
	 Tui	_BlinkOpt	:1;
	 Tui	_BlinkPeriod:2;
	 Tui	_sync		:1;
	 Tui	_standard	:1;
	 Tui	_ColorEnc	:1;
	 Tui	_luminance	:1;
	 Tui	_VideoFullPage:1;
  } _bits;
  Tuc      _valor;
} u_mode; 

 
const char tabla[]={
        '0','1','2','3','4','5','6','7','8','9','-',' ','A','B','C','D','E','F','G','H','I','J','K',
        'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',':','.','/','·','a','b','c','d',
        'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','à',
        'â','ä','á','é','è','ë','ê','ì','î','ï','í','ò','ô','ö','ó','ù','û','ü','ú','Ä','Ö','Ü','ç',
		0,'ñ','+','*'};

void OSD_Reset (void)
{
   char n,i;
   int buff;

   u_mode._valor =0xb8e;

   OSD_SendWord (0x3000);
   OSD_SendWord (0x3000);
   OSD_SendWord (0x0);
   OSD_SendWord (0x1000);                      
   OSD_SendWord (0xdb);
   OSD_SendWord (0x1000);		//Reset del OSD

   OSD_SendWord (CONTROL_REGISTER);
   OSD_SendWord (DATA_REGISTER | 0xb8e);

   OSD_SendWord (MODE_REGISTER);
   OSD_SendWord (DATA_REGISTER| 0x04);

   OSD_SendWord (ZOOM_REGISTER);
   OSD_SendWord (DATA_REGISTER| 0x0);

   OSD_SendWord (COLOR_REGISTER);
   OSD_SendWord (DATA_REGISTER | 0x482);


   for (n=0;n<11 ;n++ )
   {
       OSD_SendWord (ROW_ATTRIBUTES| n);
       OSD_SendWord (DATA_REGISTER | 0x0c0);
   }

   for (n=0;n<11 ;n++ )
   {
       for (i=0;i<28;i++)
       {
           buff=n<<8;
           buff|=i;
           OSD_SendWord (PAGE_ADDRESS| buff);
           OSD_SendWord (DATA_REGISTER | 0x08b);
       }
   }

  
}

void OSD_FullMode (char mode)
{
	u_mode._bits._PageMode = mode;
	OSD_SendWord (CONTROL_REGISTER);
    OSD_SendWord (DATA_REGISTER| u_mode._valor);
}

void OSD_CharMode (char mode)
{
	u_mode._bits._CharMode = mode;
	OSD_SendWord (CONTROL_REGISTER);
    OSD_SendWord (DATA_REGISTER| u_mode._valor);
}

void OSD_DisplayOn (char display)
{
	u_mode._bits._display = display;
	OSD_SendWord (CONTROL_REGISTER);
    OSD_SendWord (DATA_REGISTER| u_mode._valor);
}

void OSD_ColorMode (char mode)
{
	u_mode._bits._c3 = mode;
	OSD_SendWord (CONTROL_REGISTER);
    OSD_SendWord (DATA_REGISTER| u_mode._valor);
}

void OSD_BlinkOption (char option)
{
	u_mode._bits._BlinkOpt = option;
	OSD_SendWord (CONTROL_REGISTER);
    OSD_SendWord (DATA_REGISTER| u_mode._valor);
}

void OSD_BlinkPeriod (char period)
{
	u_mode._bits._BlinkPeriod = period;
	OSD_SendWord (CONTROL_REGISTER);
    OSD_SendWord (DATA_REGISTER| u_mode._valor);
}

void OSD_SyncMode (char mode)
{
	u_mode._bits._sync = mode;
	OSD_SendWord (CONTROL_REGISTER);
    OSD_SendWord (DATA_REGISTER| u_mode._valor);
}

void OSD_StandarType (char type)
{
	u_mode._bits._standard = type;
	OSD_SendWord (CONTROL_REGISTER);
    OSD_SendWord (DATA_REGISTER| u_mode._valor);
}

void OSD_ColorEncoder (char encoder)
{
	u_mode._bits._ColorEnc = encoder;
	OSD_SendWord (CONTROL_REGISTER);
    OSD_SendWord (DATA_REGISTER| u_mode._valor);
}

void OSD_LuminanceLevels (char levels)
{
	u_mode._bits._luminance = levels;
	OSD_SendWord (CONTROL_REGISTER);
    OSD_SendWord (DATA_REGISTER| u_mode._valor);
}

void OSD_VideoFullPageMode (char mode)
{
	u_mode._bits._VideoFullPage = mode;
	OSD_SendWord (CONTROL_REGISTER);
    OSD_SendWord (DATA_REGISTER| u_mode._valor);
}

void OSD_SendWord (int word)
{
	char n;
	OSD_PORT &= ~BIT_OSD_CSU;

	for (n=0;n<16 ;n++ )
	{
		if (word & 0x8000)
			OSD_PORT |=BIT_OSD_DATA;
		else
			 OSD_PORT &= ~BIT_OSD_DATA;

		OSD_PORT &=~BIT_OSD_CLOCK;
		OSD_PORT |=BIT_OSD_CLOCK;

		word = word << 1;	
	}
	OSD_PORT |= BIT_OSD_CSU;
}


void OSD_ScreenPos (char hor, char vert)
{
   int tmp;

   tmp = vert;
   tmp<<=6;
   tmp|=hor;
   OSD_SendWord (POSITION_REGISTER);
   OSD_SendWord (DATA_REGISTER| tmp);
}

void OSD_TextPos (char x, char y)
{
	int iCol = y<<8;

    OSD_SendWord ((PAGE_ADDRESS|iCol)|x);
}

void OSD_PrintStr (char *str)
{
	char car;
    while (*str!=0)
    {
        for (car=0;car<90;car++)
        {
            if (tabla[car]==*str)
               break;
        }
        OSD_SendWord (DATA_REGISTER|car);
		str++;
    }
}

void OSD_PrintChar (char ch, char mode)
{
	char car;
	for (car=0;car<90;car++)
	{
	   if (tabla[car]==ch)
		  break;
	}
	car|=mode;
    OSD_SendWord (DATA_REGISTER|car);
}

void OSD_PrintExChar (char ch, char mode)
{
	ch|=mode;
    OSD_SendWord (DATA_REGISTER|ch);
}

