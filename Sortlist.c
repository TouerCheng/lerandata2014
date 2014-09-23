#include <stdio.h>
#include <stdlib.h>
typedef struct lianbiao
{
	int a;
	struct lianbiao *next;
}lb;
lb* myinput()
{
	lb *head,*p,*pp;
	printf("请输入int型数据，以0结束.\n");
	head=p=(lb *)calloc(sizeof(lb),1);
	while(1)
	{
		pp=(lb *)calloc(sizeof(lb),1);
		scanf("%d",&pp->a);
		if(pp->a==0)
		{
			p->next=NULL;
			return head;
		}
		p->next=pp;
		p=pp;
	}
}
void myoutput(lb *head)
{
	head=head->next;
	while(1)
	{
		if(head!=NULL)
		{
			printf("%d ",head->a);
			head=head->next;
		}
		else  break;
	}
	printf("\n");
	return;
}
void chuli(lb *head)
{
	int num;
	lb *p,*pp,*tmp1,*tmp2;
	tmp=p=head->next;
	num=p->a;
	while(1)
	{
		p=p->next;
		if(p!=NULL)
		{
			if(p->a <= num)
			{
				pp=p;
				head->next=p;
				tmp=
			}
		}
	}
	
}
main()
{
	lb *head;
	head=myinput();
	myoutput(head);
}
