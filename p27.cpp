#include <graphics.h>

#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include <string.h>
#include <alloc.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

#define ESC 0x1b
#define SPACE 0x39
#define LEFT 0x4b
#define RIGHT 0x4d
#define UP 0x48
#define DOWN 0x50
#define ENTER 0x0d
#define F1 0x3b
#define F2 0x3c
#define F3 0x3d
#define F4 0x3e
#define F5 0x3f
#define F6 0x40
#define TAB 9

  int GraphDriver=1,GraphMode=0,ErrorCode,ErrorFont,MaxX,MaxY;

  int i,j,jt,x,y,n,k,kt,m,ix,iy,k1,done,kama,key,isokey,b,porto;
  int old,code,tax,max1,c1,c2,c3,c4,p1,p2,p3,p0,p4,p00,p44,rev;
  int zoom,test,max,min,wideiso,iso,inver,formula,GUMA;
  int handle,windows,reverse,windows_1,windows_2,windows_3,windows_4;

	float y1,y2,y3,y4,high;
	unsigned char color[8000],bit[8000],pw;
	struct ffblk ffblk;
	struct time t;
	struct date d;
	struct ftime old_date_time;
	char filen[10],ma[4],ka[10],what,name[20],ssi;

  void *old_map,*txt_map,*prn_map,*wind_1,*wind_2,*wind_3,*wind_4,*Map;
  unsigned bit_size,bit_size_1,bit_size_2,bit_size_3,bit_size_4,bit_size_0;
  unsigned Size;

void GRAFwindow(void);
void Initialize(void);
void alarm(int f,int d);
void my_window(int l,int t,int r,int b,char *st,int att);
void Ramka(void);
void Filew(void);
void Coder();
void Filer(void);
void Error(void);
void Help(void);
void Arrow(void);
void Prof(void);
void Limonti(void);
void Printer(void);
void Isoterma(void);
void Image(void);
void Cartoon(void);
void Maxim(void);
void Hard();
void Waiting();

void main(void)
{
	p0=p00=0;p4=p44=255;
	kama=code=old=0;
	windows=reverse=0;
	GUMA=15;

	outportb(0x301,0x2f);//   AntiCrash
	if((access("\\JTERMO\\aga.exe",00) || access("\\JTERMO\\gag.exe",00)
	   || access("\\JTERMO\\agdemo.exe",00))!=0)
		{ printf("\n Sorry, my Body need to troubleshooting.");
		printf("\n My kind regards!");
		printf(" \n                            *Johnt_Termo*");
		getch();
		  goto s19;
		 }

	Ramka();
	_setcursortype(0);

	//          Поиск существующих файлов  типа *.ag_
	     done = findfirst("*.ag_",&ffblk,0);
	     if(done==-1) goto s8;

	       kama++;
	     while (!done)
	    {
	      done = findnext(&ffblk);
	      if(done==0) kama++;
	    }

s8:     my_window(8,8,71,20," MAIN ",543);
		alarm(500,50);
	gotoxy(11,3);
	cputs("   1. Работа с Тестовой картиной...    ");
	gotoxy(11,5);
	cputs("   2. Работа с Тепловой картиной...   ");
	gotoxy(11,7);
	cputs("   3. Работа с Архивом кадров...  ");

	switch(getch()){
	case '1':
//		test=0;
	  porto=0x09;	 kama++;
		outportb(0x301,0x29); // Chess.....
		my_window(8,8,71,20," TEST ",543);
		alarm(500,50);
	gotoxy(8,4);
	cputs("На ВКУ должна быть картинка типа шахматного поля");
	gotoxy(8,6);
  cputs("      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █  ");
	gotoxy(8,7);
  cputs("       █ █ █ █ █ █ █ █ █ █ █ █ █ █ █  ");
	gotoxy(42,11);
	cputs(" Press any Key... ");
	getch();
				    goto s1;
	case '2':
  //		 test=1;
	  porto=0x06;	  kama++;goto s21;

	 case ESC: goto s19;
	 case '3': break;
	  default: Help();Ramka();   goto s8;

	       }
	if(kama==0)   { Error(); goto s8; }
	my_window(8,8,71,20," AGA ",543);
s7: 	gotoxy(11,4);
if(kama==1) printf("   Уже существует  %d кадр !              ",kama);
if(kama>1 && kama<=4) printf("   Уже существует  %d кадра !             ",kama);
if(kama>4) printf("   Уже существует  %d кадров !           ",kama);
	gotoxy(9,6);
	printf("   Введите номер кадра -->          ");
	scanf("%d",&tax);
	if(tax>kama)
	{
	   Error();
	goto s8;
	}
		   my_window(8,8,71,20," READ ",543);
	gotoxy(12,5);
	cputs(  "      Считывание кадра ... ");
	alarm(500,100);
	  Filer();old=1;
			max1=1;
			       gotoxy(12,5);
		cputs("        Минуточку,                   ");
		gotoxy(12,7);
		cputs("        формирование кадра ...        ");
			 Maxim();
				zoom=0;
			    goto s4;



s21:	outportb(0x301,0x26); // Video.....
	  my_window(8,8,71,20," TERMO-SET ",543);
	alarm(700,250);
	gotoxy(8,4);
	cputs("   Настройте тепловизор на тепловое");
	gotoxy(8,6);
	cputs("         изображение обьекта");
	gotoxy(42,11);
	cputs(" Press any Key... ");
	getch();

s1:     my_window(8,8,71,20," HOLDER ",543);
	gotoxy(6,4);
	cputs("          Выполняется  захват  кадра...   ");
	 max1=0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

	Hard();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

		gotoxy(6,4);
		cputs("          WELL   DONE   COMMANDER            ");
		delay(200);


	my_window(8,8,71,20," INFO ",543);
	gotoxy(12,4);alarm(500,100);
	cputs(  "  Введите служебную информацию ");
	gotoxy(12,6);
	cputs(  "   >                      <     ");
	gotoxy(17,6);
	scanf("%20s",name);
	fflush(stdin);
	gotoxy(12,4);
		cputs("        Минуточку,                   ");
		gotoxy(12,6);
		cputs("        формирование кадра ...       ");

	 Maxim();
//       Автоподстройка шкалы first look
	   if( max < (p4-64)) p4=max+25;
	zoom=0;
// -----------------------------------------------------------------

s4:	Coder(p0,p4,0);
	Initialize();
	Cartoon();

// -----------------------------------------------------------------

	closegraph();
	_setcursortype(0);
	textbackground(8);
	Ramka();
//          ____________________________BACKWINDER_______
		p0=p00;p4=p44;
		code=max=old=0;
		if(max1!=1) kama--;
				 goto s8;
//          _____________________________________________
s19:	textbackground(8);
	window(1,1,80,25);
	clrscr();
	_setcursortype(2);

	outportb(0x301,0x2f);  // Security

	printf("\r\a   До нових зустрiчей,Панове !!!");
	printf("\n     OK.    ");
	exit(0);
}
// *********************************************************************
void Initialize(void)
{                                /*   Г Р А Ф И К А    */
	    ErrorCode = registerbgidriver(CGA_driver);
	    ErrorFont = registerbgifont(small_font);

    if (ErrorCode < 0 || ErrorFont < 0)
    {            printf("error CGA or LITT !");}

	  initgraph(&GraphDriver,&GraphMode,"" );
	  if( ErrorCode != grOk)
{ printf("\n Ошибка гpафики :%s\n",grapherrormsg( ErrorCode ));
	  exit(1);}
	  MaxX=getmaxx();
	  MaxY=getmaxy();
  }
