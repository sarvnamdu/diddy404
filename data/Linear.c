*Linear Search*

#include<stdio.h>
#include<conio.h>
void main()
{
int arr[20];
int i,size,sech;
printf("\n\t-- Linear Search --\n\n");
printf("Enter total no. of elements : ");
scanf("%d",&size);
for(i=0; i<size; i++)
{
printf("Enter %d element : ",i+1);
scanf("%d",&arr[i]);}
printf("Enter the element to be searched:");
scanf("%d",&sech);
for(i=0; i<size; i++)
{
if(sech==arr[i])
{
printf("Element exits in the list at position : %d",i+1);
break;
}
}getch();
}