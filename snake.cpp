
#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>

struct player
{
char name[20];
int score;
}user;

class box
{
public:
int x1,x2,y1,y2;
}s[1000],b,c;


void create1(box s[], box &b, box &c, int &no, int &score, int &count)
{      //If snake has eaten a blue block
	char m[10];
	int i;
	no++;
	if (score>=200)
	no++;
	score+=10;
	itoa(score,m,10);
	setfillstyle(SOLID_FILL,BLACK);
	bar(520,340,545,355);    //Erasing score
	setcolor(6);
	outtextxy(520,348,m);    //New score

	setfillstyle(SOLID_FILL,BLACK);
	bar(b.x1,b.y1,b.x2,b.y2);       //Erasing blue block
	setfillstyle(SOLID_FILL,RED);
	bar(s[0].x1,s[0].y1,s[0].x2,s[0].y2);

	A:      //If new location of blue block coincides with snake

	b.x1=18+(random(20)*22);
	b.y1=24+(random(19)*22);
	b.x2=b.x1+20;
	b.y2=b.y1+20;

	if (count%8==0)
	{c.x1=18+(random(20)*22);
	c.y1=24+(random(19)*22);
	c.x2=c.x1+20;
	c.y2=c.y1+20;}


	for (i=0;i<no;i++)
		if ((s[i].x1==b.x1&&s[i].y1==b.y1)||(b.x1==c.x1&&b.y1==c.y1)||(s[i].x1==c.x1&&s[i].y1==c.y1))
			goto A; //If new location of blue block coincides with snake

	setfillstyle(SOLID_FILL,BLUE);
	bar(b.x1,b.y1,b.x2,b.y2);   //New blue block

	if (count%8==0)        //If green block should appear
	{setfillstyle(SOLID_FILL,GREEN);
	bar(c.x1,c.y1,c.x2,c.y2);
	bar(530,135,590,150);}   //Creating timer

}

void doublecreate1(box s[], box &c, int &no, int &score)
{       //If snake has eaten green block.
	char m[10];
	no++;
	if (score>=200)
	no++;
	score+=50;
	itoa(score,m,10);
	setfillstyle(SOLID_FILL,BLACK);
	bar(520,340,545,355);  //Erase score
	setcolor(6);
	outtextxy(520,348,m);  //New score.

	setfillstyle(SOLID_FILL,BLACK);
	bar(c.x1,c.y1,c.x2,c.y2);   //Remove green block.
	bar(530,135,590,150);       //Remove timer
	setfillstyle(SOLID_FILL,RED);
	bar(s[0].x1,s[0].y1,s[0].x2,s[0].y2);
	c.x1=6000;
	setfillstyle(SOLID_FILL,GREEN);
	}

void triplecreate1(box &c, int &remove, int &flag) //Timer for green block
{
	if (flag==1)   //If green block is active
		{
		setfillstyle(SOLID_FILL,BLACK);
		bar(588-remove,137,588,148);
		remove+=3;
		if (remove==63)   //Time up.
		{
		setfillstyle(SOLID_FILL,BLACK);
		bar(c.x1,c.y1,c.x2,c.y2);  //Remove Green block
		bar(530,135,590,150);      //Remove Timer.
		remove=0;
		flag=0;        //Green block no longer active
		c.x1=6000;
		}}
}

void death1(int &score)   //If user has died.
{
	char m[10];
	itoa(score,m,10);
	setcolor(RED);
	line(16,464,620,464);    //Bottom Border
	line(16,22,620,22);      //Top Border
	line(620,22,620,464);    //Right Border
	line(16,22,16,464);      //Left Border
	line(502,22,502,464);    //Middle Border
	delay(1000);                       //Pause for effect
	cleardevice();    //Clears the graphic screen.
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	setcolor(WHITE);
	outtextxy(200,170,"YOU LOST");
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	setcolor(RED);
	outtextxy(215,235,"Your Score is ");
	outtextxy(345,235,m);
	fstream f1("High1.txt",ios::app);  //Adds score to high score.
	f1<<m<<endl;
	f1.close();
}

void recreate1(int &score,int &speed) //Delays the snake : stops it from
{                                  //moving at supersonic speed.
	delay(speed);              //Also redraws, gives extra time for flash
	char m[10];
	itoa(score,m,10);
	line(16,464,620,464);    //Bottom Border
	line(16,22,620,22);      //Top Border
	line(620,22,620,464);    //Right Border
	line(16,22,16,464);      //Left Border
	line(502,22,502,464);    //Middle Border
	setcolor(6);
	outtextxy(520,330,"Score");
	outtextxy(520,348,m);
	outtextxy(520,70,"Player ");
	setcolor(WHITE);

}

void create2(box s[], box &b, box &c, int &no, int &score, int &count)
{      //If snake has eaten a blue block
	char m[10];
	int i;
	no++;
	if (score>=200)
	no++;
	score+=10;
	itoa(score,m,10);
	setfillstyle(SOLID_FILL,BLACK);
	bar(520,340,545,355); //Erasing score
	setcolor(6);
	outtextxy(520,348,m); //New score

	setfillstyle(SOLID_FILL,BLACK);
	bar(b.x1,b.y1,b.x2,b.y2);     //Erasing blue block
	setfillstyle(SOLID_FILL,RED);
	bar(s[0].x1,s[0].y1,s[0].x2,s[0].y2);

	A:    //If new location of blue block coincides with snake

	b.x1=18+(random(20)*22);
	b.y1=24+(random(19)*22);
	b.x2=b.x1+20;
	b.y2=b.y1+20;

	if (count%8==0)
	{c.x1=18+(random(20)*22);
	c.y1=24+(random(19)*22);
	c.x2=c.x1+20;
	c.y2=c.y1+20;}


	for (i=0;i<no;i++)
		if ((s[i].x1==b.x1&&s[i].y1==b.y1)||(b.x1==c.x1&&b.y1==c.y1)||(s[i].x1==c.x1&&s[i].y1==c.y1))
			goto A;  //If new location of blue block coincides with snake

	setfillstyle(SOLID_FILL,BLUE);
	bar(b.x1,b.y1,b.x2,b.y2); //New blue block

	if (count%8==0)    //If green block should appear
	{setfillstyle(SOLID_FILL,GREEN);
	bar(c.x1,c.y1,c.x2,c.y2);
	bar(530,135,590,150);}  //Creating timer

}

void doublecreate2(box s[], box &c, int &no, int &score)
{          //If snake has eaten green block.
	char m[10];
	no++;
	if (score>=200)
	no++;
	score+=50;
	itoa(score,m,10);
	setfillstyle(SOLID_FILL,BLACK);
	bar(520,340,545,355); //Erase score
	setcolor(6);
	outtextxy(520,348,m); //New score.

	setfillstyle(SOLID_FILL,BLACK);
	bar(c.x1,c.y1,c.x2,c.y2); //Remove green block.
	bar(530,135,590,150);     //Remove timer
	setfillstyle(SOLID_FILL,RED);
	bar(s[0].x1,s[0].y1,s[0].x2,s[0].y2);
	c.x1=6000;
	setfillstyle(SOLID_FILL,GREEN);
	}