void alarm(int f,int d)          //   Зуммер
   {
   sound(f);delay(d);nosound();
   }
void Filew()   //  Запись файла_______________________________________
     {
     itoa(kama,filen,10);
     strcat(filen,".ag_");
if ((handle = open(filen, O_RDWR | O_BINARY | O_CREAT,S_IWRITE)) == -1)
  {
      perror("Error: Open Write!");
      exit(0);
   }
      _write(handle,bit,sizeof(bit));
      _write(handle,&p0,sizeof(p0));
      _write(handle,&p4,sizeof(p4));
      _write(handle,&name,sizeof(name));
//      _write(handle,&test,sizeof(test));
	 _close(handle);
}
void Filer()    //  Чтение файла______________________________________
     {
     itoa(tax,filen,10);
     strcat(filen,".ag_");
     if ((handle = open(filen, O_RDWR | O_BINARY)) == -1)
   {
      perror("Error: Open Read!");
      exit(0);
   }
      _read(handle,bit,sizeof(bit));
      _read(handle,&p0,sizeof(p0));
      _read(handle,&p4,sizeof(p4));
      _read(handle,&name,sizeof(name));
//      _read(handle,&test,sizeof(test));
	getftime(handle,&old_date_time);
	 _close(handle);
	}
void Coder(int p0,int p4,int inver) //  Псевдоpаcцвечивание экpана
{
    y1=y2=y3=y4=1;
    p1=p0+(p4-p0)/4;
    p2=p1+(p4-p0)/4;
    p3=p2+(p4-p0)/4;
      if(inver==2)
      { for (i=0;i<=8000;i++)
	{
		formula=bit[i]*255/63;
		if(formula > GUMA) formula=formula+GUMA;

	  if(formula<(iso-wideiso/2) || formula>(iso+wideiso/2))
		{ color[i]=0; y1++;  }
	  else
		{ color[i]=1; y2++;  }
	}
	k1=0;
      }
      else
	       {
	if(inver==0) {
	c1=0;c2=1;c3=3;c4=2;
		       }
	else {c1=2;c2=3;c3=1;c4=0;}

	for (i=0;i<=8000;i++)
	{
		formula=bit[i]*255/63;
		if(formula > GUMA) formula=formula+GUMA;

	  if(formula<=p1) {color[i]=c1;y1++;}
	  if(formula>p1 && formula<=p2) {color[i]=c2;y2++;}
	  if(formula>p2 && formula<p3) {color[i]=c3;y3++;}
	  if(formula>=p3) {color[i]=c4;y4++;}
	}
	if(color[min]==0)    // Color Arrow MAX
	    k1=2;
	else
	    k1=0;
	       }
	}

