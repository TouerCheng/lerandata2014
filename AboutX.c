#include <stdio.h>
#include <stdlib.h>
typedef struct shuju
{
	int xishu;//多项式的系数
	int zhishu;//多项式的指数
	struct shuju *next;
}sj;

sj* myinput(void)
{
	sj *head,*p,*pp;
	printf("请输入多项式的系数和指数，用逗号隔开，输入（0，0）结束\n");
	head=p=(sj*)calloc(1,sizeof(sj));
	scanf("%d,%d",&p->xishu,&p->zhishu);
	while(1)
	{
		pp=(sj*)calloc(1,sizeof(sj));
		scanf("%d,%d",&pp->xishu,&pp->zhishu);
		if(pp->xishu==0)	break;
		p->next=pp;
		p=pp;
	}
	p->next=NULL;
	printf("输入完毕\n");
	return head;
}

sj* myadd(sj *a,sj *b)
{
	sj *c;
	sj *p,*pp;
	c=p=(sj *)calloc(1,sizeof(sj));
	if(a->zhishu < b->zhishu)
	{
		p->xishu=a->xishu;
		p->zhishu=a->zhishu;
		a=a->next;
	}
	else if(a->zhishu > b->zhishu)
        {
                p->xishu=b->xishu;
                p->zhishu=b->zhishu;
                b=b->next;
        }
	else if(a->zhishu == b->zhishu)
        {
                p->xishu=a->xishu+b->xishu;
                p->zhishu=a->zhishu;
                a=a->next;
		b=b->next;
        }
	if(a==NULL&&b==NULL)
	{
		p->next=NULL;
		return c;
	}
	if(a==NULL&&b!=NULL)
        {
		while(1)
		{
			if(b!=NULL)
			{
				pp=(sj *)calloc(1,sizeof(sj));
				pp->xishu=b->xishu;
				pp->zhishu=b->zhishu;
				p->next=pp;
				p=pp;
				b=b->next;
			}
			else
			{
				break;
			}
			
		}
                p->next=NULL;
                return c;
        }
	if(a!=NULL&&b==NULL)
        {
                while(1)
                {
                        if(a!=NULL)
                        {
                                pp=(sj *)calloc(1,sizeof(sj));
                                pp->xishu=a->xishu;
                                pp->zhishu=a->zhishu;
                                p->next=pp;
                                p=pp;
                                a=a->next;
                        }
                        else
                        {
                                break;
                        }
                        
                }
                p->next=NULL;
                return c;
        }
	while(1)
	{
		pp=(sj *)calloc(1,sizeof(sj));
		if(a->zhishu < b->zhishu)
		{
			pp->xishu=a->xishu;
			pp->zhishu=a->zhishu;
			a=a->next;
		}
		else if(a->zhishu > b->zhishu)
	        {
	                pp->xishu=b->xishu;
	                pp->zhishu=b->zhishu;
	                b=b->next;
	        }
		else if(a->zhishu == b->zhishu)
	        {
	                pp->xishu=a->xishu+b->xishu;
	                pp->zhishu=a->zhishu;
	                a=a->next;
			b=b->next;
	        }
		p->next=pp;
		p=pp;
		if(a==NULL&&b==NULL)
		{
			p->next=NULL;
			return c;
		}
		if(a==NULL&&b!=NULL)
	        {
			while(1)
			{
				if(b!=NULL)
				{
					pp=(sj *)calloc(1,sizeof(sj));
					pp->xishu=b->xishu;
					pp->zhishu=b->zhishu;
					p->next=pp;
					p=pp;
					b=b->next;
				}
				else
				{
					break;
				}
				
			}
	                p->next=NULL;
	                return c;
	        }
		if(a!=NULL&&b==NULL)
	        {
	                while(1)
	                {
	                        if(a!=NULL)
	                        {
	                                pp=(sj *)calloc(1,sizeof(sj));
	                                pp->xishu=a->xishu;
	                                pp->zhishu=a->zhishu;
	                                p->next=pp;
	                                p=pp;
	                                a=a->next;
	                        }
	                        else
	                        {
	                                break;
	                        }
	                        
	                }
	                p->next=NULL;
	                return c;
		}
		
	}
		
}

