#include<stdio.h>
#include<tm_tm.h>
#include<stdlib.h>
int main()
{
Date *d;
d=nowTime();
printf("Day : %d\n",day(d));
printf("Month : %d\n",month(d));
printf("Year : %d\n",year(d));
printf("Hour : %d\n",hour(d));
printf("Minute : %d\n",minute(d));
printf("Second : %d\n",second(d));
printf("Day Of Week : %d\n",dayOfWeek(d));
printf("Day Of Year : %d\n",dayOfYear(d));
return 0;
}