void GRAFwindow()     // _____________________________________
{
setviewport(0,0,MaxX,MaxY,1);
	if(zoom==1)
	  clearviewport();
	  setbkcolor(0);
	  rectangle(0,0,201,161);
	  rectangle(203,0,319,161);
	  rectangle(0,163,201,199);
	  rectangle(203,163,319,199);

	rectangle(211,5,225,47);
		setfillstyle(1,c1);
		bar(212,6,224,16);
		setfillstyle(1,c2);
		bar(212,16,224,26);
		setfillstyle(1,c3);
		bar(212,26,224,36);
		setfillstyle(1,c4);
		bar(212,36,224,46);

		outtextxy(229,6,"<+");outtextxy(229,17,"<+");
		outtextxy(229,28,"<+");outtextxy(229,39,"<+");
		outtextxy(305,6,"C");outtextxy(305,17,"C");
		outtextxy(305,28,"C");outtextxy(305,39,"C");
		outtextxy(270,6,".");outtextxy(270,17,".");
		outtextxy(270,28,".");outtextxy(270,39,".");
		sprintf(ka,"%d",p0);outtextxy(245,6,ka);
		sprintf(ka,"%d",p1);outtextxy(277,6,ka);outtextxy(245,17,ka);
		sprintf(ka,"%d",p2);outtextxy(277,17,ka);outtextxy(245,28,ka);
		sprintf(ka,"%d",p3);outtextxy(277,28,ka);outtextxy(245,39,ka);
		sprintf(ka,"%d",p4);outtextxy(277,39,ka);

	Limonti();
	if(zoom==0){
	switch(windows){
	case 0:
		bit_size_0=imagesize(1,1,100,80);
			if((wind_1 = malloc(bit_size_0))==(void*)0)
			{cprintf("Wind 1 !");exit(0);}
		getimage(1,1,100,80,wind_1);
		  break;

	case 1: bit_size_1=imagesize(1,1,100,80);
			if((wind_2 = malloc(bit_size_1))==(void*)0)
			{cprintf("Wind 2 !");exit(0);}
		getimage(1,1,100,80,wind_2);
		  break;

	case 2: bit_size_2=imagesize(1,1,100,80);
			if((wind_3 = malloc(bit_size_2))==(void*)0)
			{cprintf("Wind 3 !");exit(0);}
		getimage(1,1,100,80,wind_3);
		 break;

	case 3: bit_size_3=imagesize(1,1,100,80);
			if((wind_4 = malloc(bit_size_3))==(void*)0)
			{cprintf("Wind 4 !");exit(0);}
		getimage(1,1,100,80,wind_4);
		 break;

	case 4:   bit_size_0=imagesize(1,1,100,80);
			if((wind_4 = malloc(bit_size_0))==(void*)0)
			{cprintf("Wind 4 !");exit(0);}
		getimage(1,1,100,80,wind_4);
		 break;
		       }
		   }

		   rectangle(0,0,201,161);
	rectangle(1,1,200,160);
	settextstyle(DEFAULT_FONT,0,1);
	if(code==0)
	{
	setcolor(k1);
	if(zoom!=0)
	Arrow();
	setcolor(3);
		outtextxy(3,175,"Макс.температура =    C");  }
	   else outtextxy(3,175,"Шкала температур");

	alarm(492,50);
	outtextxy(3,166,"Кадр N  ");
	outtextxy(3,187,">                      <");
	setcolor(2);

	outtextxy(12,187,name);
	switch(old)  {
    case 0: sprintf(ka," %d ",kama);outtextxy(53,166,ka);
	    gettime(&t);
	    getdate(&d);
	    settextstyle(2,0,4);
	    sprintf(ka,"%2d:",t.ti_hour);outtextxy(216,50,ka);
	    sprintf(ka,"%02d",t.ti_min);outtextxy(231,50,ka);
	    sprintf(ka,"%2d/",d.da_day);outtextxy(253,50,ka);
	    sprintf(ka,"%02d/",d.da_mon);outtextxy(269,50,ka);
	    sprintf(ka,"%d",d.da_year);outtextxy(288,50,ka);
	    break;
    case 1: sprintf(ka," %d ",tax);outtextxy(53,166,ka);
	    settextstyle(2,0,4);
	    sprintf(ka,"%2d:",old_date_time.ft_hour);outtextxy(216,50,ka);
	    sprintf(ka,"%02d",old_date_time.ft_min);outtextxy(231,50,ka);
	    sprintf(ka,"%2d/",old_date_time.ft_day);outtextxy(253,50,ka);
	    sprintf(ka,"%02d/",old_date_time.ft_month);outtextxy(269,50,ka);
	    sprintf(ka,"%d",old_date_time.ft_year+1980);outtextxy(288,50,ka);
	    break;
		       }
	settextstyle(SMALL_FONT,0,4);
	if(code==0) {
	    sprintf(ma,"+%d ",max);
	    outtextxy(153,171,ma);}
	setcolor(3);
	y1=76+(80-80*y1/8000);
	y2=76+(80-80*y2/8000);
	y3=76+(80-80*y3/8000);
	y4=76+(80-80*y4/8000);

	setfillstyle(1,c1);
	bar3d(210,y1,224,158,5,1);
	setfillstyle(1,c2);
	bar3d(232,y2,246,158,5,1);
	setfillstyle(1,c3);
	bar3d(254,y3,268,158,5,1);
	setfillstyle(1,c4);
	bar3d(276,y4,290,158,5,1);
	alarm(592,50);
	}
void Limonti()    //  Заморочка с кадром  old 80x100 to new 160x200.
{
//                  1x1...............
     if(zoom==0)
    {

		rectangle(1,1,101,80);
	i=0;
	for(y=1;y<=79;y++)
	{

	for(j=1;j<=100;j++)
	    {
	  putpixel(j,y,color[i]);
	      i++;
	    }
	}

     }

	 else
      {
//                        2x1.................
	  y=1;
	  i=x=0;
s2:         	      putpixel(x,y,color[i]);
		 putpixel(x,y+1,color[i]);


	  if(min==i)
	  { ix=y;iy=x;
	  }
		      x++;
	      putpixel(x,y,color[i]);
		putpixel(x,y+1,color[i]);
	      if (x < 200)
	      {i++;x++;
		   goto s2;
		}
	      else
			y=y+2;x=0;
			if(y<=157)  goto s2;
      }
      }

void Error()     //Окно ошибки
{    my_window(8,8,71,20," EMPTY ! ",203);
	  gotoxy(10,5);
	cputs("      Kадра не существует, повторите.");
	alarm(450,100);alarm(400,100);alarm(375,70);
	sleep(1);}
