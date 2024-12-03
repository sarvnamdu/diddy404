*Binary Search

#include<stdio.h>
#include<conio.h>
void main(){
int n,i,search,f=0,low,high,mid,a[20];
clrscr();
printf("Enter the nvalue:");
scanf("%d",&n);
for(i=1;i<=n;i++){
printf("Enter the number in ascending order a[%d]=",i);
scanf("%d",&a[i]);
}
printf("Enter the search element:");
scanf("%d",&search);
low=1;
high=n;
while(low<=high){
mid=(low+high)/2;
if(search<a[mid]){
high=mid-1;
}
elseif(search>a[mid]){
low=mid+1;
}
else{
f=1;
printf("obtained in the position %d:",mid);
getch();
exit();
}
}
if(f==0)
printf("not present");
getch();
}