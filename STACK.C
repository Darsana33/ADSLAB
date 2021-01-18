#include<stdlib.h>
struct node
{
 int data;
 struct node *link;
};
struct node *TOP=NULL;
void push()
{
 struct node *ne=(struct node *)malloc(sizeof(struct node));
 if(ne==NULL)
 {
  printf("out of memmory");
  return;
 }
 printf("\n Enter the elements to push\n");
 scanf("%d",&ne->data);
 ne->link=TOP;
 TOP=ne;
}
void pop()
{
 struct node *ptr;
 if(TOP==NULL)
 {
  printf("stack is empty");
  return;
 }
 printf("poped the element %d\n",TOP->data);
 ptr=TOP;
 TOP=TOP->link;
 free(ptr);
}
void search()
{
 struct node *ptr;
 int x,pos=1;
 if(TOP==NULL)
 {
  printf("stack is empty");
  return;
 }
 ptr=TOP;
 printf("Enter the element to be searched\n");
 scanf("%d",&x);
 while(ptr!=NULL)
 {
  if(ptr->data==x)
  {
   printf("\n Element found at %d position from the top\n",pos);
   break;
  }
  ptr=ptr->link;
  pos++;
 }
 if(ptr==NULL)
   printf("Element not found");
}
void display()
{
 struct node *ptr=TOP;
 if(TOP==NULL)
 {
  printf("\n stack is empty");
  return;
 }
 ptr=TOP;
 printf("\n The elements are\n");
 while(ptr!=NULL)
 {
  printf("%d",ptr->data);
  ptr=ptr->link;
 }
}
void main()
{
 int ch=0;
 clrscr();
 while(ch!=5)
 {
  printf("\n Menu \n1.Push \n2.Pop \n3.Search \n4.Display \n5.Exit \n Enter your choice");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:push();
	  break;
   case 2:pop();
	  break;
   case 3:search();
	  break;
   case 4:display();
	  break;
   case 5:printf("Good bye");
	  break;
  }
 }
 getch();
}