void triplecreate2(box &c, int &remove, int &flag, int &ate) //Timer for green block
{
	if (flag==1)  //If green block is active
		{
		setfillstyle(SOLID_FILL,BLACK);
		bar(588-remove,137,588,148);
		remove+=3;
		if (remove==63) //Time up.
		{setfillstyle(SOLID_FILL,BLACK);
		bar(c.x1,c.y1,c.x2,c.y2);  //Remove Green block
		bar(530,135,590,150);     //Remove Timer.
		remove=0;
		flag=0;        //Green block no longer active
		c.x1=6000; }
		setfillstyle(SOLID_FILL,8);
		if (ate==1)
		setfillstyle(SOLID_FILL,BLUE);
		}
}

void death2(int &score)  //If user has died.
{
	char m[10];
	itoa(score,m,10);
	setfillstyle(SOLID_FILL,RED);
	bar(0,0,620,15);
	bar(0,0,10,450);
	bar(0,450,620,470);
	bar(610,470,620,0);
	bar(506,0,516,450);
	delay(1000);     //Pause for effect
	cleardevice();     //Clears the graphic screen.
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	setcolor(WHITE);
	outtextxy(200,170,"YOU LOST");
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	setcolor(RED);
	outtextxy(215,235,"Your Score is ");
	outtextxy(345,235,m);
	fstream f2("High2.txt",ios::app); //Adds score to high score.
	f2<<m<<endl;
	f2.close();
}

void recreate2(int &score,int &speed)  //Delays the snake : stops it from
{                                      //moving at supersonic speed.
	delay(speed);              //Also redraws, gives extra time for flash
	char m[10];
	itoa(score,m,10);
	bar(0,0,620,15);
	bar(0,0,10,450);
	bar(0,450,620,470);
	bar(610,470,620,0);
	bar(506,0,516,450);
	setcolor(6);
	outtextxy(520,330,"Score");
	outtextxy(520,348,m);
	outtextxy(520,70,"Player Name");

}

union REGS in,out;

       int callmouse()
       {
	      in.x.ax=1;
	      int86(51,&in,&out);
	      return 1;
       }
       void mouseposi(int &xpos,int &ypos,int &click)
       {
	      in.x.ax=3;
	      int86(51,&in,&out);
	      click=out.x.bx;
	      xpos=out.x.cx;
	      ypos=out.x.dx;
	}
       int mousehide()
       {
	      in.x.ax=2;
	      int86(51,&in,&out);
	      return 1;
       }
      void setposi(int &xpos,int &ypos)
      {
	     in.x.ax=4;
	     in.x.cx=xpos;
	     in.x.dx=ypos;
	     int86(51,&in,&out);
      }
      void restrictmouseptr(int x1,int y1,int x2,int y2)
	  {
		 in.x.ax=7;
		 in.x.cx=x1;
		 in.x.dx=x2;
		 int86(51,&in,&out);
		 in.x.ax=8;
		 in.x.cx=y1;
		 in.x.dx=y2;
		 int86(51,&in,&out);
	  }

void main()
{

gotoxy(32,13);
cout<<"Enter your name";
gotoxy(32,14);
gets(user.name);
gotoxy(32,15);


/* request auto detection */
int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

randomize();             //To ensure random locations for blue,green blocks.

START:                  //In instructions, when someone clicks Main Menu,it
setfillstyle(SOLID_FILL,BLACK);                        //goes to START.
bar(0,0,700,700);                 //CLEARSCREEN
setcolor(WHITE);
setfillstyle(SOLID_FILL,8);
bar(0,0,620,15);
bar(0,0,10,450);                             //BORDERS
bar(0,450,620,470);
bar(610,470,620,0);

setfillstyle(SOLID_FILL,GREEN);
bar(225,190,385,215);                          //CAMPAIGN
setfillstyle(SOLID_FILL,9);
bar(225,240,385,265);                          //LEVELSELECT
setfillstyle(SOLID_FILL,RED);
bar(225,290,385,315);                          //INSTRUCTIONS
rectangle(225,190,385,215);
rectangle(225,240,385,265);                 //BORDERS FOR ABOVE BUTTONS
rectangle(225,290,385,315);

setcolor(BLACK);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);  //CAMPAIGN,LEVELSELECT,INSTRUCTIONS
outtextxy(270,300,"EXIT GAME");
outtextxy(260,200,"LEVEL SELECT");
outtextxy(257,250,"INSTRUCTIONS");

setcolor(WHITE);
settextstyle(3,HORIZ_DIR,6);
outtextxy(145,50,"SNAKE XENZIA");
settextstyle(0,HORIZ_DIR,0);         //RESET TEXT STYLE

int x,y,cl,choice=0,random1=300,random2=180,instrandom1=315,instrandom2=385;
/*
x - x coordinate of mouse
y - y coordinate of mouse
cl - left click or right click or both of mouse
random1 - initial x coordinate of mouse
random2 - initial y coordinate of mouse
instrandom1 - initial x coordinate of mouse in instructions page
instrandom2 - initial y coordinate of mouse in instructions page
*/
setposi(random1,random2);
callmouse();
restrictmouseptr(0,0,635,450);    //Prevents mouse from going across borders
setcolor(WHITE);
do
{
mouseposi(x,y,cl);

if (cl==1 && x>=225 && x<=385 && y>=190 && y<=215)       //LEVELSELECT
choice=1;

else if (cl==1 && x>=225 && x<=385 && y>=240 && y<=265)  //INSTRUCTIONS
choice=2;

else if (cl==1 && x>=225 && x<=385 && y>=290 && y<=315)  //EXIT GAME
exit(0);

else if (cl==2)               //RIGHT CLICK
exit(0);

}while(choice==0);

mousehide();                //Remove mouse

