
/*implementation of Binary Search Tree*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct bst
{
int data;
struct bast *left,*right;
}
node;

void insert(node *,node *);
void inorder(node *);
node *search(node *,int,node **);
void del(node *,int);

void main()
{
int choice;
char ans='N';
int key;
node *New,*root,*tmp,*parent;
node *get_node();
root=NULL;
clrscr();
printf("\n\t Program for Binary Search Tree");
do
{
printf("\n 1.Create\n 2.Search\n 3.Delete\n 4.Display");
printf("\n\n Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1: do
{
New=get_node();
printf("\n Enter the element");
scanf("%d",&New->data);
if(root==NULL)
root=New;
else
insert(root,New);
printf("\n Do u want to enter more elements(y/n)");
ans=getch();
}
while(ans=='Y');
break;
case 2: printf("\n Enter the Element which you want to search");
scanf("%d",&key);
tmp=search(root,key,&parent);
printf("\n Parent of node %d is %d",tmp->data,parent->data);
break;
case 3: printf("\n Enter the Element u wish to delete");
scanf("%d",&key);
del(root,key);
case 4: if(root==NULL)
printf("Tree is not Created");
else
{
printf("\n The tree is:");
inorder(root);
}
break;
}
}
while(choice!=5);
}

node *get_node()
{
node *temp;
temp=(node *)malloc(sizeof(node));
temp->left=NULL;
temp->right=NULL;
return temp;
}

void insert(node *root,node *New)
{
if(New->data<root->data)
{
if(root->left==NULL)
root->left=New;
else
insert(root->left,New);
}
if(New->data>root->data)
{
if(root->right==NULL)
root->right=New;
else
insert(root->right,New);
}
}

node *search(node *root,int key,node **parent)
{
node *temp;
temp=root;
while(temp!=NULL)
{
if(temp->data==key)
{
printf("\n The %d Element is present",temp->data);
return temp;
}
*parent=temp;
if(temp->data>key)
temp=temp->left;
else
temp=temp->right;
}
return NULL;
}

void del(node *root,int key)
{
node *temp,*parent,*temp_succ;
temp=search(root,key,&parent);

/*deleting a node with 2 child*/

if(temp->left=NULL&&temp->right!=NULL)
{
parent=temp;
temp_succ=temp->right;
while(temp_succ->left!=NULL)
{
parent=temp_succ;
temp_succ=temp_succ->left;
}
temp->data=temp_succ->data;
parent->left=NULL;
printf("Now Deleted it");
return;
}

/*deleted a node with one child left*/

if(temp->left!=NULL&&temp->right==NULL)
{
if(parent->left==temp)
parent->left=temp->left;
else
parent->right=temp->left;
temp=NULL;
free(temp);
printf("Now Deleted it");
return;
}

/*right child*/

if(temp->left==NULL&&temp->right!=NULL)
{
if(parent->left==temp)
parent->left=temp->right;
else
parent->right=temp->right;
temp=NULL;
free(temp);
printf("Now Deleted it");
return;
}

/*deleting node which having no child*/

if(temp->left==NULL&&temp->right==NULL)
{
if(parent->left==temp)
parent->left=NULL;
else
parent->right=NULL;
printf("Now Deleted it");
return;
}
}

void inorder(node *temp)
{
if(temp!=NULL)
{
inorder(temp->left);
printf("  %d",temp->data);
inorder(temp->right);
}
}


