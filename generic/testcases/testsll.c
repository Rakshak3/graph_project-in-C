#include<stdio.h>
#include<tm_sll.h>
#include<stdlib.h>
#include<string.h>

int main()
{
bool success;
int *x;
SinglyLinkedListIterator iterator;
int ch,num,index,t;
SinglyLinkedList *list1,*list2;
list1=createSinglyLinkedList(&success);
if(success==false)
{
printf("Unable To Create List\n");
return 0;
}
list2=createSinglyLinkedList(&success);
if(success==false)
{
destroySinglyLinkedList(list1);
printf("Unable to create list\n");
return 0;
}
while(1)
{
printf("1. Add in list 1\n");
printf("2. Add in list 2\n");
printf("3. Insert into list 1\n");
printf("4. Insert into list 2\n");
printf("5. Remove From list 1\n");
printf("6. Remove From list 2\n");
printf("7. Get from list 1\n");
printf("8. Get from list 2\n");
printf("9. Iteration of list 1\n");
printf("10. Iteration of list 2\n");
printf("11. Append two lists\n");
printf("12. Get Size of list 1\n");
printf("13. Get Size of list 2\n");
printf("14. Exit\n");
printf("15. clear\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter a number to add in list 1 : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
x=&num;
addToSinglyLinkedList(list1,x,&success);
if(success) printf("%d successfully added in list 1\n",*x);
else printf("Unable to add\n");
}
if(ch==2)
{
printf("Enter a number to add in list 2 : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
x=&num;
addToSinglyLinkedList(list2,x,&success);
if(success) printf("%d successfully added in list 2\n",*x);
else printf("Unable to add\n");
}
if(ch==3)
{
printf("Enter a number to insert in list 1 : ");
scanf("%d",&num);
fflush(stdin);
printf("Enter index : ");
scanf("%d",&index);
fflush(stdin);
InsertIntoSinglyLinkedList(list1,index,&num,&success);
if(success) printf("%d successfully inserted at %d index in list 1\n",num,index);
else printf("Unable to insert\n");
}
if(ch==4)
{
printf("Enter a number to insert in list 2 : ");
scanf("%d",&num);
fflush(stdin);
printf("Enter index : ");
scanf("%d",&index);
fflush(stdin);
InsertIntoSinglyLinkedList(list2,index,&num,&success);
if(success) printf("%d successfully inserted at %d index in list 2\n",num,index);
else printf("Unable to insert\n");
}
if(ch==5)
{
printf("Enter index to remove its data from list 1 : ");
scanf("%d",&index);
fflush(stdin);
x=removeFromSinglyLinkedList(list1,index,&success);
if(success) printf("%d successfully removed from list 1\n",*x);
else printf("Unable to remove\n");
}
if(ch==6)
{
printf("Enter index to remove its data from list 2 : ");
scanf("%d",&index);
fflush(stdin);
x=removeFromSinglyLinkedList(list2,index,&success);
if(success) printf("%d successfully removed from list 2\n",*x);
else printf("Unable to remove\n");
}
if(ch==7)
{
printf("Enter index to get its data from list 1 : ");
scanf("%d",&index);
fflush(stdin);
x=getFromSinglyLinkedList(list1,index,&success);
if(success) printf("%d\n",*x);
else printf("Unable to get data\n");
}
if(ch==8)
{
printf("Enter index to get its data from list 2 : ");
scanf("%d",&index);
fflush(stdin);
x=getFromSinglyLinkedList(list2,index,&success);
if(success) printf("%d\n",*x);
else printf("Unable to get data\n");
}
if(ch==9)
{
iterator=getSinglyLinkedListIterator(list1,&success);
if(success)
{
while(hasNextInSinglyLinkedList(&iterator))
{
x=(int *)getNextElementFromSinglyLinkedList(&iterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==10)
{
iterator=getSinglyLinkedListIterator(list2,&success);
if(success)
{
while(hasNextInSinglyLinkedList(&iterator))
{
x=(int *)getNextElementFromSinglyLinkedList(&iterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==11)
{

}
if(ch==12)
{
t=getSizeOfSinglyLinkedList(list1);
printf("Size of list 1 is %d\n",t);
}
if(ch==13)
{
t=getSizeOfSinglyLinkedList(list2);
printf("Size of list 2 is %d\n",t);
}
if(ch==14)
{
break;
}
if(ch==15)
{
clearSinglyLinkedList(list1);
}
}
free(x);
destroySinglyLinkedList(list1);
destroySinglyLinkedList(list2);
return 0;
}