if (choice==2)             //If user has chosen INSTRUCTIONS
{
INST1:                     //When someone clicks BACK on instr-page2
choice=0;
setfillstyle(SOLID_FILL,BLACK);
bar(20,60,600,430);                    //CLEARSCREEN
setfillstyle(SOLID_FILL,9);
bar(480,400,580,425);                  //Creating NEXT Button
setfillstyle(SOLID_FILL,RED);
bar(265,400,365,425);                  //Creating MENU Button
setcolor(WHITE);
rectangle(480,400,580,425);            //NEXTBORDER
rectangle(265,400,365,425);            //MENUBORDER
setcolor(BLACK);
outtextxy(515,410,"NEXT");
outtextxy(280,410,"MAIN MENU");

setcolor(WHITE);
settextstyle(3,HORIZ_DIR,5);
outtextxy(170,50,"INSTRUCTIONS");      //TITLE
settextstyle(2,0,7);
setcolor(6);
outtextxy(165,130,"WELCOME TO SNAKE XENZIA!");
setcolor(7);
settextstyle(0,0,0);
outtextxy(50,180,"It's time to roll up your sleeves and settle down for a mind blowing");
outtextxy(35,200,"experience. Snake Xenzia is a game designed to provide you with a");
outtextxy(35,220,"pumped up, adrenaline filled, fun way to waste time!");

setfillstyle(SOLID_FILL,RED);
for (int i=0;i<4;i++)
	bar(260+(i*22),260,280+(i*22),280);
setcolor(5);
outtextxy(235,300,"This is your snake");
setcolor(GREEN);
outtextxy(50,335,"Your objective is to help your snake become as long as possible by");
outtextxy(35,355,"eating blocks and scoring points.");

setposi(instrandom1,instrandom2);
callmouse();
do
{
mouseposi(x,y,cl);

if (cl==1 && x>=480 && x<=580 && y>=400 && y<=425)    //Choosing NEXT
choice=2;

else if (cl==1 && x>=265 && x<=365 && y>=400 && y<=425)
choice=3;                                            //Choosing MAIN MENU

else if (cl==2)                                     //RIGHT CLICK
exit(0);

}while(choice==0);
setposi(instrandom1,instrandom2);    //Moves mouse to neutral location. If this is not there, entire instructions will be bypassed.
mousehide();

if (choice==3)        //If user chose MAIN MENU
{choice=0;
goto START;}


//END OF INSTRUCTION 1

INST2:
setfillstyle(SOLID_FILL,BLACK);
bar(20,20,600,379);
setfillstyle(SOLID_FILL,9);
bar(40,400,140,425);
setcolor(BLACK);
outtextxy(75,410,"BACK");		  //CREATING BACK BUTTON
setcolor(WHITE);
rectangle(40,400,140,425);
settextstyle(3,HORIZ_DIR,5);
outtextxy(130,50,"MOVING THE SNAKE");
settextstyle(0,0,0);
setcolor(7);
outtextxy(50,135,"The Snake will move on its own and hence it is your duty to change");
outtextxy(35,155,"its direction alone.");
outtextxy(50,190,"Use W,A,S,D to change the Snake's direction");
setcolor(6);
outtextxy(220,240,"W     -     Move Up");
outtextxy(220,265,"S     -     Move Down");
outtextxy(220,290,"D     -     Move Right");
outtextxy(220,315,"A     -     Move Left");
setcolor(GREEN);
outtextxy(50,365,"Keep in mind that the snake cannot make any 180 degree turns");

choice=0;
callmouse();
do
{
mouseposi(x,y,cl);

if (cl==1 && x>=40 && x<=140 && y>=400 && y<=425)  //Choosing BACK
choice=1;

else if (cl==1 && x>=480 && x<=580 && y>=400 && y<=425) //Choosing NEXT
choice=2;

else if (cl==1 && x>=265 && x<=365 && y>=400 && y<=425) //Choosing MAIN MENU
choice=3;

else if (cl==2)
exit(0);

}while(choice==0);
setposi(instrandom1,instrandom2);     //Moves mouse to neutral location. If this is not there, entire instructions will be bypassed.

mousehide();

if (choice==3)    //If user chose MAIN MENU
{choice=0;
goto START;}

else if (choice==1)  //If user chose BACK
{choice=0;
goto INST1;}
choice=0;

//END OF INSTRUCTION 2

INST3:
setfillstyle(SOLID_FILL,BLACK);
bar(20,20,600,375);
setfillstyle(SOLID_FILL,9);
bar(480,400,580,425);                  //Creating NEXT Button
setcolor(BLACK);
outtextxy(515,410,"NEXT");
setcolor(WHITE);
rectangle(480,400,580,425);            //NEXTBORDER
settextstyle(3,HORIZ_DIR,5);
outtextxy(160,45,"SCORING POINTS");
settextstyle(0,0,0);
setcolor(7);
outtextxy(50,115,"In order to score points, the Snake has to eat blocks. There");
outtextxy(35,135,"are two different types of blocks that the Snake can eat:-");
setcolor(6);
outtextxy(110,170,"BLUE -      -");
outtextxy(230,170,"This block appears every time the Snake");
outtextxy(230,190,"eats the previous blue block. It is worth");
outtextxy(230,210,"10 points each");
setfillstyle(SOLID_FILL,BLUE);
bar(170,165,190,185);
outtextxy(110,240,"GREEN -     -");
outtextxy(230,240,"This block appears every time the Snake");
outtextxy(230,260,"eats 8 blue blocks. It is worth 50 points");
outtextxy(230,280,"each. Once active, it is only available for");
outtextxy(230,300,"a limited time, so be fast!");
setfillstyle(SOLID_FILL,GREEN);
bar(170,235,190,255);
setcolor(5);
outtextxy(50,330,"Every time you eat a block, your Snake will become one block longer.");
outtextxy(35,350,"Once your score reaches 200, every time you eat a block, your Snake");
outtextxy(35,370,"will become two blocks longer.");

callmouse();
do
{
mouseposi(x,y,cl);

if (cl==1 && x>=40 && x<=140 && y>=400 && y<=425)    //Choosing BACK
choice=1;

else if (cl==1 && x>=480 && x<=580 && y>=400 && y<=425)  //Choosing NEXT
choice=2;

else if (cl==1 && x>=265 && x<=365 && y>=400 && y<=425) //Choosing MAIN MENU
choice=3;

else if (cl==2)      //RIGHT CLICK
exit(0);

}while(choice==0);
setposi(instrandom1,instrandom2);       //Moves mouse to neutral location. If this is not there, entire instructions will be bypassed.

mousehide();

if (choice==3)   //If user chose MAIN MENU
{choice=0;
goto START;}

else if (choice==1)      //If user chose BACK
{choice=0;
goto INST2;}
choice=0;

//END OF INSTRUCTION 3

INST4:
setfillstyle(SOLID_FILL,BLACK);
bar(20,20,600,380);
bar(480,400,580,425);
setcolor(WHITE);
settextstyle(3,HORIZ_DIR,5);
outtextxy(175,50,"WAYS TO DIE");
settextstyle(0,0,0);
setcolor(7);
outtextxy(50,125,"There are two types of borders - Solid Borders and Gaseous Borders");
outtextxy(35,145,"If the Snake hits a Solid Border, it will die. However, the Snake");
outtextxy(35,165,"has the ability to pass through Gaseous Borders and show up on the");
outtextxy(35,185,"the other side of the screen without dying.");
setfillstyle(SOLID_FILL,8);
bar(150,235,250,250);
setcolor(WHITE);
line(350,242,450,242);
outtextxy(153,265,"SOLID BORDER");
outtextxy(345,265,"GASEOUS BORDER");
setcolor(GREEN);
outtextxy(50,300,"The Snake will also die if any part of its body collides with any");
outtextxy(35,320,"other part of its body. Pressing the space bar while playing will");
outtextxy(35,340,"force exit the game. Pressing 'P' while playing will pause the");
outtextxy(35,360,"game.");

callmouse();
do
{
mouseposi(x,y,cl);

if (cl==1 && x>=40 && x<=140 && y>=400 && y<=425)   //Choosing BACK
choice=1;

else if (cl==1 && x>=265 && x<=365 && y>=400 && y<=425)  //Choosing MAIN MENU
choice=3;

else if (cl==2)
exit(0);

}while(choice==0);
setposi(instrandom1,instrandom2);        //Moves mouse to neutral location. If this is not there, entire instructions will be bypassed.

mousehide();

if (choice==3)       //If user chose MAIN MENU
{choice=0;
goto START;}

else if (choice==1)    //If user chose BACK
{choice=0;
goto INST3;}
choice=0;


//END OF INSTRUCTION 4

}