void Help()     //Окно Help
{my_window(4,3,77,25," HELP ═════════════════════════════════ Е.Завальнюк (т.43-96-81) ",781);
     gotoxy(5,3);
	cputs(  "1,2,3 : Выбор режима работы комплекса");
     gotoxy(8,4);
	cputs(  "ESC: Выход без проблем...");
     gotoxy(4,6);
    cputs(  "(!) Нижеследующие команды применимы только при просмотре кадра:");
     gotoxy(9,7);
	cputs(  "F1: Расширение первого диапазона шкалы температур");
     gotoxy(9,8);
	cputs(  "F2: Расширение второго диапазона шкалы температур");
     gotoxy(9,9);
	cputs(  "F3: Расширение третьего диапазона шкалы температур");
     gotoxy(9,10);
	cputs(  "F4: Расширение четвертого диапазона шкалы температур");
     gotoxy(6,11);
	cputs("ENTER: Восстановление начального диапазона температур,");
     gotoxy(10,12);
	cputs(  "   а также Увеличение кадра в 2 раза ");
     gotoxy(10,13);
	cputs(  "P: Печать текущего кадра (by PrintScreen)");
     gotoxy(6,14);
	cputs(  "< ^ >: Определение точки интереса в кадре ");
     gotoxy(10,15);
	cputs(  "   а также Уровень и Ширина изотермы");
     gotoxy(10,16);
	cputs(  "W: Запись кадра на диск ");
     gotoxy(10,17);
	cputs(  "N: Получение негатива ");
     gotoxy(10,18);
	cputs(  "I: Режим изотермы ");
     gotoxy(8,19);
	cputs(  "TAB: Переход между текущими кадрами ");
     gotoxy(28,21);
	cputs(  " Learning version ");
     getch();
	     }
void my_window(int l,int t,int r,int b,char *st,int att)
     { int y;
     window(l,t,r,b);  textattr(att);    gotoxy(1,1);
     cprintf("%c%c%c%s",201,205,205,st);
     while(wherex()!= r-l-1) cprintf("%c",205);
     cprintf("%c\b\n",187);
     while(wherey()!= b-t-1) cprintf("%c\b\n",186);
     cprintf("%c",188);  gotoxy(1,2);
     while(wherey()!= b-t-1) cprintf("%c\b\n",186);
     cprintf("%c",200);
     while(wherex()!= r-l-1)  cprintf("%c",205);
     gotoxy(2,2);
     y = 2;
     while(wherey()!= b-t-2)
     {
     gotoxy(2,y);
     while(wherex()!= r-l-1)  cprintf("%c",32);
     y++;
     }
       }
void Ramka()    //   Надписи
{
window(1,1,80,25);clrscr();textattr(2);
gotoxy(1,1);cputs("(C)1993,НИТ Ltd(Винница).");
gotoxy(67,1);cputs("Help - ПОМОЩЬ");
textattr(15);
	gotoxy(1,25);
cputs("_ЭКСПРЕСС-ТЕРМОДИАГНОСТИКА_______________________________ТВ-03+IBM/XT+Firmware_");
}
void Arrow()
{
putpixel(iy+2,ix+2,k1);putpixel(iy+2,ix+3,k1);
putpixel(iy+2,ix+4,k1);putpixel(iy+2,ix+5,k1);putpixel(iy+2,ix+6,k1);
putpixel(iy+2,ix+7,k1);
putpixel(iy+3,ix+2,k1);putpixel(iy+3,ix+3,k1);
putpixel(iy+3,ix+4,k1);putpixel(iy+3,ix+5,k1);putpixel(iy+3,ix+6,k1);
putpixel(iy+4,ix+2,k1);putpixel(iy+4,ix+3,k1);
putpixel(iy+4,ix+4,k1);putpixel(iy+4,ix+5,k1);
putpixel(iy+5,ix+2,k1);putpixel(iy+5,ix+3,k1);putpixel(iy+5,ix+4,k1);
putpixel(iy+5,ix+5,k1);putpixel(iy+5,ix+6,k1);
putpixel(iy+6,ix+2,k1);putpixel(iy+6,ix+3,k1);putpixel(iy+6,ix+5,k1);
putpixel(iy+6,ix+6,k1);putpixel(iy+6,ix+7,k1);
putpixel(iy+7,ix+2,k1);putpixel(iy+7,ix+6,k1);
putpixel(iy+7,ix+7,k1);putpixel(iy+7,ix+8,k1);
putpixel(iy+8,ix+7,k1);putpixel(iy+8,ix+8,k1);
					 }

