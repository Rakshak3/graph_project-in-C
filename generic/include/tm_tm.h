#ifndef __TM_TM__H
#define __TM_TM__H123
#include<tm_common.h>
typedef struct __date
{
int day,month,year,hour,minute,second,dayOfWeek,dayOfYear;
}Date;

Date *nowTime();
Date *addDays(Date *d,int e);
Date *addMonth(Date *d,int e);
Date *addYear(Date *d,int e);
int day(Date *d);
int month(Date *d);
int year(Date *d);
int hour(Date *d);
int minute(Date *d);
int second(Date *d);
int dayOfWeek(Date *d);
int dayOfYear(Date *d);

#endif