else if (choice==1);                      //If user chose LEVEL SELECT
	{
	setfillstyle(SOLID_FILL,BLACK);
	bar(0,0,700,700);              //clearscreen
	setfillstyle(SOLID_FILL,8);
	bar(0,0,620,15);
	bar(0,0,10,450);                    //borders
	bar(0,450,620,470);
	bar(610,470,620,0);

	setcolor(WHITE);
	settextstyle(3,HORIZ_DIR,6);
	outtextxy(145,50,"LEVEL SELECT");
	settextstyle(0,HORIZ_DIR,0);          //reset text style

	setfillstyle(SOLID_FILL,GREEN);
	bar(225,190,385,215);                 //LEVEL1 Bar
	bar(225,240,385,265);                 //LEVEL2 Bar
	setfillstyle(SOLID_FILL,RED);
	bar(225,290,385,315);                 //MAIN MENU Bar
	setcolor(WHITE);
	rectangle(225,190,385,215);
	rectangle(225,240,385,265);           //Borders for above bars
	rectangle(225,290,385,315);
	setcolor(BLACK);
	outtextxy(274,200,"LEVEL 1");
	outtextxy(274,250,"LEVEL 2");
	outtextxy(268,300,"MAIN MENU");
	}


choice=0;
setposi(random1,random2);

setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);

callmouse();

do
{
mouseposi(x,y,cl);
if (cl==1 && x>=225 && x<=385 && y>=190 && y<=215)     //Choosing LEVEL1
choice=1;

else if (cl==1 && x>=225 && x<=385 && y>=240 && y<=265) //Choosing LEVEL2
choice=2;

else if (cl==1 && x>=225 && x<=385 && y>=290 && y<=315) //Choosing MAIN MENU
choice=3;

else if (cl==2)
exit(0);

} while(choice==0);
setposi(random1,random2);           //Moves mouse to neutral location. If this is not there, entire instructions will be bypassed.

mousehide();

if (choice==3)       //If user chose MAIN MENU
{choice=0;
setfillstyle(SOLID_FILL,BLACK);
bar(0,0,700,700);
setcolor(WHITE);
goto START;
}

