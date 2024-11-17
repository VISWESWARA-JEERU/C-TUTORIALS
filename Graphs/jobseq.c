#include<stdio.h>
#include<stdlib.h>
 struct Job{
    char id;
    int deadline;
    int profit;

};
int compare(const void* a,const void* b){
    struct Job* temp1 = (struct Job*)a;
    struct  Job* temp2 = (struct Job*)b;
    return (temp2->profit - temp1->profit); 
}
//int min(int num1,int num2){
  //  return num1>num2 ? num1: num2;
//}
void jobsequencing(struct Job jobs[],int n){
    qsort(jobs,n,sizeof(struct Job),compare);
    int slot[n];
    int result[n];
    for(int i=0;i<n;i++){
        slot[i] =0;
    }
    for(int i=0;i<n;i++){
        for(int j= jobs[i].deadline-1;j>=0;j--){
            if(slot[j]==0){
                result[j] =jobs[i].id;
                slot[j]=1;
                break;
            }
        }
    }

for(int i=0;i<n;i++)
{
    if(slot[i]){
        printf("%c",result[i]);
    }
}
}
int main(){
    int n;
    printf("enter the number of jobs");
    scanf("%d",&n);
    struct Job jobs[n];
    for(int i=0;i<n;i++){
        printf("\n enter the JOBID ,DEADLINE , PROFIT OF JOBS %d",i+1);
        scanf("%c%d%d",&jobs[i].id,&jobs[i].deadline,&jobs[i].profit);
    }
    jobsequencing(jobs,n);
    return 0;
}