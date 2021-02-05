#include<stdlib.h>
struct node
{
 struct node *left;
 struct node *right;
 int data;
};
struct node *head=NULL;
struct node * GetNode();
void insertFirst();
void insertLast();
void insertPos();
void deleteFirst();
void deleteLast();
void deletePos();
void display();
void search();
void main()
{
 int ch=0; clrscr();
 while(ch!=9)
 {
  printf("\n Menu\n 1.insert first\n 2.insert last\n 3.insert position\n 4.delete first\n 5.delete last\n 6.delete position\n 7.display\n 8.search\n 9.exit");
  printf("\n Enter the choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:insertFirst();
	  break;
   case 2:insertLast();
	  break;
   case 3:insertPos();
	  break;
   case 4:deleteFirst();
	  break;
   case 5:deleteLast();
	  break;
   case 6:deletePos();
	  break;
   case 7:display();
	  break;
   case 8:search();
	  break;
  }}
  printf("good bye");
  getch();
}
void display()
{
struct node *ptr=head;
if(head==NULL)
{
 printf("\n list is empty");
 return;
}
printf("\n The elements are\n");
while(ptr!=NULL)
{
 printf("%d\t",ptr->data);
 ptr=ptr->right;
}
}
struct node * GetNode()
{
 int x;
 struct node *ne=(struct node *)malloc(sizeof(struct node));
 if(ne==NULL)
   printf("\n Insufficient memory");
 else
  {
   printf("Enter the values to insert:");
   scanf("%d",&x);
   ne->left=NULL;
   ne->right=NULL;
   ne->data=x;
  }
  return ne;
}
void insertFirst()
{
 struct node *ne;
 ne=GetNode();
 if(ne==NULL)
   return;
 if(head==NULL)
   head=ne;
 else
  {
   head->left=ne;
   ne->right=head;
   head=ne;
  }
 display();
}
void insertLast()
{
 struct node *ptr,*ne;
 ne=GetNode();
 if(ne==NULL)
   return;
 if(head==NULL)
   head=ne;
 else
  {
   ptr=head;
   while(ptr->right!=NULL)
   {
    ptr=ptr->right;
   }
   ptr->right=ne;
   ne->left=ptr;
  }
 display();
}
void insertPos()
{
 int value;
 struct node *ne,*ptr,*ptr1;
 ne=GetNode();
 if(ne==NULL)
   return;
 if(head==NULL)
  {
   printf("List is empty so the node is inserted as first node");
   head=ne;
   return;
  }
 printf("Enter the key value after which the node has to be inserted\n");
 scanf("%d",&value);
 ptr=head;
 while(ptr->right!=NULL&&ptr->data!=value)
 {
  ptr=ptr->right;
 }
 if(ptr->right==NULL)
 {
  ptr->right=ne;
  ne->left=ptr;
  printf("\n node is inserted at the last position");
 }
 else
 {
  ptr1=ptr->right;
  ne->right=ptr1;
  ne->left=ptr;
  ptr->right=ne;
  ptr1->left=ne;
 }
 printf("\n The element is inserted");
 display();
 }
void deleteLast()
{
 struct node *ptr,*prev;
 if(head==NULL)
 {
  printf("\n List is empty");
  return;
 }
 if(head->right==NULL)
 {
 free(head);
 head=NULL;
 return;
 }
 ptr=head->right;
 while(ptr->right!=NULL)
 {
  ptr=ptr->right;
 }
 prev=ptr->left;
 prev->right=NULL;
 free(ptr);
 display();
}
void deleteFirst()
{
 struct node *ptr;
 if(head==NULL)
 {
  printf("list is empty\n");
  return;
 }
 ptr=head;
 head=head->right;
 if(head!=NULL)
   head->left=NULL;
 free(ptr);
 display();
}
void deletePos()
{
 struct node *ptr,*prev,*next;
 int x;
 if(head==NULL)
 {
  printf("list is empty\n");
  return;
 }
 printf("Enter the element to delete:");
 scanf("%d",&x);
 if(head->data==x)
 {
  ptr=head;
  head=ptr->right;
  if(head!=NULL)
  {
   head->left=NULL;
  }
  free(ptr);
  return;
 }
 ptr=head;
 while(ptr->data!=x&&ptr->right!=NULL)
 {
  ptr=ptr->right;
 }
 if(ptr->data==x)
 {
  next=ptr->right;
  prev=ptr->left;
  prev->right=ptr->right;
  if(next!=NULL)
    next->left=ptr->left;
  free(ptr);
  return;
 }
 printf("\n Element not present in the list");
}
void search()
{
 struct node *ptr;
 int x;
 if(head==NULL)
 {
  printf("\n list is empty");
  return;
 }
 printf("\n Enter element to search");
 scanf("%d",&x);
 ptr=head;
 while(ptr!=NULL)
 {
  if(ptr->data==x)
  {
   printf("\n Element present in the list");
   break;
  }
  ptr=ptr->right;
 }
 if(ptr==NULL)
   printf("\n Element not in the list");
}