else if (choice==1)
{                           //If user chose LEVEL 1

BEGIN1:   //If user chooses PLAY AGAIN (Presses p or P) after dying in LEVEL1
setfillstyle(SOLID_FILL,BLACK);
bar(0,0,700,700);
char end;
int no=4,kill=0,speed=125,count=0,remove=0,flag=0;
user.score=0;
/*
end - Deciding whether user will exit the game, play again or go to main menu
      after dying in LEVEL1
no - Number of blocks for snake
score - score of the player
kill -  Checking if player has died or not.
	kill = 0 --> Player is alive.
	kill = 1 --> Player is dead --> Will invoke death function.
speed - delay count between movements of snake. The speed can be changed
	using 'm' and 'n' (CHEAT CODES)
count - To check if it is time for green block to appear.
	if (count%8)==0 --> Green block appears
remove - To create the erasing effect of timer for green block
flag - Checking if green block is active or not
       flag = 0 --> Not active
       flag = 1 -->Active
*/

setcolor(WHITE);

bar(0,0,700,700);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

line(16,464,620,464);    //Bottom Border
line(16,22,620,22);      //Top Border
line(620,22,620,464);    //Right Border
line(16,22,16,464);      //Left Border
line(502,22,502,464);    //Middle Border

setfillstyle(SOLID_FILL,RED);

setcolor(6);

outtextxy(520,70,"Player Name");
outtextxy(520,90,user.name);             //name of player
outtextxy(520,330,"Score");
outtextxy(520,348,"0");

for (int i=0;i<no;i++)               //Giving values to location of snake
	{
	s[i].x1=238+(i*22);
	s[i].x2=258+(i*22);
	s[i].y1=200;
	s[i].y2=220;
	}

for (i=0;i<no;i++)
	bar(s[i].x1,s[i].y1,s[i].x2,s[i].y2);  //Drawing the snake initially

A1: //If blue block coincides with snake, to get new locations for blue block.

b.x1=18+(random(20)*22);   //Giving initial location to blue block
b.y1=24+random(19)*22;
b.x2=b.x1+20;
b.y2=b.y1+20;

c.x1=6000;              //Giving initial junk value to green block
c.y1=6000;
c.x2=c.x1+20;
c.y2=c.x2+20;

for (i=0;i<no;i++)         //Checking if blue block coincides with snake
	if (s[i].x1==b.x1&&s[i].y1==b.y1)
		goto A1;

if (b.x1>=160 && b.x1<=380 && b.y1>=110 && b.y1<=150) //Checking if blue block
	goto A1;                               //coincides with "Press any
						    //key to start"
setfillstyle(SOLID_FILL,BLUE);
bar(b.x1,b.y1,b.x2,b.y2);       //Drawing the blue block

setfillstyle(SOLID_FILL,RED);

char prev='a',k;

/*
prev - previous press of player. Initially it is set to 'a' since the snake
       starts moving in 'd' direction.
k - current press of player (i.e) direction in which snake is currently
    moving in.
*/

setcolor(YELLOW);
outtextxy(180,130,"Press any key to start");
getch();
setfillstyle(SOLID_FILL,BLACK);
bar(180,130,380,150);  //Erasing "Press any key to start"
setcolor(WHITE);

while (k!=32)    //Checking if user pressed SPACE
{
	if (kbhit())  //If user inputed something
	k=getch();
	else      //If user didn't press anything, snake is supposed to
	{         //move in current direction. Even if user inputed something,
	if (k=='a')   //the code will enter this 'else' in the next second.
		{
		if (prev=='d')   //Snake can't make 180 degree turns.
			{k=prev;
			goto Skip1;}
		prev='a';

		setfillstyle(SOLID_FILL,BLACK);

		bar(s[no-1].x1,s[no-1].y1,s[no-1].x2,s[no-1].y2);  //Erases last block of snake

		for (i=no-1;i>0;i--)
			{s[i].x1=s[i-1].x1;   //Each block takes location of
			s[i].x2=s[i-1].x2;    //block next to it.
			s[i].y1=s[i-1].y1;
			s[i].y2=s[i-1].y2;}

		s[0].x1-=22;     //For first block
		s[0].x2-=22;

		if (s[0].x1<16)
			{s[0].x1=480;      //To go through left border.
			s[0].x2=500;}

		setfillstyle(SOLID_FILL,RED);    //Redrawing snake.
		for (i=0;i<no;i++)
			bar(s[i].x1,s[i].y1,s[i].x2,s[i].y2);

		for (i=1;i<no;i++)     //Checking if snake has collided with
			if (s[0].x1==s[i].x1 && s[0].y1==s[i].y1)   //itself
				kill=1;

			if (kill==1)
				{death1(user.score); //You dead bro.
				break;}

		if (s[0].x1>=b.x1 && s[0].x2<=b.x2 && s[0].y1>=b.y1 && s[0].y2<=b.y2)
			{                   //If snake has eaten blue block
			count++; //To keep track of when green block must appear
			create1(s,b,c,no,user.score,count);  //Creating new blue block.
			if (count%8==0)
			flag=1; //Green block is present.

			setcolor(BLUE);  //FLASHING BLUE BORDER
			line(16,464,620,464);    //Bottom Border
			line(16,22,620,22);      //Top Border
			line(620,22,620,464);    //Right Border
			line(16,22,16,464);      //Left Border
			line(502,22,502,464);    //Middle Border
			}

		if (s[0].x1>=c.x1 && s[0].x2<=c.x2 && s[0].y1>=c.y1 && s[0].y2<=c.y2)
			{          //If snake has eaten green block
			doublecreate1(s,c,no,user.score);
			flag=0;    //Green block is gone.
			remove=0;  //Timer for green block is unnecessary
			setcolor(GREEN);     //FLASHING GREEN BORDER.
			line(16,464,620,464);    //Bottom Border
			line(16,22,620,22);      //Top Border
			line(620,22,620,464);    //Right Border
			line(16,22,16,464);      //Left Border
			line(502,22,502,464);    //Middle Border

			}
		else        //If snake has not eaten green block.
			triplecreate1(c,remove,flag);

		recreate1(user.score,speed);

		}

	else if (k=='w')
		{
		if (prev=='s')    //Snake can't make 180 degree turns.
			{k=prev;
			goto Skip1;}
		prev='w';

		setfillstyle(SOLID_FILL,BLACK);

		bar(s[no-1].x1,s[no-1].y1,s[no-1].x2,s[no-1].y2);  //Erases last block of snake

		for (i=no-1;i>0;i--)
			{s[i].x1=s[i-1].x1;   //Each block takes location of
			s[i].x2=s[i-1].x2;    //block next to it
			s[i].y1=s[i-1].y1;
			s[i].y2=s[i-1].y2;}
		s[0].y1-=22;        //For first block
		s[0].y2-=22;

		if (s[0].y1<22)      //To go through top border.
			{s[0].y1=442;
			s[0].y2=462;}

		setfillstyle(SOLID_FILL,RED);  //Redrawing snake.
		for (i=0;i<no;i++)
			bar(s[i].x1,s[i].y1,s[i].x2,s[i].y2);

		for (i=1;i<no;i++)    //Checking if snake has collided with
			if (s[0].x1==s[i].x1 && s[0].y1==s[i].y1)   //itself
				kill=1;

			if (kill==1)
				{death1(user.score);  //You dead bro.
				break;}

		if (s[0].x1>=b.x1 && s[0].x2<=b.x2 && s[0].y1>=b.y1 && s[0].y2<=b.y2)
			{              //If snake has eaten blue block
			count++;  //To keep track of when green block must appear
			create1(s,b,c,no,user.score,count); //Creating new blue block
			if (count%8==0)
			flag=1;    //Green block is present

			setcolor(BLUE);  //FLASHING BLUE BORDER
			line(16,464,620,464);    //Bottom Border
			line(16,22,620,22);      //Top Border
			line(620,22,620,464);    //Right Border
			line(16,22,16,464);      //Left Border
			line(502,22,502,464);    //Middle Border
			}

		if (s[0].x1>=c.x1 && s[0].x2<=c.x2 && s[0].y1>=c.y1 && s[0].y2<=c.y2)
			{       //If snake has eaten green block
			doublecreate1(s,c,no,user.score);
			flag=0;   //Green block is gone.
			remove=0;  //Timer for green block is unnecessary
			setcolor(GREEN);  //FLASHING GREEN BORDER.
			line(16,464,620,464);    //Bottom Border
			line(16,22,620,22);      //Top Border
			line(620,22,620,464);    //Right Border
			line(16,22,16,464);      //Left Border
			line(502,22,502,464);    //Middle Border
			}
		else         //If snake has not eaten green block.
			triplecreate1(c,remove,flag);

		recreate1(user.score,speed);

		}

	else if (k=='d')
		{
		if (prev=='a')   //Snake can't make 180 degree turns.
			{k=prev;
			goto Skip1;}
		prev='d';
		setfillstyle(SOLID_FILL,BLACK);

		bar(s[no-1].x1,s[no-1].y1,s[no-1].x2,s[no-1].y2);  //Erases last block of snake

		for (i=no-1;i>0;i--)
			{s[i].x1=s[i-1].x1;   //Each block takes location of
			s[i].x2=s[i-1].x2;    //block next to it.
			s[i].y1=s[i-1].y1;
			s[i].y2=s[i-1].y2;}

		s[0].x1+=22;     //For first block
		s[0].x2+=22;

		if (s[0].x2>502)
			{s[0].x1=18;    //To go through right border.
			s[0].x2=38;}

		setfillstyle(SOLID_FILL,RED);   //Redrawing snake.
		for (i=0;i<no;i++)
			bar(s[i].x1,s[i].y1,s[i].x2,s[i].y2);

		for (i=1;i<no;i++)      //Checking if snake has collided with
			if (s[0].x1==s[i].x1 && s[0].y1==s[i].y1) //itself
				kill=1;

			if (kill==1)
				{death1(user.score);  //You dead bro.
				break;}

		if (s[0].x1>=b.x1 && s[0].x2<=b.x2 && s[0].y1>=b.y1 && s[0].y2<=b.y2)
			{            //If snake has eaten blue block
			count++; //To keep track of when green block must appear
			create1(s,b,c,no,user.score,count);//Creating new blue block
			if (count%8==0)
			flag=1;  //Green block is present.

			setcolor(BLUE);  //FLASHING BLUE BORDER
			line(16,464,620,464);    //Bottom Border
			line(16,22,620,22);      //Top Border
			line(620,22,620,464);    //Right Border
			line(16,22,16,464);      //Left Border
			line(502,22,502,464);    //Middle Border
			}

		if (s[0].x1>=c.x1 && s[0].x2<=c.x2 && s[0].y1>=c.y1 && s[0].y2<=c.y2)
			{     //If snake has eaten green block
			doublecreate1(s,c,no,user.score);
			flag=0;    //Green block is gone
			remove=0;     //Timer for green block is unnecessary
			setcolor(GREEN);          //FLASHING GREEN BORDER.
			line(16,464,620,464);    //Bottom Border
			line(16,22,620,22);      //Top Border
			line(620,22,620,464);    //Right Border
			line(16,22,16,464);      //Left Border
			line(502,22,502,464);    //Middle Border
			}
		else        //If snake has not eaten green block.
			triplecreate1(c,remove,flag);

		recreate1(user.score,speed);

		}

	else if (k=='s')
		{
		if (prev=='w')   //Snake can't make 180 degree turns.
			{k=prev;
			goto Skip1;}
		prev='s';
		setfillstyle(SOLID_FILL,BLACK);

		bar(s[no-1].x1,s[no-1].y1,s[no-1].x2,s[no-1].y2);  //Erases last block of snake

		for (i=no-1;i>0;i--)
			{s[i].x1=s[i-1].x1;  //Each block takes location of
			s[i].x2=s[i-1].x2;    //block next to it.
			s[i].y1=s[i-1].y1;
			s[i].y2=s[i-1].y2;}

		s[0].y1+=22;    //For first block
		s[0].y2+=22;

		if (s[0].y2>464)      //To go through bottom border.
			{s[0].y1=24;
			s[0].y2=44;}

		setfillstyle(SOLID_FILL,RED);   //Redrawing snake.
		for (i=0;i<no;i++)
			bar(s[i].x1,s[i].y1,s[i].x2,s[i].y2);

		for (i=1;i<no;i++)    //Checking if snake has collided with
			if (s[0].x1==s[i].x1 && s[0].y1==s[i].y1)  //itself
				kill=1;

			if (kill==1)
				{death1(user.score);  //You dead bro.
				break;}

		if (s[0].x1>=b.x1 && s[0].x2<=b.x2 && s[0].y1>=b.y1 && s[0].y2<=b.y2)
			{           //If snake has eaten blue block
			count++;    //To keep track of when green block must appear
			create1(s,b,c,no,user.score,count); //Creating a new blue block
			if (count%8==0)
			flag=1;    //Green block is present.

			setcolor(BLUE);   //FLASHING BLUE BORDER
			line(16,464,620,464);    //Bottom Border
			line(16,22,620,22);      //Top Border
			line(620,22,620,464);    //Right Border
			line(16,22,16,464);      //Left Border
			line(502,22,502,464);    //Middle Border
			}

		if (s[0].x1>=c.x1 && s[0].x2<=c.x2 && s[0].y1>=c.y1 && s[0].y2<=c.y2)
			{      //If snake has eaten green block
			doublecreate1(s,c,no,user.score);
			flag=0;    //Green block is gone.
			remove=0;   //Timer for green block is unnecessary
			setcolor(GREEN);     //FLASHING GREEN BORDER.
			line(16,464,620,464);    //Bottom Border
			line(16,22,620,22);      //Top Border
			line(620,22,620,464);    //Right Border
			line(16,22,16,464);      //Left Border
			line(502,22,502,464);    //Middle Border
			}
		else      //If snake has not eaten green block.
			triplecreate1(c,remove,flag);


		recreate1(user.score,speed);

		}
	else if (k=='m')   //Cheat code : Speed Up
		{speed+=100;
		k=prev;}
	else if (k=='n')      //Cheat code : Speed Down
		{speed-=50;
		k=prev;}
	else if (k=='p')
		{setcolor(YELLOW);
		outtextxy(520,200,"Game Paused");
		getch();
		setfillstyle(SOLID_FILL,BLACK);
		bar(520,200,620,210);
		k=prev;
		setcolor(WHITE);
		}
	else                //Ignoring invalid inputs.
	k=prev;
	Skip1:
	}
	}
setcolor(YELLOW);
settextstyle(3,HORIZ_DIR,1);
k='a';         //Getting ready for the user to Play Again
outtextxy(190,305,"Press Space Bar To Exit");
outtextxy(198,335,"Press P To Play Again");
outtextxy(170,365,"Press M to Go To Main Menu");
while (end!=32)
{end=getch();
if (end=='p'||end=='P') //If user chose PLAY AGAIN (Pressed p or P)
goto BEGIN1;
if (end=='m'||end=='M') //If user chose MAIN MENU (Pressed m or M)
{setfillstyle(SOLID_FILL,BLACK);
setcolor(WHITE);
bar(0,0,700,700);
choice=0;
goto START;}}

setfillstyle(SOLID_FILL,BLACK);
bar(0,0,700,700);
cout<<"LEVEL 1 HIGH SCORES"<<endl;
int high[100],track=0,hi,hj,htemp;
fstream g1("High1.txt",ios::in);
while (!g1.eof())
{g1>>high[track++];}
g1.close();

for (hi=0;hi<track;hi++)
	for (hj=0;hj<track-hi-1;hj++)
		if (high[hj]<high[hj+1])
			{
			htemp=high[hj];
			high[hj]=high[hj+1];
			high[hj+1]=htemp;
			}

for (hi=0;hi<10;hi++)
{cout<<high[hi]<<endl;
high[hi]=0;}
track=0;
cout<<endl<<"LEVEL 2 HIGH SCORES"<<endl;

fstream g2("High2.txt",ios::in);
while (!g2.eof())
{g2>>high[track++];}
g2.close();

for (hi=0;hi<track;hi++)
	for (hj=0;hj<track-hi-1;hj++)
		if (high[hj]<high[hj+1])
			{
			htemp=high[hj];
			high[hj]=high[hj+1];
			high[hj+1]=htemp;
			}

for (hi=0;hi<10;hi++)
cout<<high[hi]<<endl;

getch();
}
//If code reaches this line, program will end.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/*----------------------------------LEVEL2-------------------------------*/
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

