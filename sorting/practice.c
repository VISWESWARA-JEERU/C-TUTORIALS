//job sequencing
#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int ID=0;
    int deadline=0;
    int profit=0;
} jobsq;

int main(){
    int jobs;
    printf("Enter noof works:");
    scanf("%d",&jobs);
    jobsq jobArr[jobs];
    for(int i=0;i<jobs;i++){
        printf("Enter jod%d ID, deadline, and profit:",i+1);
        scanf("%d%d%d",&jobArr[i].ID,&jobArr[i].deadline,&jobArr[i].profit);
    }
    

}
