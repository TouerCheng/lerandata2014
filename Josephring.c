#include <stdio.h>
#include <stdlib.h>
typedef	struct lianbiao
{
	int node;
	int mima;
	struct lianbiao *next;
}lb;
lb* input()
{
	int i;
	int m;
	printf("请输入个数:");
	scanf("%d",&m);
	lb *head,*p,*q;
	head=(lb *)malloc(sizeof(lb));
	p=head;
	printf("请输入第1个密码：");
	p->node=1;
	scanf("%d",&p->mima);
	for(i=2;i<=m;i++)
	{
	q=(lb *)malloc(sizeof(lb));
        printf("请输入第%d个密码：",i);
        q->node=i;
        scanf("%d",&q->mima);
	p->next=q;
	p=q;
	}
	p->next=head;
	return head;
}
void print(lb *head)
{
	lb *p;
	p=head;
	printf("初始化为：\n");
	while(1)
        {
                printf("%d  %d\n",p->node,p->mima);
                if(p->next==head)	break;
		p=p->next;
        }

}
void cat(lb *head,int n)
{
	lb *p;
	lb *pp;
	int i;
	while(1)
	{
		p=head;
        	pp=head->next;
		if(p==pp)
		{
			printf("编号：%d   密码：%d\n",p->node,p->mima);
			return;
		}
		if(n==1)
		{

			while(1)
			{
				p=p->next;
				pp=p->next;
				if(pp==head)
				{
					n=pp->mima;
					printf("编号：%d   密码：%d\n",pp->node,pp->mima);
					head=pp->next;
					p->next=head;
					break;
				}
			}
			continue;
		}
		for(i=2;i<n;i++)
		{
			p=p->next;
			pp=p->next;
		}

		printf("编号：%d   密码：%d\n",pp->node,pp->mima);
		if(pp==head)
		{
			head=pp->next;
		}
		n=pp->mima;
		p->next=pp->next;
	}
}
int main()
{
	int n;
	lb *head;
	head=input();
	print(head);
	printf("请输入初始数字:");
	scanf("%d",&n);
	cat(head,n);
	
}
	
