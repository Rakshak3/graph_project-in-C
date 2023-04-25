#include<stdio.h>
#include<tm_dll.h>
#include<stdlib.h>
#include<string.h>

typedef struct Employee
{
int id;
void *ptr;
char name[35];
}employee;

int main()
{
DoublyLinkedListIterator iter;
int *r;
int id,ch,x,index;
char name[35],m;
void *ptr;
bool succ;
DoublyLinkedList *list1,*list2;
employee *t,*s,*n;
list1=createDoublyLinkedList(&succ);
if(succ==false)
{
printf("Not  enough memory\n");
return 0;
}
list2=createDoublyLinkedList(&succ);
if(succ==false)
{
destroyDoublyLinkedList(list1);
printf("Not enough memery\n");
return 0;
}
while(1)
{
printf("***************************************************\n");
printf("1. Add Employee in list 1\n");
printf("2. Add Employee in list 2\n");
printf("3. Remove Employee from list 1\n");
printf("4. Remove Employee from list 2\n");
printf("5. Insert Employee in list 1\n");
printf("6. Insert Employee in list 2\n");
printf("7. Get Size of List 1 of Employee\n");
printf("8. Get Size of List 2 of Employee\n");
printf("9. Get Employee's details from list 1\n");
printf("10. Get Employee's details from list 2\n");
printf("11. Append two lists\n");
printf("12. Traverse list 1\n");
printf("13. Traverse list 2\n");
printf("14.  Reverse Traverse list 1\n");
printf("15.  Reverse Traverse list 2\n");
printf("16. Exit\n");
printf("***************************************************\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
printf("**************************\n");
if(ch==1)
{
printf("Enter id : ");
scanf("%d",&id);
fflush(stdin);
printf("Enter name : ");
fgets(name,35,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
t=(employee *)malloc(sizeof(employee));
t->id=id;
strcpy(t->name,name);
addToDoublyLinkedList(list1,(void *)t,&succ);
if(succ) printf("Employee added\n");
else printf("Employee not added\n");
}

if(ch==2)
{
printf("Enter id : ");
scanf("%d",&id);
fflush(stdin);
printf("Enter name : ");
fgets(name,35,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
t=(employee *)malloc(sizeof(employee));
t->id=id;
strcpy(t->name,name);
addToDoublyLinkedList(list2,(void *)t,&succ);
if(succ) printf("Employee added\n");
else printf("Employee not added\n");
}

if(ch==3)
{
printf("Enter index : ");
scanf("%d",&index);
fflush(stdin);
ptr=removeFromDoublyLinkedList(list1,index,&succ);
s=(employee *)ptr;
if(succ)
{
printf("%s removed\n",s->name);
}
else printf("%s not removed\n",s->name);
}

if(ch==4)
{
printf("Enter index : ");
scanf("%d",&index);
fflush(stdin);
ptr=removeFromDoublyLinkedList(list2,index,&succ);
s=(employee *)ptr;
if(succ)
{
printf("%s removed\n",s->name);
}
else printf("%s not removed\n",s->name);
}

if(ch==5)
{
printf("Enter id : ");
scanf("%d",&id);
fflush(stdin);
printf("Enter name : ");
fgets(name,35,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Enter index : ");
scanf("%d",&index);
fflush(stdin);
t=(employee *)malloc(sizeof(employee));
t->id=id;
strcpy(t->name,name);
insertIntoDoublyLinkedList(list1,index,(void *)t,&succ);
if(succ) printf("Employee Inserted at %d\n",index);
else printf("Insertion failed\n");
}

if(ch==6)
{
printf("Enter id : ");
scanf("%d",&id);
fflush(stdin);
printf("Enter name : ");
fgets(name,35,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("Enter index : ");
scanf("%d",&index);
fflush(stdin);
t=(employee *)malloc(sizeof(employee));
t->id=id;
strcpy(t->name,name);
insertIntoDoublyLinkedList(list2,index,(void *)t,&succ);
if(succ) printf("Employee Inserted at %d\n",index);
else printf("Insertion failed\n");
}

if(ch==7)
{
x=getSizeOfDoublyLinkedList(list1);
printf("Size of List 1 is %d\n",x);
}

if(ch==8)
{
x=getSizeOfDoublyLinkedList(list2);
printf("Size of List 2 is %d\n",x);
}

if(ch==9)
{
printf("Enter index : ");
scanf("%d",&index);
fflush(stdin);
ptr=getFromDoublyLinkedList(list1,index,&succ);
s=(employee *)ptr;
if(succ) printf("ID : %d , Name : %s\n",s->id,s->name);
else printf("Failed\n");
}

if(ch==10)
{
printf("Enter index : ");
scanf("%d",&index);
fflush(stdin);
ptr=getFromDoublyLinkedList(list2,index,&succ);
s=(employee *)ptr;
if(succ) printf("ID : %d , Name : %s\n",s->id,s->name);
else printf("Failed\n");
}

if(ch==11)
{
appendToDoublyLinkedList(list1,list2,&succ);
if(succ)
{
iter=getDoublyLinkedList(list1,&succ);
if(succ)
{
while(hasNextInDoublyLinkedList(&iter));
{
r=(void *)getNextElementFromDoublyLinkedList(&iter,&succ);
s=(employee *)r;
printf("ID : %d , Name : %s ",s->id,s->name);
}
}
}
}
if(ch==12)
{
iter=getDoublyLinkedList(list1,&succ);
if(succ)
{
while(hasNextInDoublyLinkedList(&iter))
{
r=(void *)getNextElementFromDoublyLinkedList(&iter,&succ);
s=(employee *)r;
printf("ID : %d , ",s->id);
printf("Name : %s\n",s->name);
}
}else printf("none\n");
}
if(ch==13)
{
iter=getDoublyLinkedList(list2,&succ);
if(succ)
{
while(hasNextInDoublyLinkedList(&iter))
{
r=(void *)getNextElementFromDoublyLinkedList(&iter,&succ);
s=(employee *)r;
printf("ID : %d , ",s->id);
printf("Name : %s\n",s->name);
}
}else printf("none\n");
}
if(ch==14)
{
iter=getRevDoublyLinkedList(list1,&succ);
if(succ)
{
while(hasPreviousInDoublyLinkedList(&iter))
{
r=(void *)getPreviousElementFromDoublyLinkedList(&iter,&succ);
s=(employee *)r;
printf("ID : %d ,",s->id);
printf("Name : %s\n",s->name);
} 
}else printf("none\n");
}
if(ch==15)
{
iter=getRevDoublyLinkedList(list2,&succ);
if(succ)
{
while(hasPreviousInDoublyLinkedList(&iter))
{
r=(void *)getPreviousElementFromDoublyLinkedList(&iter,&succ);
s=(employee *)r;
printf("ID : %d ,",s->id);
printf("Name : %s\n",s->name);
} 
}else printf("none\n");
}
if(ch==16) break;
}
destroyDoublyLinkedList(list1);
destroyDoublyLinkedList(list2);
return 0;
}