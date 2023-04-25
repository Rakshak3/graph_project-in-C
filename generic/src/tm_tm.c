#ifndef __TM_TM__C
#define __TM_TM__C 124
#include<tm_tm.h>
#include<time.h>
#include<stdlib.h>
Date *nowTime()
{
time_t now;
Date *d;
struct tm *myTime;
time(&now);
myTime=localtime(&now);
d=(Date *)malloc(sizeof(Date));
d->day=myTime->tm_mday;
d->month=myTime->tm_mon+1;
d->year=myTime->tm_year+1900;
d->hour=myTime->tm_hour;
d->minute=myTime->tm_min;
d->second=myTime->tm_sec;
d->dayOfWeek=myTime->tm_wday+1;
d->dayOfYear=myTime->tm_yday+1;
return d;
}

Date *addDays(Date *d,int e)
{

}

Date *addMonth(Date *d,int e)
{

}

Date *addYear(Date *d,int e)
{

}

int day(Date *d)
{
return d->day;
}
int month(Date *d)
{
return d->month;
}
int year(Date *d)
{
return d->year;
}
int hour(Date *d)
{
return d->hour;
}
int minute(Date *d)
{
return d->minute;
}
int second(Date *d)
{
return d->second;
}
int dayOfWeek(Date *d)
{
return d->dayOfWeek;
}
int dayOfYear(Date *d)
{
return d->dayOfYear;
}

#endif