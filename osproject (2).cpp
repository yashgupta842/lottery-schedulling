#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
class lottery
{public:
int process_id;
int burst_time;
int s;
int start_time, end_time;
int t[100];
void show()
{int j=0;
for(int i=start_time;i<end_time;i++)
{printf("%d ",t);
j++;
}
}
int search(int p)
{int j=0,c=0;
for(int i=start_time;i<end_time;i++)
{if(t[j]==p)
{return 1;
}
j++;
}return 0;
}
void insert()
{
int j=0;
for(int i=start_time;i<end_time;i++)
{t[j]=i;
j++;
}
}
};
 int main()
{int a;
int size;
printf("\t\t====================================================================================\n");
printf("\t\t\t\t\tWELCOME TO LOTTERY SCHEDULING\t\t\t\n");
printf("\t\t\t\t\tNAME:-YASH GUPTA\n");
printf("\t\t\t\t\tSECTION:-K1607\n");
printf("\t\t\t\t\tROLL-NO:-28\n");
printf("\t\t====================================================================================\n");
printf("ENTER THE NUMBER OF PROCESS YOU WANT TO EXECUTE:-\n");
scanf("%d",&a);
int tstart=0,tend;
class lottery q[a];
for(int i=0;i<a;i++)
{printf("ENTER THE PROCESS_ID FOR %d PROCESS  \n",i+1);
scanf("%d",&q[i].process_id);
printf("ENTER THE BURST_TIME FOR %d PROCESS  \n",i+1);
scanf("%d",&q[i].burst_time);
printf("ENTER THE ENDING TIME FOR %d PROCESS RANGE FROM %d to 100\n",i+1,tstart);
scanf("%d",&tend);
q[i].start_time=tstart;
q[i].end_time=tend;
size=tend-tstart;
q[i].s=size;
q[i].insert();
tstart=tend;
}
for(int i=0;i<a;i++)
{
printf("PROCESS_ID FOR %d PROCESS IS  %d\n",i+1,q[i].process_id);
printf("BURST_TIME FOR %d PROCESS IS  %d\n",i+1,q[i].burst_time);
printf("NO. OF TICKETS A %d PROCESS CAN HAVE %d \n",i+1,q[i].s);
printf("RANGE OF TICKETS FOR %d PROCESS IS\n",i+1);
q[i].show(); 
printf("\n");

}
int y,d,time_slice;

printf("ENTER THE TIME SLICE YOU WANT");
scanf("%d",&time_slice);

for(int k=0;k<15;k++)
{y=(rand()%25);
printf(" THE RANDOM NUMBERS FOR LOTTERY GENERATED ARE:-%d\n",y);
for(int i=0;i<a;i++)
{

d=q[i].search(y);
if(d==1)
{if(q[i].burst_time<=0)
{printf("PROCESS WITH PROCESS_ID %d  IS ALREADY EXECUTED SUCCESSFULLY\n",q[i].process_id);
}
else
{q[i].burst_time=q[i].burst_time-time_slice;
if(q[i].burst_time<0)
printf("REMAINING BURST_TIME FOR PROCESS WITH PROCESS_ID %d\n",q[i].process_id);
else
printf("REMAINING BURST_TIME FOR PROCESS WITH PROCESS_ID %d is %d\n",q[i].process_id,q[i].burst_time);
}

}
else
continue;
}
}
}
