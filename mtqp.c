#include <stdio.h>
#include <stdlib.h>
//定义空棋盘
int shuchu[8][8];
int qipan[8][8]={0};
int chak;
//定义坐标格式
typedef struct zuobiao
{
	int x;
	int y;
}zuobiao;
//定义栈
struct zhan
{
	zuobiao zb[100];
	int num[100];
	int top;
}s;

//进栈并且写入棋盘
void push(zuobiao e)
{
	if(s.top==99)
	{
		printf("进栈时栈满\n");
		exit(1);
	}
	s.top++;
	s.zb[s.top]=e;
	qipan[e.y][e.x]=1;
}

//出栈并且写入棋盘
void pop()
{
	if(s.top==1)
	{
		printf("出栈时栈空\n");
		printf("%d\n",chak);
		exit(1);
	}
	//s.num[s.top]=0;
	qipan[s.zb[s.top].y][s.zb[s.top].x]=0;
	s.num[s.top]=0;
	s.zb[s.top].x=0;
	s.zb[s.top].y=0;
	s.top--;
}

//判断坐标是否符合
int panduan(int x,int y)
{
	if(x>7 || x<0 || y>7 || y<0)
		return -1;
	if(qipan[y][x]==1)
		return -1;
	return 1;
}
int main()
{
	int i,j;
	zuobiao bg;
	printf("请输入初始坐标:");
	scanf("%d %d",&bg.x,&bg.y);
	bg.x=bg.x-1;
	bg.y=bg.y-1;
	if(bg.x>7 || bg.x<0 || bg.y>7 || bg.y<0 )
	{
		printf("初始坐标不符合规定\n");
		exit(1);
	}
	
	//初始坐标进栈
	push(bg);

	//运算主体	
	while(s.top!=64)
	{
	
		
		//数据整理
 	       for(i=64;i>=1;i--)
 	       {
 	               shuchu[s.zb[i].y][s.zb[i].x]=i;
 	       }

 	       //数据输出
 	       for(i=0;i<8;i++)
 	       {
 	               for(j=0;j<8;j++)
 	               {
 	                       printf("%5d ",shuchu[i][j]);
       		        }
        	        printf("\n");
       		}
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			shuchu[i][j]=0;	
		}
        	

		chak++;
		if(s.num[s.top]<1 && panduan(bg.x-2,bg.y-1)==1 )
		{
			s.num[s.top]=1;
			bg.x=bg.x-2;
			bg.y=bg.y-1;
			push(bg);
			continue;
		}
		else if(s.num[s.top]<2 && panduan(bg.x-1,bg.y-2)==1 )
                {
                        s.num[s.top]=2;
                        bg.x=bg.x-1;
                        bg.y=bg.y-2;
                        push(bg);
			continue;
                }
		else if(s.num[s.top]<3 && panduan(bg.x+2,bg.y-1)==1 )
                {
                        s.num[s.top]=3;
                        bg.x=bg.x+2;
                        bg.y=bg.y-1;
                        push(bg);
			continue;
                }
		else if(s.num[s.top]<4 && panduan(bg.x+1,bg.y-2)==1 )
                {
                        s.num[s.top]=4;
                        bg.x=bg.x+1;
                        bg.y=bg.y-2;
                        push(bg);
			continue;
                }
		else if(s.num[s.top]<5 && panduan(bg.x-2,bg.y+1)==1 )
                {
                        s.num[s.top]=5;
                        bg.x=bg.x-2;
                        bg.y=bg.y+1;
                        push(bg);
			continue;
                }
		else if(s.num[s.top]<6 && panduan(bg.x-1,bg.y+2)==1 )
                {
                        s.num[s.top]=6;
                        bg.x=bg.x-1;
                        bg.y=bg.y+2;
                        push(bg);
			continue;
                }
		else if(s.num[s.top]<7 && panduan(bg.x+2,bg.y+1)==1 )
                {
                        s.num[s.top]=7;
                        bg.x=bg.x+2;
                        bg.y=bg.y+1;
                        push(bg);
			continue;
                }
		else if(s.num[s.top]<8 && panduan(bg.x+1,bg.y+2)==1 )
                {
                        s.num[s.top]=8;
                        bg.x=bg.x+1;
                        bg.y=bg.y+2;
                        push(bg);
			continue;
                }
		else
		{ 
			pop();
			/*
			if(s.num[s.top]==1)
			{
				bg.x=bg.x+2;
                        	bg.y=bg.y+1;
			}
			if(s.num[s.top]==2)
			{
				bg.x=bg.x+1;
                        	bg.y=bg.y+2;
			}
			if(s.num[s.top]==3)
                        {
				bg.x=bg.x-2;
                        	bg.y=bg.y+1;
                        }
			if(s.num[s.top]==4)
                        {
				bg.x=bg.x-1;
                        	bg.y=bg.y+2;
                        }
			if(s.num[s.top]==5)
                        {
				 bg.x=bg.x+2;
                        	 bg.y=bg.y-1;
                        }
			if(s.num[s.top]==6)
                        {
				bg.x=bg.x+1;
         	                bg.y=bg.y-2;
	
                        }
			if(s.num[s.top]==7)
                        {
				bg.x=bg.x-2;
                        	bg.y=bg.y-1;
                        }
			if(s.num[s.top]==8)
                        {
				bg.x=bg.x-1;
                        	bg.y=bg.y-2;
                        }
			*/
			bg=s.zb[s.top];
		}
	}

	//数据整理
	for(i=64;i>=1;i--)
	{
		shuchu[s.zb[i].x][s.zb[i].y]=i;
	}
	
	//数据输出
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			printf("%d ",shuchu[i][j]);
		}
		printf("\n");
	}	

}
