#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
#include<ctype.h>

struct node
{
 struct node *llink,*rlink;
 int data,wt;
};

typedef struct
{
 int wt,v,via;
}tab;

void main()
{
 struct node * head;
 int i,n,s,t;char ch;
 struct node * insert(struct node *head,int);
 void insert1(struct node *head);
 struct node *find(struct node *head,int s);
 void path(struct node *,int,int);
 head=NULL;
 clrscr();
 do
 {
   printf("
1-Insertion");
   printf("
2-Path");
   printf("
3-Exit");
   printf("
Ur Choice:");
   scanf("%d",&s);
   switch(s)
   {
     case 1:	//Insertion
       printf("
No of CITIES.. :");
       scanf("%d",&n);
       for(i=1;i<=n;i++)
	 head=insert(head,i);
       for(i=1;i<=n;i++)
       {
	printf("
Do u create path from city-%d :",i);
	fflush(stdin);
	scanf("%c",&ch);
	if(tolower(ch)=='y')
	 insert1(find(head,i));
       }
     break;

     case 2:	//Path define
       printf("
From which city u want to travel :");
       scanf("%d",&t);
       if(t<=n)
	path(head,t,n);
       else
	printf("
Enter Correct data....");
     break;

     case 3: //exit
       exit(0);
   }
 }while(s<4||s>0);
 getch();
}

struct node *find(struct node *head,int s)
{
  struct node *t;
  t=head;
  while(t!=NULL)
  {
    if(t->data==s)
      return t;
    t=t->rlink;
  }
}

struct node * insert(struct node *head,int i)
{
 struct node *t,*temp;
 temp=head;
 t=(struct node*)malloc(sizeof(struct node));
 t->llink=NULL;
 t->rlink=NULL;
 t->data=i;
 t->wt=0;
 if(head==NULL)
  return t;
 while(temp->rlink!=NULL)
  temp=temp->rlink;
 temp->rlink=t;
 return head;
}

void insert1(struct node *head)
{
 struct node *t,*temp,*head1=NULL;
 char ch;
 do
 {
  temp=head1;
  t=(struct node*)malloc(sizeof(struct node));
  t->llink=NULL;
  t->rlink=NULL;
  printf("
Enter destination :");
  scanf("%d",&t->data);
  printf("
Enter Weight :");
  scanf("%d",&t->wt);
  if(head1==NULL)
  {
   head->llink=t;
   head1=t;
  }
  else
  {
   while(temp->rlink!=NULL)
    temp=temp->rlink;
   temp->rlink=t;
  }
  printf("
Do u continue y/n : ");
  fflush(stdin);
  scanf("%c",&ch);
 }while(tolower(ch)=='y');
}

void path(struct node *head,int s,int n)
{
 struct node *temp;
 tab *t;
 int d,k,cost=0,i=2,j=1,s1,f=0,c=0,via=0;
 t=(tab *)malloc(n*sizeof(tab));
 s1=s;
 for(i=1;i<=n;i++)
 {
  t[i].v=0;
  t[i].wt=9999;
  t[i].via=0;
 }
 while(j<n)
 {
  temp=find(head,s1);
  via=temp->data;
  temp=temp->llink;
  d=temp->data;
  while(temp!=NULL)
  {
   if((t[d].v)==0 && (t[d].wt > (cost+temp->wt)))
   {
     t[d].wt=cost+temp->wt;
     t[d].via=via;
   }
   temp=temp->rlink;
   d=temp->data;
  }
  cost=9999;
  for(i=1;i<=n;i++)
  {
    if(t[i].v==0 && i!=s)
    {
     if(t[i].wt<cost)
     {
      cost=t[i].wt;
      k=i;f=1;
     }
    }
  }
  if(f==1)
  {
   t[k].v=1;
   c=1;
   f=0;
  }
  j=j+1;
  s1=k;
 }
 printf("
Sourse  via    destination Distance");
 for(i=1;i<=n;i++)
 {
  if(t[i].v==1)
    if(t[i].via!=s)
      printf("
%d	%d   ->	  %d	  : %d",s,t[i].via,i,t[i].wt);
    else
      printf("
%d	--  ->	  %d	  :  %d",s,i,t[i].wt);
 }
 if(c==0)
   printf("
No way to travel from city - %d to other city..",s);
}
