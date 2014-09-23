/*
 * =====================================================================================
 *
 *       Filename:  math2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/30/2014 01:30:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  cheng, 623977469@qq.com
 *        Company:  LinuxGroup2013
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct com
{
	int a[100];
	int top;
}zhan;
typedef struct cam
{
	char s[100][100];
	int top;
}zh;
void push(zhan *s,int e)
{
	if(s->top == 99)
	  exit(1);
	s->top++;
	s->a[s->top]=e;
}

void pop(zhan *s,char *e)
{
	if(s->top ==-1)
	  exit(1);
	*e=s->a[s->top];
	s->top--;
}
void popint(zhan *s,int *e)
{
	if(s->top<=-1)
	  *e=0;
	else
	{
		*e=s->a[s->top];
		s->top--;
	}
}

void hou(char a[],char b[])
{
	int i=0;
	int j=0;
	char tmp;
	zhan c;
	(c.top)=-1;
	while(a[i]!='\0')
	{
		// num
		if(a[i]>=48&&a[i]<=57)
		{
			b[j++]=a[i];
		}
		//(
		if(a[i]=='(')
		{
			push(&c,a[i]);
		}
		//)
		if(a[i]==')')
		{
			while(c.a[c.top]!='(')
			{
				pop(&c,&tmp);
				b[j++]=' ';
				b[j++]=tmp;
			}
			pop(&c,&tmp);
		}
		if(a[i]=='+' || a[i]=='-')
		{
			while((c.top)!=-1 && c.a[c.top]!='(')
			{
				pop(&c,&tmp);
				b[j++]=' ';
				b[j++]=tmp;
			}
			b[j++]=' ';
			push(&c,a[i]);
		}
		if(a[i]=='*' || a[i]=='/')
		{
			while((c.top)!=-1 && (c.a[c.top]=='*'||c.a[c.top]=='/'))
			{
				pop(&c,&tmp);
				b[j++]=' ';
				b[j++]=tmp;
		    }
			b[j++]=' ';
			push(&c,a[i]);
		}
		i++;
	}
	while((c.top)!=-1)
	{
		pop(&c,&tmp);
		b[j++]=' ';
		b[j++]=tmp;
	}
	b[j]='\0';
}

int qiuzhi(char *b,int n)
{
	int i=0,j=0,tmp=0;
	int a[50];
	zhan c;
	c.top=-1;
	while(i<n)
	{
		if(b[i]>=48)
		{
			tmp=0;
			j=0;
			a[j]=b[i]-'0';
			i++;
			j++;
			while(b[i]!=' ')
			{
				a[j]=b[i]-'0';
				j++;
				i++;
			}
			j--;
		int w=j;
		for(;j>=0;j--)
		  tmp=tmp+a[w-j]*((int)pow(10,j));
		push(&c,tmp);
		}
		if(b[i]<48&&b[i]!=' ')
		{
			int p1,p2;
			popint(&c,&p2);
			popint(&c,&p1);
			if(b[i]=='*')
			  push(&c,p2*p1);
			if(b[i]=='/')
			  push(&c,p1/p2);
			if(b[i]=='+')
			  push(&c,p1+p2);
			if(b[i]=='-')
			  push(&c,p1-p2);
			i++;
		}
		if(b[i]==' ')
		  i++;
	}
	return(c.a[c.top]);


}
int main(int argc, char *argv[])
{

	char a[100],b[100];
	scanf("%s",a);
	hou(a,b);
	//printf("%s\n",b);
	int n=strlen(b);
	printf("=%d",qiuzhi(b,n));
	return EXIT_SUCCESS;
}