sj * myjian(sj *a,sj *b)
{
	sj *p=b;
	while(1)
	{
		if(p!=NULL)
		{
			p->xishu=0 - p->xishu;
			p=p->next;
		}
		else break;
		
	}
	return myadd(a,b);
}
void myprintf(sj *head)
{
	printf("p=");
	if(head->next!=NULL)
        {	
		if(head->xishu==0)
		{
			
		}
		else if(head->xishu==-1&&head->zhishu==0)
		{
			printf("-1+");
		}
		else if(head->zhishu==1&&head->xishu==1)
                {
                	printf("x+");
                }
            	else if(head->xishu==-1&&head->zhishu==1)
        	{
        	        printf("-x+");
          	}
            	else if(head->xishu==1)
       	        {
            	        printf("x^%d+",head->zhishu);

                }
               	else if(head->xishu==-1)
                {
                        printf("-x^%d+",head->zhishu);

                }
		else if(head->zhishu==1)
		{
			printf("%dx+",head->xishu);
		}
		else if(head->zhishu==0)
		{
			printf("%d+",head->xishu);
		}
		else	
       		printf("%dx^%d+",head->xishu,head->zhishu);
        }
      	else
   	{
		if(head->xishu==0)
                {
                        printf("0\n");
                }
		else if(head->xishu==-1&&head->zhishu==0)
                {
                        printf("-1\n");
                }

		else if(head->zhishu==1&&head->xishu==1)
                {
                        printf("x\n");
                }
                else if(head->xishu==-1&&head->zhishu==1)
                {
                        printf("-x\n");
                }
                else if(head->xishu==1)
                {
                        printf("x^%d\n",head->zhishu);

                }
                else if(head->xishu==-1)
                {
                        printf("-x^%d\n",head->zhishu);

                }
		else if(head->zhishu==1)
                {
                        printf("%dx\n",head->xishu);
                }
		 else if(head->zhishu==0)
                {
                        printf("%d\n",head->xishu);
                }


                else

       	 	printf("%dx^%d\n",head->xishu,head->zhishu);
                return;
        }
        head=head->next;

	while(1)
	{
		if(head->next!=NULL)
		{	
			if(head->xishu<0)
			{
				printf("\b");
			}
			if(head->xishu==0)
	                {
                 	       
        	        }
			else if(head->xishu==-1&&head->zhishu==0)
	                {
                	        printf("-1+");
        	        }

			else if(head->zhishu==1&&head->xishu==1)
			{
				printf("x+");
			}
			else if(head->xishu==-1&&head->zhishu==1)
			{
				printf("-x+");
			}
			else if(head->xishu==1)
			{
				 printf("x^%d+",head->zhishu);

			}
			else if(head->xishu==-1)
			{
                                 printf("-x^%d+",head->zhishu);

                        }
			else if(head->zhishu==1)
	                {
        	                printf("%dx+",head->xishu);
                	}
			else if(head->zhishu==0)
       		        {
                	        printf("%d+",head->xishu);
               		}

			else
			printf("%dx^%d+",head->xishu,head->zhishu);
		}
		else
		{
			if(head->xishu<0)
                        {
                                printf("\b");
                        }
			if(head->xishu==0)
	                {
                 	       printf("0\n");
        	        }
			else if(head->xishu==-1&&head->zhishu==0)
        	        {
	                        printf("-1\n");
                	}

			else if(head->zhishu==1&&head->xishu==1)
                        {
                                printf("x\n");
                        }
                        else if(head->xishu==-1&&head->zhishu==1)
                        {
                                printf("-x\n");
                        }
                        else if(head->xishu==1)
                        {
                                 printf("x^%d\n",head->zhishu);

                        }
                        else if(head->xishu==-1)
                        {
                                 printf("-x^%d\n",head->zhishu);

                        }
			else if(head->zhishu==1)
                	{
                        	printf("%dx\n",head->xishu);
                	}
			else if(head->zhishu==0)
	                {
                       		printf("%d\n",head->xishu);
        	        }

                        else

			printf("%dx^%d\n",head->xishu,head->zhishu);
			return;
		}
		head=head->next;
	}
}
sj *cheng(int a,int b,sj* c)
{
	sj *head,*p,*pp;
	head=p=(sj *)calloc(sizeof(sj),1);
	p->xishu=a*c->xishu;
	p->zhishu=b+c->zhishu;
	c=c->next;

	while(1)
	{
		if(c!=NULL)
		{
			pp=(sj *)calloc(1,sizeof(sj));
			
			pp->xishu=a*c->xishu;
			pp->zhishu=b+c->zhishu;
			
			p->next=pp;
			p=pp;
			c=c->next;
		}
		else  break;
	}
	p->next=NULL;
	return head;
}

sj *mycheng(sj *a,sj *b)
{
	sj *head,*tmp;
	head=cheng(a->xishu,a->zhishu,b);
	a=a->next;
	while(1)
	{
		if(a!=NULL)
		{
			tmp=cheng(a->xishu,a->zhishu,b);
			head=myadd(head,tmp);
			a=a->next;
		}
		else break;
	}
	return head;
}

main()
{
	sj *a,*b,*c,*d,*e;
	printf("请输入A式子,");
	a=myinput();
	printf("请输入B式子,");
	b=myinput();
	printf("A式子为:");
	myprintf(a);
	printf("B式子为:");
	myprintf(b);
	printf("A*B为：");
	e=mycheng(a,b);
	myprintf(e);
	c=myadd(a,b);
	printf("A+B为:");
	myprintf(c);
	printf("A-B为:");
	d=myjian(a,b);
	myprintf(d);
}




























