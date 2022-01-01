#include<stdio.h>
#include<stdlib.h>

int main(){

   processes P[10];
   int choice,n;
   do{
       printf("\n\n CPU SCHEDULING ALGORITHMS SIMULATION \n");
       printf("\n Options:");
       printf("\n 0. Enter process data.");
       printf("\n 1. FCFS");
       printf("\n 2. SJF (Preemptive)");
       printf("\n 3. SJF (Non Preemptive)");
       printf("\n 4. Priority Scheduling (Preemptive)");
       printf("\n 5. Priority Scheduling (Non Preemptive)");
       printf("\n 6. Round Robin");
       printf("\n 7. Exit\n Select : ");
       scanf("%d",&choice);
       switch(choice){
           case 0:
               n=accept(P);
               break;
           case 1:
               FCFS(P,n);
               break;
           case 2:
               sjfPreemptive(P,n);
               break;
           case 3:
               SJF_NP(P,n);
               break;
           case 4:
               PRT_P(P,n);
               break;
           case 5:
               PRT_NP(P,n);
               break;
           case 6:
               RR(P,n);
               break;
           case 7:exit(0);
       }
   }while(choice != 7);

   return 0;
}
