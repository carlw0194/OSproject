//Round Robin Scheduling
void RR(processes P[],int n)
{
   int pflag=0,t,tcurr=0,k,i,Q=0;
   int sumw=0,sumt=0;
   float avgwt=0.0,avgta=0.0;
   processes temp1[10],temp2[10];

   for(i=0;i<n;i++)
       temp1[i]=P[i];

   sortFunction(temp1,n);

   for(i=0;i<n;i++)
       temp2[i]=temp1[i];

   printf("\n Enter quantum time : ");
   scanf("%d",&Q);

   for(k=0;;k++){
       if(k>n-1)
           k=0;
       if(temp1[k].burstTime>0)
           printf(" %d %s",tcurr,temp1[k].name);
       t=0;
       while(t<Q && temp1[k].burstTime > 0){
           t++;
           tcurr++;
           temp1[k].burstTime--;
       }
       if(temp1[k].burstTime <= 0 && temp1[k].flag != 1){
           temp1[k].waitingTime = tcurr - temp2[k].burstTime - temp1[k].arrivalTime;
           temp1[k].turnAround = tcurr - temp1[k].arrivalTime;
           pflag++;
           temp1[k].flag = 1;
           sumw+=temp1[k].waitingTime;
           sumt+=temp1[k].turnAround;
       }
       if(pflag == n)
           break;
   }
   printf(" %d",tcurr);
   avgwt = (float)sumw/n;
   avgta = (float)sumt/n;
   printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}
