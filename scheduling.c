#include<stdio.h>
#include<stdlib.h>

typedef struct process{
   char name[5];
   int burstTime;
   int arrivalTime;
   int priority;
   int waitingTime,turnAround,flag;

}processes;

int accept(processes P[]){
int i,n;
printf("\n Enter total no. of processes : ");
   scanf("%d",&n);
   for(i=0;i<n;i++){
       printf("\n PROCESS [%d]",i+1);
       printf(" Enter process name : ");
       scanf("%s",&P[i].name);
       printf(" Enter burst time : ");
       scanf("%d",&P[i].burstTime);
       printf(" Enter arrival time : ");
       scanf("%d",&P[i].arrivalTime);
       printf(" Enter priority : ");
       scanf("%d",&P[i].priority);
   }
   printf("\n PROG.\tB.T.\tA.T.\tPRIORITY");
   for(i=0;i<n;i++)
       printf("\n %s\t%d\t%d\t%d",P[i].name,P[i].burstTime,P[i].arrivalTime,P[i].priority);
   return n;
}


void sortFunction(processes temp[],int n)
{
   processes x;
   int i,j;
   for(i=1;i<n;i++)
       for(j=0;j<n-i;j++){
           if(temp[j].arrivalTime > temp[j+1].arrivalTime){
               x = temp[j];
               temp[j] = temp[j+1];
               temp[j+1] = x;
           }
       }
}

// FCFS Algorithm
void FCFS(processes P[],int n){
   processes temp[10];
   int sumw=0,sumt=0;
   int x = 0;
   float avgwt=0.0,avgta=0.0;
   int i,j;
   for(i=0;i<n;i++)
       temp[i]=P[i];

   sortFunction(temp,n);

       printf("\n\n PROG.\tB.T.\tA.T.");
       for(i=0;i<n;i++)
           printf("\n %s\t%d\t%d",temp[i].name,temp[i].burstTime,temp[i].arrivalTime);

       sumw = temp[0].waitingTime = 0;
       sumt = temp[0].turnAround = temp[0].burstTime - temp[0].arrivalTime;

       for(i=1;i<n;i++){
           temp[i].waitingTime = (temp[i-1].burstTime + temp[i-1].arrivalTime + temp[i-1].waitingTime) - temp[i].arrivalTime;;
           temp[i].turnAround = (temp[i].waitingTime + temp[i].burstTime);
           sumw+=temp[i].waitingTime;
           sumt+=temp[i].turnAround;
       }
       avgwt = (float)sumw/n;
       avgta = (float)sumt/n;
       printf("\n\n PROG.\tB.T.\tA.T.\tW.T\tT.A.T");
       for(i=0;i<n;i++)
           printf("\n %s\t%d\t%d\t%d\t%d",temp[i].name,temp[i].burstTime,temp[i].arrivalTime,temp[i].waitingTime,temp[i].turnAround);

       printf("\n\n GANTT CHART\n ");
       for(i=0;i<n;i++)
           printf(" %s ",temp[i].name);
       printf("\n ");

       printf("0\t");
       for(i=1;i<=n;i++){
           x+=temp[i-1].burstTime;
           printf("%d ",x);
       }
       printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}


int main(){

   processes P[10];
   int choice,n;
   do{
       printf("\n\n  CPU SCHEDULING ALGORITHMS SIMULATION \n");
       printf("\n Options:");
       printf("\n 0. Enter process data.");
       printf("\n 1. FCFS\n");

       scanf("%d",&choice);
       switch(choice){
           case 0:
               n=accept(P);
               break;
           case 1:
               FCFS(P,n);
               break;

       }
   }while(choice <! 0 || choice >!1);
   getchar();

   return 0;
}
