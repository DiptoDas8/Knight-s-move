
# include "iGraphics.h"
char ch,str[5];
int px,py,count,x,y,xx,yy,mode,ind,len=0;
int pos_y[]={2,1,0,1,3,4,2,0,1,3,4,3,1,0,2,4,3,1,0,2,4,3,4,2,0};
int pos_x[]={2,4,2,0,1,3,4,3,1,0,2,4,3,1,0,1,3,2,4,3,4,2,0,1,0};
void knight_pos_change(void)
{
	
		if(y>yy)
			y=y-1;
		else if(y<yy)
			y=y+1;
		else if(x>xx)
			x=x-1;
		else if(x<xx)
			x=x+1;
}
void chess_draw()
{
	int i,j,inx,iny=10,r=30,g=144,b=255;
	for(i=0;i<5;i++)
	{
		inx=10;
		for(j=0;j<5;j++)
		{
	
			if(b==255)
			{
				r=0;
				g=0;
				b=0;
			}
			else
			{
				r=30;
				g=144;
				b=255;
			}
			iSetColor(r,g,b);
			iFilledRectangle(inx,iny,64,64);
			inx+=64;
		}
		iny+=64;
	}
}

void iDraw()
{
	
	iClear();
	iSetColor(255,215,0);
	iFilledRectangle(0,0,550,500);
	chess_draw();
	iShowBMP(x,y,"knight.bmp");
	iSetColor(0,0,255);
	iText(50,470,"Dipto Das, Student ID: S201205080",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(10,410,"Press 'm' to Move the Knight,'r' to restart,'i' to Input Index:");
	iText(50,340,"Press 'End' to Exit.");
	iSetColor(255,255,255);
	iFilledRectangle(50,360,100,25);
	xx=pos_x[count]*64+10;
	yy=pos_y[count]*64+10;
	if(mode==1)
	{
		iSetColor(0,55,0);
		iText(70,365,str);
		
	}

	}
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	/*if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//printf("%d %d\n",mx,my);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}*/
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/

void iKeyboard(unsigned char key)
{
	if(key == 'r')
	{
	
		px=py=0;
		x=pos_x[px]*64+10;
		y=pos_y[py]*64+10;
		count=0;

	}
	if(key=='m')
	{
		if(x==xx)
		{
			count++;
			if(count>24)
			{
				count=px=py=0;
				x=pos_x[px]*64+10;
				y=pos_y[py]*64+10;
			}
		}
		
	}
	if(key=='\r')
	{
		int i;
		for(i=0;i<len;i++)
			str[i]=0;
		mode=0;
		px=py=count=ind;
		x=pos_x[px]*64+10;
		y=pos_y[py]*64+10;
		len=0;
		
		ind=0;
	}
	if(mode==1)
	{
		
		str[len++]=key;
		ind=ind*10+key-'0';
	}
	
	if(key=='i')
	{
		mode=1;
		
	}
	
	

	
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	
	
}

int main()
{
	
	iSetTimer(5,knight_pos_change);
	count=0;
	mode=0;
	px=py=0;
	x=pos_x[px]*64+10;
	y=pos_y[py]*64+10;
	iInitialize(550,500, "Knight's Tour");
	return 0;
}	