void Prof()      // мишень на спине
{   int digit,leo[160],lion[200];

s1:       j=100;k=80;
    x=j+3;y=1;
    for(i=0;i<160;i++)
	{ leo[i]=getpixel(x,y);y++;}
    y=k+3;x=1;
    for(i=0;i<200;i++)
	{ lion[i]=getpixel(x,y);x++;}

    setcolor(2);
    line(217,193,217,166);
    line(217,193,305,193);
    settextstyle(2,1,2);
    sprintf(ka,">  +%d",max);
    outtextxy(207,167,ka);
    settextstyle(2,0,4);
s16:                        x=217;y=192;
     setfillstyle(1,0);
		bar(j-1,160,j+5,164);
		bar(200,k,204,k+5);
		bar(170,145,196,159);
     setcolor(3);
		rectangle(1,1,200,160);
		rectangle(169,144,197,158);
		   setcolor(2);
		   outtextxy(j,156,"^");
		   settextstyle(2,1,4);
		   outtextxy(196,k-2,"^");
		   settextstyle(2,0,4);
      if(j>1)i=j/2;
      else i=j;
      if(k<=2)digit=k/2+j/2;
      else
	   digit=(k/2)*100+j/2;
	   formula=bit[digit]*255/63;
		if(formula > GUMA) formula=formula+GUMA;

      sprintf(ka,"+%d",formula);outtextxy(172,145,ka);

      for(n=1;n<=80;n++)
		 {
      high=25*bit[i]/127;
      putpixel(x++,y-high,color[i]);
//      delay(5);
      i=i+100;
		 }

s15:    key=getch();
	if(!key){
	 key=getch();
	 switch(key){
  case RIGHT:
	   j=j+4;
	    if(j<1 || j>196) {  j=j-4;
	    alarm(450,100);alarm(400,100);alarm(375,70);
	   goto s15;
	   } else
	     {  setcolor(0);line(0,162,320,162);
		    setcolor(3);
	      rectangle(1,1,200,160);
	   rectangle(0,0,201,161);
	   rectangle(0,163,201,199);
	    bar(218,164,318,192);
	   x=j-1;y=1;
	      for(i=0;i<160;i++)
		{ putpixel(x,y,leo[i]);y++;}
	   x=j+3;y=1;
	      for(i=0;i<160;i++)
		{ leo[i]=getpixel(x,y);y++;}
		if(y1<116)
		    setcolor(1);
		    else
		    setcolor(0);
		line(j+3,160,j+3,1);
	   setcolor(2);
	   goto s16;   }
  case LEFT:
	   j=j-4;
	      if(j<1 || j>196) {  j=j+4;
	   alarm(450,100);alarm(400,100);alarm(375,70);
	   goto s15;
	   }  else
	    {  setcolor(0);line(0,162,320,162);
		    setcolor(3);
	      rectangle(1,1,200,160);
	   rectangle(0,0,201,161);
	   rectangle(0,163,201,199);
	    bar(218,164,318,192);

	   x=j+7;y=1;
	      for(i=0;i<160;i++)
		{ putpixel(x,y,leo[i]);y++;}
	   x=j+3;y=1;
	      for(i=0;i<160;i++)
		{ leo[i]=getpixel(x,y);y++;}
		if(y1<116)
		    setcolor(2);
		    else
		    setcolor(0);
		line(j+3,160,j+3,1);

	   setcolor(2);
	   goto s16;  }
   case UP:
	   k=k-4;
	      if(k<1 || k>155) {  k=k+4;
	   alarm(450,100);alarm(400,100);alarm(375,70);
	   goto s15;
	   }  else
	    {  setcolor(0);line(202,0,202,160);
	      setcolor(3);
	      rectangle(1,1,200,160);
	   rectangle(0,0,201,161);
	   rectangle(203,0,319,161);
	   rectangle(0,0,200,161);
	   y=k+7;x=1;
	      for(i=0;i<200;i++)
		{ putpixel(x,y,lion[i]);x++;}
	   y=k+3;x=1;
	      for(i=0;i<200;i++)
		{ lion[i]=getpixel(x,y);x++;}
	      setcolor(3);
		line(200,k+3,1,k+3);
	   setcolor(2);
	   goto s16;  }
   case DOWN:
	   k=k+4;
	      if(k<1 || k>155) {  k=k-4;
	   alarm(450,100);alarm(400,100);alarm(375,70);
	   goto s15;
	   }  else
	    {  setcolor(0);line(202,0,202,160);
	      setcolor(3);
	      rectangle(1,1,200,160);
	   rectangle(0,0,201,161);
	   rectangle(203,0,319,161);
	   rectangle(0,0,200,161);
	   y=k-1;x=1;
	      for(i=0;i<200;i++)
		{ putpixel(x,y,lion[i]);x++;}
	   y=k+3;x=1;
	      for(i=0;i<200;i++)
		{ lion[i]=getpixel(x,y);x++;}
	      setcolor(2);
		line(200,k+3,1,k+3);
	   setcolor(2);
	   goto s16;  }
	   case F1:
	   code=1;p4=p1;
		Waiting();
	    Coder(p0,p4,0);      break;
	   case F2:
	   code=1;p0=p1;p4=p2;
	   Waiting();
	   Coder(p0,p4,0);break;
	   case F3:
	   code=1;p0=p2;p4=p3;
		Waiting();
	   Coder(p0,p4,0);break;
	   case F4:
	   code=1;p0=p3;
		Waiting();
	   Coder(p0,p4,0); break;
		   } }
	 else
	   switch(key){
	   case 'h':
		setfillstyle(1,0);
		bar(212,6,224,46);
	setcolor(2);
		outtextxy(213,3,"F1");
		outtextxy(213,13,"F2");
		outtextxy(213,24,"F3");
		outtextxy(213,35,"F4");
		goto s15;
	   case ENTER:
		p0=p00;p4=p44;
		Waiting();

		 Coder(p0,p4,0);code=1;  break;
	   case 'n':   Waiting();
	     Coder(p0,p4,1); code=1;break;
	   case 'p':

		    jt=j;kt=k;
		  Printer();
		    settextstyle(2,0,4);
		    j=jt;k=kt;
		  goto s16;
	   case 'i':
		     bit_size=imagesize(1,1,200,160);
			if((old_map = malloc(bit_size))==(void*)0)
			  {cprintf("KARAMBA !");exit(0);}
			getimage(1,1,200,160,old_map);  // copy kadr
		Isoterma();
		  setfillstyle(1,0);
		   bar(3,175,175,182);
		   setcolor(3);
		   settextstyle(0,0,1);
		   outtextxy(3,175,"Макс.температура =    C");
		   setcolor(2);
		   settextstyle(2,0,4);
		   sprintf(ma,"+%d ",max);
		   outtextxy(153,171,ma);
			putimage(1,1,old_map,COPY_PUT);

			 Coder(p0,p4,0);
			 bar(210,70,295,158);
			 setcolor(3);
	y1=76+(80-80*y1/8000);
	y2=76+(80-80*y2/8000);
	y3=76+(80-80*y3/8000);
	y4=76+(80-80*y4/8000);

	setfillstyle(1,c1);
	bar3d(210,y1,224,158,5,1);
	setfillstyle(1,c2);
	bar3d(232,y2,246,158,5,1);
	setfillstyle(1,c3);
	bar3d(254,y3,268,158,5,1);
	setfillstyle(1,c4);
	bar3d(276,y4,290,158,5,1);
			goto s16;
	case 'w':
		   bit_size=imagesize(40,50,170,90);
			if((prn_map = malloc(bit_size))==(void*)0)
			  {cprintf("KARAMBA !");exit(0);}
			getimage(40,50,170,90,prn_map);  // copy kadr

	 rectangle(40,50,170,90);
	 setfillstyle(1,0);
	 bar(41,51,169,89);
	 settextstyle(DEFAULT_FONT,0,1);
		   if(max1==1)
		   {
		outtextxy(55,60,"Кадр уже ");
		 outtextxy(65,70," записан !");
		 alarm(350,250);alarm(450,250);alarm(550,250);
		 sleep(1);
		   }
		   else
		   {
	 outtextxy(55,60,"Запись ");
		 outtextxy(65,70," кадра...");
		 Filew();      max1=1;
		 alarm(350,250);alarm(450,250);alarm(550,250);
		   }
			putimage(40,50,prn_map,COPY_PUT);
		     settextstyle(SMALL_FONT,0,4);
			goto s16;
		      }
		   }
