#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;

};
struct node *create_list(struct node *start);
void display (struct node *start);
void count(struct node *start);
void search (struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);
int main()

{
    struct node *start=NULL;
    int choice,data,item,pos;
    while(1)
{
printf("1.create list\n");
printf("2.display\n");
printf("3.count\n");
printf("4.search\n");
printf("5.add at beg or/at empty\n");
printf("6.add at end\n");
printf("7.add after node\n");
printf("8.add before node\n");
printf("9.add at position\n");
printf("10.delete\n");
printf("11.reverse\n");
printf("12.quit\n");
printf("enter your choice.\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
start =create_list(start);
break;
case 2:
display (start);
break;
case 3:
count (start);
break;
case 4:
printf("enter element to be searched: ");
scanf("%d",&data);
search(start,data);
break;
case 5:
printf("enter element to be inserted");
scanf("%d",&data);
start =addatbeg(start,data);
break;
case 6:
printf("enter element to be inserted");
scanf("%d",&data);
start= addatend(start,data);
break;
case 7:
printf("enter element to be inserted");
scanf("%d",&data);
printf("enter element after which to insert");
scanf("%d",&item);
start=addafter(start,data,item);
break;
case 8:
printf("enter element to be inserted");
scanf("%d",&data);
printf("enter element after which to insert");
scanf("%d",&item);
start=addbefore(start,data,item);
break;
case 9:
printf("enter element to be inserted");
scanf("%d",&data);
printf("enter element after which to insert");
scanf("%d",&pos);
start=addatpos(start,data,pos);
break;
case 10:
printf("enter element to be deleted");
scanf("%d",&data);
start =del(start,data);
break;
case 11:
start=reverse(start);
break;
case 12:
exit(1);
default:
printf("wrong choice \n");
}
}
}


void display(struct node *start)
{
struct node *p;
if(start==NULL)
{
    printf("list is empty");
    return;

}
p=start;
printf("list is \n");
while(p!=NULL)
{
    printf("%d \t",p->info);
    p=p->link;
}
printf("\n\n");
} // end of display


void count(struct node *start)
{
    struct node *p;
    int cnt=0;
    p=start;
    while(p!=NULL)
    {
        p=p->link;
        cnt++;

    }
    printf("number of element are %d\n",cnt);

} //end of count



void search(struct node *start, int item)
{
struct node *p=start;
int pos=1;
while(p!=NULL)
{
    if(p->info==item)
    {
        printf("item %d found at position %d \n",item,pos);
        return;
    }
 p=p->link;

 pos++;

}
printf("item %d not found in list\n",item);

} //end of search


struct node *addatbeg(struct node *start,int data)
{
struct node *temp;
temp=(struct node *)malloc (sizeof(struct node));
temp->info=data;
temp->link=start;
start=temp;
return start;

} // end of addatbeg

struct node *addatend (struct node *start,int data)
{
struct node *p,*temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->info=data;
p=start;
while(p->link!=NULL)
{
    p=p->link;
}
    p->link=temp;
    temp->link=NULL;
    return start;

} // end of addatend

struct node *addafter(struct node *start,int data,int item)
{
struct node *temp,*p;
p=start;
while(p!=NULL)
{
    if(p->info==item)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->info=data;
        temp->link=p->link;
        p->link=temp;
        return start;

    }
    p=p->link;

}
printf("%d not present in the list \n",item);
return start;

} // end of add_after



struct node *addbefore(struct node *start,int data ,int item)
{
struct node*temp,*p;
if(start==NULL)
{
    printf("list is empty \n");
    return start;
}
if(item==start->info)
{
    temp=(struct node* )malloc (sizeof(struct node));
    temp->info=data;
    temp->link=start;
    start =temp;
    return start;

}
p=start;
while(p->link!=NULL)
{
    if(p->link->info==item)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=data;
        temp->link=p->link;
        p->link=temp;
        return start;
    }
    p=p->link;

}
printf("%d not present in the list\n",item);
return start;

} //end of addbefore


struct node *addatpos(struct node *start,int data,int pos)
{
    struct node *temp,*p;
    int i;
    temp=(struct node *)malloc (sizeof(struct node));
    temp->info=data;
    if(pos==1)
    {
        temp->link=start;
        start=temp;
        return start;

    }
p=start;
for(i=1;i<pos-1 && p!=NULL;i++)
p=p->link;
if(p==NULL)
printf("there are less than %d elemnt \n",pos);
else 
{
    temp->link=p->link;
    p->link=temp;
}
return start;

} // end of addatpos

struct node *create_list(struct node *start)
{
int i,n,data;
printf("enter no.  of nodes");
scanf("%d",&n);
start =NULL;
if(n==0)
return start;
printf("enter the element to be inserted ");
scanf("%d",&data);
start=addatbeg(start,data);
for(i=2;i<=n;i++)
{

    printf("enter element to be inserted ");
    scanf("%d",&data);
    start=addatend(start,data);
}

return start;

} // end of create list

struct node *del(struct node *start,int data)
{
    struct node*temp,*p;
    if(start==NULL)
    {
        printf("list is empty \n");
       return start;

    }
if (start->info==data)  //deletion of first node
{
temp=start;
start=start->link;
free(temp);
return start;

}
p=start; //deletion in between or at the end
while(p->link!=NULL)
{
    if(p->link->info==data)
    {
        temp=p->link;
        p->link=temp->link;
        free(temp);
        return start;
    }
    p=p->link;
}
printf("element %d not found \n",data);
return start;

} // end of delete

struct node *reverse(struct node *start)
{
struct node *prev,*ptr,*next;
prev=NULL;
ptr=start;
while(ptr!=NULL)
{
    next = ptr->link;
    ptr->link=prev;
    prev=ptr;
    ptr=next;
}

start=prev;
return start;

} //end of reverse