else if (choice==2)
{

BEGIN2:    //If user chooses PLAY AGAIN (Presses p or P) after dying in LEVEL1
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
char end;
int no=4,kill=0,speed=125,count=0,remove=0,flag=0,ate=0;
user.score=0;
/*
end - Deciding whether user will exit the game, play again or go to main menu
      after dying in LEVEL1
no - Number of blocks for snake
score - score of the player
kill -  Checking if player has died or not.
	kill = 0 --> Player is alive.
	kill = 1 --> Player is dead --> Will invoke death function.
speed - delay count between movements of snake. The speed can be changed
	using 'm' and 'n' (CHEAT CODES)
count - To check if it is time for green block to appear.
	if (count%8)==0 --> Green block appears
remove - To create the erasing effect of timer for green block
flag - Checking if green block is active or not
       flag = 0 --> Not active
       flag = 1 -->Active
ate - Provides extra time for border flash when green block is active
*/

clrscr();

randomize();

/* request auto detection */
int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

setfillstyle(SOLID_FILL,8);
bar(0,0,620,15);
bar(0,0,10,450);           //BORDERS
bar(0,450,620,470);
bar(610,470,620,0);
bar(506,0,516,450);

setcolor(6);

outtextxy(520,70,"Player Name");
outtextxy(520,90,user.name);         //name of player
outtextxy(520,330,"Score");
outtextxy(520,348,"0");

A2:       //If blue block coincides with snake

b.x1=18+(random(20)*22);  //Giving initial location to blue block
b.y1=24+random(19)*22;
b.x2=b.x1+20;
b.y2=b.y1+20;

c.x1=6000;                //Giving initial junk value to green block
c.y1=6000;
c.x2=c.x1+20;
c.y2=c.x2+20;

for (int i=0;i<no;i++)        //Checking if blue block coincides with snake
	if (s[i].x1==b.x1&&s[i].y1==b.y1)
		goto A2;

if (b.x1>=160 && b.x1<=380 && b.y1>=110 && b.y1<=150) //Checking if blue block
	goto A2;                               //coincides with "Press any
						    //key to start"
setfillstyle(SOLID_FILL,BLUE);
bar(b.x1,b.y1,b.x2,b.y2);   //Drawing the blue block

setfillstyle(SOLID_FILL,RED);
char prev='a',k;
/*
prev - previous press of player. Initially it is set to 'a' since the snake
       starts moving in 'd' direction.
k - current press of player (i.e) direction in which snake is currently
    moving in.
*/
for (i=0;i<no;i++)
	{        //Giving values to initial location of snake.
	s[i].x1=238+(i*22);
	s[i].x2=258+(i*22);
	s[i].y1=200;
	s[i].y2=220;
	}

for (i=0;i<no;i++)           //Drawing the snake
	bar(s[i].x1,s[i].y1,s[i].x2,s[i].y2);

setcolor(YELLOW);
outtextxy(180,130,"Press any key to start");
getch();
setfillstyle(SOLID_FILL,BLACK);
bar(180,130,380,150);      //Erasing "Press any key to start"
setcolor(WHITE);

while (k!=32)       //Checking if user pressed SPACE
	{
	if (kbhit())  //If user inputed something
		k=getch();
	else         //If user didn't press anything, snake is supposed to
	{            //move in current direction. Even if user inputed something,
	if (k=='a')     //the code will enter this 'else' in the next second.
		{
		if (prev=='d')  //Snake can't make 180 degree turns.
			{k=prev;
			goto Skip2;}
		prev='a';

		setfillstyle(SOLID_FILL,BLACK);

		bar(s[no-1].x1,s[no-1].y1,s[no-1].x2,s[no-1].y2); //Erases last block of snake

		for (i=no-1;i>0;i--)
			{s[i].x1=s[i-1].x1;  //Each block takes location of
			s[i].x2=s[i-1].x2;   //block next to it.
			s[i].y1=s[i-1].y1;
			s[i].y2=s[i-1].y2;}

		s[0].x1-=22;    //For first block
		s[0].x2-=22;

		setfillstyle(SOLID_FILL,RED); //Redrawing snake.
		for (i=0;i<no;i++)
			bar(s[i].x1,s[i].y1,s[i].x2,s[i].y2);

		setfillstyle(SOLID_FILL,8); //If snake has collided with borders.
		if (s[0].x1<=0 || s[0].x2>=505 || s[0].y1<=15 || s[0].y2>=450)
			{death2(user.score);
			break;}

		for (i=1;i<no;i++)    //Checking if snake has collided with
			if (s[0].x1==s[i].x1 && s[0].y1==s[i].y1) //itself
				kill=1;

			if (kill==1)
				{death2(user.score); //You dead bro.
				break;}

		if (s[0].x1>=b.x1 && s[0].x2<=b.x2 && s[0].y1>=b.y1 && s[0].y2<=b.y2)
			{          //If snake has eaten blue block
			setfillstyle(SOLID_FILL,BLUE); //FLASHING BLUE BORDER
			bar(0,0,620,15);
			bar(0,0,10,450);
			bar(0,450,620,470);
			bar(610,470,620,0);
			bar(506,0,516,450);

			count++;  //To keep track of when green block must appear

			create2(s,b,c,no,user.score,count);

			if (count%8==0)
			flag=1; //Green block is present.
			ate=1;
			}

		if (s[0].x1>=c.x1 && s[0].x2<=c.x2 && s[0].y1>=c.y1 && s[0].y2<=c.y2)
			{      //If snake has eaten green block
			setfillstyle(SOLID_FILL,GREEN); //FLASHING GREEN BORDER
			bar(0,0,620,15);
			bar(0,0,10,450);
			bar(0,450,620,470);
			bar(610,470,620,0);
			bar(506,0,516,450);

			doublecreate2(s,c,no,user.score);

			flag=0; //Green block is gone
			remove=0;  //Timer for green block is unnecessary
			}
		else  //If snake has not eaten green block.
			{triplecreate2(c,remove,flag,ate);
			ate=0;}

		recreate2(user.score,speed);
		}

	else if (k=='w')
		{
		if (prev=='s')  //Snake can't make 180 degree turns.
			{k=prev;
			goto Skip2;}
		prev='w';
		setfillstyle(SOLID_FILL,BLACK);

		bar(s[no-1].x1,s[no-1].y1,s[no-1].x2,s[no-1].y2); //Erases last block of snake

		for (i=no-1;i>0;i--)
			{s[i].x1=s[i-1].x1;    //Each block takes location of
			s[i].x2=s[i-1].x2;     //block next to it
			s[i].y1=s[i-1].y1;
			s[i].y2=s[i-1].y2;}

		s[0].y1-=22;   //For first block
		s[0].y2-=22;

		setfillstyle(SOLID_FILL,RED); //Redrawing snake
		for (i=0;i<no;i++)
			bar(s[i].x1,s[i].y1,s[i].x2,s[i].y2);

		setfillstyle(SOLID_FILL,8); //If snake has collided with borders.
		if (s[0].x1<=0 || s[0].x2>=505 || s[0].y1<=15 || s[0].y2>=450)
			{death2(user.score);
			break;}

		for (i=1;i<no;i++)   //Checking if snake has collided with
			if (s[0].x1==s[i].x1 && s[0].y1==s[i].y1) //itself
				kill=1;

			if (kill==1)
				{death2(user.score); //You dead bro.
				break;}

		if (s[0].x1>=b.x1 && s[0].x2<=b.x2 && s[0].y1>=b.y1 && s[0].y2<=b.y2)
			{           //If snake has eaten blue block
			setfillstyle(SOLID_FILL,BLUE); //FLASHING BLUE BORDER
			bar(0,0,620,15);
			bar(0,0,10,450);
			bar(0,450,620,470);
			bar(610,470,620,0);
			bar(506,0,516,450);

			count++;  //To keep track of when green block must appear

			create2(s,b,c,no,user.score,count);

			if (count%8==0)
			flag=1; //Green block is present.
			ate=1;}

		if (s[0].x1>=c.x1 && s[0].x2<=c.x2 && s[0].y1>=c.y1 && s[0].y2<=c.y2)
			{     //If snake has eaten green block
			setfillstyle(SOLID_FILL,GREEN); //FLASHING GREEN BORDER
			bar(0,0,620,15);
			bar(0,0,10,450);
			bar(0,450,620,470);
			bar(610,470,620,0);
			bar(506,0,516,450);

			doublecreate2(s,c,no,user.score);
			flag=0;  //Green block is gone
			remove=0;} //Timer for green block is unnecessary
		else  //If snake has not eaten green block.
			{triplecreate2(c,remove,flag,ate);
			ate=0;}

		recreate2(user.score,speed);

		}

	else if (k=='d')
		{
		if (prev=='a') //Snake can't make 180 degree turns.
			{k=prev;
			goto Skip2;}
		prev='d';
		setfillstyle(SOLID_FILL,BLACK);

		bar(s[no-1].x1,s[no-1].y1,s[no-1].x2,s[no-1].y2); //Erases last block of snake

		for (i=no-1;i>0;i--)         //Each block takes location of
			{s[i].x1=s[i-1].x1;  //block next to it.
			s[i].x2=s[i-1].x2;
			s[i].y1=s[i-1].y1;
			s[i].y2=s[i-1].y2;}

		s[0].x1+=22;   //For first block
		s[0].x2+=22;

		setfillstyle(SOLID_FILL,RED);  //Redrawing snake.
		for (i=0;i<no;i++)
			bar(s[i].x1,s[i].y1,s[i].x2,s[i].y2);

		setfillstyle(SOLID_FILL,8); //If snake has collided with borders.
		if (s[0].x1<=0 || s[0].x2>=505 || s[0].y1<=15 || s[0].y2>=450)
			{death2(user.score);
			break;}

		for (i=1;i<no;i++)   //Checking if snake has collided with
			if (s[0].x1==s[i].x1 && s[0].y1==s[i].y1) //itself
				kill=1;

			if (kill==1)
				{death2(user.score);//You dead bro.
				break;}

		if (s[0].x1>=b.x1 && s[0].x2<=b.x2 && s[0].y1>=b.y1 && s[0].y2<=b.y2)
			{    //If snake has eaten blue block
			setfillstyle(SOLID_FILL,BLUE); //FLASHING BLUE BORDER
			bar(0,0,620,15);
			bar(0,0,10,450);
			bar(0,450,620,470);
			bar(610,470,620,0);
			bar(506,0,516,450);

			count++; //To keep track of when green block must appear

			create2(s,b,c,no,user.score,count);

			if (count%8==0)
			flag=1;  //Green block is present.
			ate=1;}

		if (s[0].x1>=c.x1 && s[0].x2<=c.x2 && s[0].y1>=c.y1 && s[0].y2<=c.y2)
			{     //If snake has eaten green block
			setfillstyle(SOLID_FILL,GREEN);//FLASHING GREEN BORDER
			bar(0,0,620,15);
			bar(0,0,10,450);
			bar(0,450,620,470);
			bar(610,470,620,0);
			bar(506,0,516,450);

			doublecreate2(s,c,no,user.score);

			flag=0;  //Green block is gone
			remove=0;//Timer for green block is unnecessary
			}

		else    //If snake has not eaten green block.
			{triplecreate2(c,remove,flag,ate);
			ate=0;}

		recreate2(user.score,speed);
		}

	else if (k=='s')
		{
		if (prev=='w') //Snake can't make 180 degree turns.
			{k=prev;
			goto Skip2;}
		prev='s';
		setfillstyle(SOLID_FILL,BLACK);

		bar(s[no-1].x1,s[no-1].y1,s[no-1].x2,s[no-1].y2); //Erases last block of snake

		for (i=no-1;i>0;i--)
			{s[i].x1=s[i-1].x1; //Each block takes location of
			s[i].x2=s[i-1].x2;  //block next to it
			s[i].y1=s[i-1].y1;
			s[i].y2=s[i-1].y2;}

		s[0].y1+=22;    //For first block
		s[0].y2+=22;

		setfillstyle(SOLID_FILL,RED); //Redrawing snake
		for (i=0;i<no;i++)
			bar(s[i].x1,s[i].y1,s[i].x2,s[i].y2);

		setfillstyle(SOLID_FILL,8); //If snake has collided with borders.
		if (s[0].x1<=0 || s[0].x2>=505 || s[0].y1<=15 || s[0].y2>=450)
			{death2(user.score);
			break;}

		for (i=1;i<no;i++)   //Checking if snake has collided with
			if (s[0].x1==s[i].x1 && s[0].y1==s[i].y1) //itself
				kill=1;

			if (kill==1)
				{death2(user.score); //You dead bro.
				break;}

		if (s[0].x1>=b.x1 && s[0].x2<=b.x2 && s[0].y1>=b.y1 && s[0].y2<=b.y2)
			{       //If snake has eaten blue block
			setfillstyle(SOLID_FILL,BLUE); //FLASHING BLUE BORDER
			bar(0,0,620,15);
			bar(0,0,10,450);
			bar(0,450,620,470);
			bar(610,470,620,0);
			bar(506,0,516,450);

			count++;  //To keep track of when green block must appear

			create2(s,b,c,no,user.score,count);

			if (count%8==0)
			flag=1; //Green block is present.
			ate=1;}

		if (s[0].x1>=c.x1 && s[0].x2<=c.x2 && s[0].y1>=c.y1 && s[0].y2<=c.y2)
			{        //If snake has eaten green block
			setfillstyle(SOLID_FILL,GREEN); //FLASHING GREEN BORDER
			bar(0,0,620,15);
			bar(0,0,10,450);
			bar(0,450,620,470);
			bar(610,470,620,0);
			bar(506,0,516,450);

			doublecreate2(s,c,no,user.score);
			flag=0; //Green block is gone
			remove=0;//Timer for green block is unnecessary
			}

		else   //If snake has not eaten green block.
			{triplecreate2(c,remove,flag,ate);
			ate=0;}

		recreate2(user.score,speed);
		}
	else if (k=='m')     //Cheat code : Speed Up
		{speed+=100;
		k=prev;}
	else if (k=='n')     //Cheat code : Speed Down
		{speed-=50;
		k=prev;}
	else if (k=='p')
		{setcolor(YELLOW);
		outtextxy(520,200,"Game Paused");
		getch();
		setfillstyle(SOLID_FILL,BLACK);
		bar(520,200,620,210);
		k=prev;
		setcolor(WHITE);
		}
	else        //Ignoring invalid inputs.
	k=prev;
	Skip2:
	}
	}
setcolor(YELLOW);
settextstyle(3,HORIZ_DIR,1);
k='a';
outtextxy(190,305,"Press Space Bar To Exit");
outtextxy(198,335,"Press P To Play Again");
outtextxy(170,365,"Press M to Go To Main Menu");
while (end!=32)
{end=getch();
if (end=='p'||end=='P')
goto BEGIN2;
if (end=='m'||end=='M')
{setfillstyle(SOLID_FILL,BLACK);
setcolor(WHITE);
bar(0,0,700,700);
choice=0;
goto START;}}

setfillstyle(SOLID_FILL,BLACK);
bar(0,0,700,700);
cout<<"LEVEL 1 HIGH SCORES"<<endl;
int high[100],track=0,hi,hj,htemp;
fstream g1("High1.txt",ios::in);
while (!g1.eof())
{g1>>high[track++];}
g1.close();

for (hi=0;hi<track;hi++)
	for (hj=0;hj<track-hi-1;hj++)
		if (high[hj]<high[hj+1])
			{
			htemp=high[hj];
			high[hj]=high[hj+1];
			high[hj+1]=htemp;
			}

for (hi=0;hi<10;hi++)
{cout<<high[hi]<<endl;
high[hi]=0;}
track=0;
cout<<endl<<"LEVEL 2 HIGH SCORES"<<endl;

fstream g2("High2.txt",ios::in);
while (!g2.eof())
{g2>>high[track++];}
g2.close();

for (hi=0;hi<track;hi++)
	for (hj=0;hj<track-hi-1;hj++)
		if (high[hj]<high[hj+1])
			{
			htemp=high[hj];
			high[hj]=high[hj+1];
			high[hj+1]=htemp;
			}

for (hi=0;hi<10;hi++)
cout<<high[hi]<<endl;

getch();
}
}