void Printer()        //__ печать экрана ___________________________
{
     pw=inportb(0x379);
     if(pw!=223)
      {
			bit_size=imagesize(1,1,200,160);
			if((prn_map = malloc(bit_size))==(void*)0)
			  {cprintf("KARAMBA !");exit(0);}
			getimage(40,50,170,90,prn_map);  // copy kadr

	 rectangle(40,50,170,90);
	 setfillstyle(1,0);
	 bar(41,51,169,89);
	 settextstyle(DEFAULT_FONT,0,1);
	 outtextxy(55,60,"Принтер не ");
		 outtextxy(65,70," готов !");
	 alarm(350,250);alarm(450,250);alarm(550,250);
	 sleep(1);
			putimage(40,50,prn_map,COPY_PUT);

	  }
     else
	 geninterrupt(0x05);
	   }
void Isoterma()              //____________________________________
{

	if((p4-p0)<10)wideiso=2;
	else wideiso=(p4-p0)/8;
	iso=p0+(p4-p0)/2;

	setfillstyle(1,0);
	bar(3,175,175,182);
	   setcolor(3);
	   settextstyle(0,0,1);
	outtextxy(3,175,"Уровень изотермы =    C");
	Waiting();

	Coder(p0,p4,2);Limonti();
		bar(170,145,196,158);
		rectangle(169,144,197,158);
		rectangle(0,0,201,161);
	setcolor(2);
		rectangle(1,1,200,160);
	settextstyle(2,0,4);
	sprintf(ma,"+%d ",iso);
	    outtextxy(153,171,ma);
	sprintf(ka,"<%d>",wideiso);
	    outtextxy(172,145,ka);


s25:    bar(210,70,295,158);

	y1=76+(80-80*y1/8000);
	y2=76+(80-80*y2/8000);
	setfillstyle(1,c1);
	bar3d(210,y1,224,158,5,1);
	setfillstyle(1,c2);
	bar3d(232,y2,246,158,5,1);
	setfillstyle(1,0);

s22:	key=getch();
	if(!key){
	 isokey=getch();
	 switch(isokey){
  case LEFT:
	 if(iso>p0)
	     { iso=iso-1;
		bar(159,175,175,182);
		sprintf(ma,"+%d ",iso);
		outtextxy(153,171,ma);
			       bar(170,145,196,157);
		setcolor(2);
		sprintf(ka,"<%d>",wideiso);
		outtextxy(172,145,ka);
	     }
	 else {alarm(450,100);alarm(400,100);alarm(375,70);}
		goto s22;
  case RIGHT:
	 if(iso<p4)
	     { iso=iso+1;
		bar(159,175,175,182);
		sprintf(ma,"+%d ",iso);
		outtextxy(153,171,ma);
				bar(170,145,196,157);
		setcolor(2);
		sprintf(ka,"<%d>",wideiso);
		outtextxy(172,145,ka);
	     }
	   else {alarm(450,100);alarm(400,100);alarm(375,70);}
		goto s22;
  case UP:
	 if(wideiso<95)
	       { wideiso=wideiso+4;
			bar(170,145,196,157);
		setcolor(2);
		sprintf(ka,"<%d>",wideiso);
		outtextxy(172,145,ka);
	       }
	   else {alarm(450,100);alarm(400,100);alarm(375,70);}
		goto s22;
  case DOWN:
	 if(wideiso>4)
	     {     wideiso=wideiso-4;
			bar(170,145,196,157);
		setcolor(2);
		sprintf(ka,"<%d>",wideiso);
		outtextxy(172,145,ka);
	      }
	   else {alarm(450,100);alarm(400,100);alarm(375,70);}
		goto s22;
		}
		 }
	  switch(key){
	  case ENTER:
		bit_size=imagesize(169,144,197,158);
			if((txt_map = malloc(bit_size))==(void*)0)
			{cprintf("KARAMBA !");exit(0);}
			getimage(169,144,197,158,txt_map);  // copy kadr
		Waiting();
		 Coder(p0,p4,2);
		Limonti();
			putimage(169,144,txt_map,0);
			rectangle(0,0,201,161);
		goto s25;
	   case 'p':
			      Printer();
			       settextstyle(2,0,4);
			       goto s22;
			   }
}
void Cartoon() //___________________________________________________
{
	    rectangle(101,80,200,160);
	switch(windows){

	case 0: windows_1=tax;
		Image();
		windows++;
		break;

	case 1: windows_2=windows_1;
		windows_1=tax;
		putimage(100,1,wind_1,0);
e6:		Image();

		setcolor(2);
		rectangle(1,1,100,80);
e2:		switch(getch()){
		case TAB:
		      if(reverse==0)
		       {
		       setcolor(3);
			rectangle(1,1,100,80);
			setcolor(2);
			rectangle(100,1,199,80);
			setcolor(3);
			tax=windows_2;
		       }
		       else
		       {rectangle(100,1,199,80);
			setcolor(2);
			rectangle(1,1,100,80);
			setcolor(3);
			tax=windows_1;
		       }
		      reverse=~reverse;
		      goto e2;
		case ENTER:  zoom=1;
			     Filer(); Maxim();
			     old=1;
				     max1=1;

			Size=imagesize(1,1,200,160);
			if((Map = malloc(Size))==(void*)0)
			  {cprintf("KARAMBA !");exit(0);}
			getimage(1,1,200,160,Map);  // copy kadr
			Waiting();
				Coder(p0,p4,0);
			     goto e6;
		case 'p':
			      Printer();
			       settextstyle(2,0,4);
			      goto e2;
		default:break;
			       }
		  windows++;
		break;

	case 2: windows_3=windows_2;
		windows_2=windows_1;
		windows_1=tax;
		putimage(1,80,wind_1,0);
		putimage(100,1,wind_2,0);
e7:		Image();

		setcolor(2);
		rectangle(1,1,100,80);
e3:             switch(getch()){
		case TAB:
		  switch(reverse){
		  case 0:
			setcolor(3);
			rectangle(1,1,100,80);
			setcolor(2);
			rectangle(100,1,199,80);
			setcolor(3);
			tax=windows_2;
			reverse++; break;
		  case 1:   rectangle(100,1,199,80);
			setcolor(2);
			rectangle(1,80,100,160);
			setcolor(3);
			tax=windows_3;
			reverse++; break;
		  case 2:   rectangle(1,80,100,160);
			setcolor(2);
			rectangle(1,1,100,80);
			setcolor(3);
			tax=windows_1;
			reverse=0; break;
				 }
		   goto e3;
		 case ENTER: zoom=1;
			     Filer(); Maxim();
			      old=1;
				     max1=1;
			Size=imagesize(1,1,200,160);
			if((Map = malloc(Size))==(void*)0)
			  {cprintf("KARAMBA !");exit(0);}
			getimage(1,1,200,160,Map);  // copy kadr
			Waiting();
				Coder(p0,p4,0);
			     goto e7;
		  case 'p':
			      Printer();
			       settextstyle(2,0,4);
			      goto e3;
		     }
		     windows++;
		     break;

	 case 3:windows_4=windows_3;
		windows_3=windows_2;
		windows_2=windows_1;
		windows_1=tax;
		putimage(100,80,wind_1,0);
		putimage(1,80,wind_2,0);
		putimage(100,1,wind_3,0);
e8:		Image();


		setcolor(2);
		rectangle(1,1,100,80);
e4:             switch(getch()){
		case TAB:
		  switch(reverse){
		  case 0:
			setcolor(3);
			rectangle(1,1,100,80);
			setcolor(2);
			rectangle(100,1,199,80);
			setcolor(3);
			tax=windows_2;
			reverse++; break;
		  case 1:   rectangle(100,1,199,80);
			setcolor(2);
			rectangle(1,80,100,160);
			setcolor(3);
			tax=windows_3;
			reverse++; break;
		  case 2:   rectangle(1,80,100,160);
			setcolor(2);
			rectangle(100,80,199,160);
			setcolor(3);
			tax=windows_4;
			reverse++; break;
		  case 3:   rectangle(100,80,199,160);
			setcolor(2);
			rectangle(1,1,100,80);
			setcolor(3);
			tax=windows_1;
			reverse=0; break;
			}
			 goto e4;

		 case ENTER: zoom=1;
			     Filer(); Maxim();
			      old=1;
				     max1=1;

		       Size=imagesize(1,1,200,160);
			if((Map = malloc(Size))==(void*)0)
			  {cprintf("KARAMBA !");exit(0);}
			getimage(1,1,200,160,Map);  // copy kadr
			Waiting();
				Coder(p0,p4,0);
			     goto e8;
		 case 'p':
			      Printer();
			       settextstyle(2,0,4);
			      goto e4;
		     }
                     windows++;
		     break;

	 case 4: windows_4=windows_3;
		 windows_3=windows_2;
		 windows_2=windows_1;
		 windows_1=tax;

		putimage(100,80,wind_2,0);
		putimage(1,80,wind_3,0);
		putimage(100,1,wind_4,0);
		 wind_2=wind_3;
		 wind_3=wind_4;

e9:		Image();

		setcolor(2);
		rectangle(1,1,100,80);
e5:             switch(getch()){
		case TAB:
		  switch(reverse){
		  case 0:
			setcolor(3);
			 rectangle(1,1,100,80);
			setcolor(2);
			rectangle(100,1,199,80);
			setcolor(3);
			tax=windows_2;
			reverse++; break;
		  case 1:   rectangle(100,1,199,80);
			setcolor(2);
			rectangle(1,80,100,160);
			setcolor(3);
			tax=windows_3;
			reverse++; break;
		  case 2:   rectangle(1,80,100,160);
			setcolor(2);
			rectangle(100,80,199,160);
			setcolor(3);
			tax=windows_4;
			reverse++; break;
		  case 3:   rectangle(100,80,199,160);
			setcolor(2);
			rectangle(1,1,100,80);
			setcolor(3);
			tax=windows_1;
			reverse=0; break;
			}
			 goto e5;

		 case ENTER: zoom=1;
			     Filer(); Maxim();
			     old=1;
				     max1=1;
		      Size=imagesize(1,1,200,160);
			if((Map = malloc(Size))==(void*)0)
			  {cprintf("KARAMBA !");exit(0);}
			getimage(1,1,200,160,Map);  // copy kadr
			Waiting();
				Coder(p0,p4,0);
			     goto e9;
		case 'p':
			      Printer();
			       settextstyle(2,0,4);
			      goto e5;
		     }
		     break;
			    }
       reverse=0;
}
void Image()  //________________________________________________
{
s14:	settextstyle(0,0,1);

	GRAFwindow();

s9:	if(zoom!=0)
	   {
//	   if(test!=0)
	 Prof();
	  if(code!=0){ code=0;setcolor(3);
	    goto s14;}
	  putimage(1,1,Map,0);  // restore Screen for further...

	   }
			else
	  {
	   key=getch();
	if(!key){
	 key=getch();
	 switch(key){
	 case F1:
	   code=1;p4=p1;
	    Coder(p0,p4,0);
	   setfillstyle(1,0);
		bar(204,1,318,160);
		bar(3,175,200,183);

		 goto s14;
	   case F2:
	   code=1;p0=p1;p4=p2;
	    Coder(p0,p4,0);
	   setfillstyle(1,0);
		bar(204,1,318,160);
		bar(3,175,200,183);
		   goto s14;
	   case F3:
	   code=1;p0=p2;p4=p3;
	    Coder(p0,p4,0);
	   setfillstyle(1,0);
		bar(204,1,318,160);
		bar(3,175,200,183);
	   goto s14;
	   case F4:
	   code=1;p0=p3;
	   Coder(p0,p4,0);
	   setfillstyle(1,0);
		bar(204,1,318,160);
		bar(3,175,200,183);
	    goto s14;
		    }
		 }
	   else{
	   switch(key){
	  case ENTER:     Size=imagesize(1,1,200,160);
			if((Map = malloc(Size))==(void*)0)
			  {cprintf("KARAMBA !");exit(0);}
			getimage(1,1,200,160,Map);  // copy kadr

		      zoom=1;  Waiting();
			Coder(p0,p4,0);
			goto s14;
	  case 'p':       Printer(); goto s9;
	  case 'n':   	    Coder(p0,p4,1); goto s14;
	  case 'w':
		   bit_size=imagesize(40,50,170,90);
			if((prn_map = malloc(bit_size))==(void*)0)
			  {cprintf("KARAMBA !");exit(0);}
			getimage(40,50,170,90,prn_map);  // copy kadr

	 rectangle(40,50,170,90);
	 setfillstyle(1,0);
	 bar(41,51,169,89);
	 settextstyle(DEFAULT_FONT,0,1);
		   if(max1==1)
		   {
		outtextxy(55,60,"Кадр уже ");
		 outtextxy(65,70," записан !");
		 alarm(350,250);alarm(450,250);alarm(550,250);
		 sleep(1);
		   }
		   else
		   {
	 outtextxy(55,60,"Запись ");
		 outtextxy(65,70," кадра...");
		 Filew();      max1=1;
		 alarm(350,250);alarm(450,250);alarm(550,250);
		   }
			putimage(40,50,prn_map,COPY_PUT);
			goto s9;

		      }
	  }
	 }
}
void Maxim()
{
	  max=0;
	  for (i=0;i<=6500;i++)        //   Поиск max
		 {  if(bit[i]>max)
		  { max=bit[i];min=i;
		  }
		 }
	  max=max*255/63;
	  if(max > GUMA) max=max+GUMA;
}
void Waiting()        // Вейточка
{
		 rectangle(35,50,170,90);
	 setfillstyle(1,0);
	 bar(36,51,169,89);
	 settextstyle(2,0,4);
		outtextxy(60,55,"Минуточку, ");
		 outtextxy(51,70,"формирование кадра ... ");
}
void Hard()
{
		b=0x20;
m3:	outportb(0x301,b | porto);
//	printf("\n     Выставили по Port 301H: %x",b | porto);
//	getch();
	if((inportb(0x300) & 0x80) !=0)
	      {	printf("\n  Сбpос неудачен !");
		getch();
		 goto m3;   }
//	getch();
	b=0x90;
	outportb(0x301,b | porto);
//	printf("\n     Выставили по Port 301H: %x",b | porto);
m2:		if((inportb(0x300) & 0x80)==0)
	 {
//	     printf("\n   Нет  готовности ! ");
		alarm(350,250);alarm(450,250);alarm(550,250);
	     goto m2;
	 }
//	printf("\n   I'm ready ! ");

	b=0x20;
m4:	outportb(0x301,b | porto);
//	printf("\n     Выставили по Port 301H: %x",b | porto);
//	getch();
	if((inportb(0x300) & 0x80) !=0)
		{		printf("\n  Сбpос неудачен !");
		getch(); goto m4; }

	for(i=0; i<8000; i++)
	{
		b=0x70;
		outportb(0x301,b | porto);
		     bit[i]=inportb(0x300);
		b=0x30;
		outportb(0x301,b | porto);
	}
//	printf("\n       Reading OK.");

	j=m=0; rev=1; k=0;

	for(i=0; i<8000; i++)
	{
	  switch(bit[i] & 0x40){
	  case 0x40:
			if(rev==1)
			{  m=rev=0;
			  j++; }
		break;

	  case 0x00:
			if(m<100)
			{ bit[k]=bit[i] & 0x3f; k++; m++; rev=1; }
		 break;
			       }
	}
	ssi=j-1;

	for(i=0;i< ((j-1)*100-3);i++)
	 bit[i+1]=((bit[i]+bit[i+3])/2);

	b=0x20;
m5:	outportb(0x301,b | porto);
//	printf("\n     Выставили по Port 301H: %x",b | porto);
//	if((inportb(0x300) & 0x80) !=0)
  //	      {	printf("\n  Сбpос неудачен !");
    //		getch();   goto m5; }

//	printf("\n                 Cтpочныx____________ : %d",ssi);
}
