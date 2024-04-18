#include<stdio.h>
#define N 5
int q[N],front=-1,rear=-1;
void main(){
     while(1){
  if(rear == N-1)
   { printf("\n queue is full"); 
         break;
   }
   else if( front = -1 && rear == -1){
     front = rear = 0;
     printf("\n enter the element : ");
     scanf("%d",&q[rear]);
   }
   else{
      rear++;
     printf("\n enter the element : ");
     scanf("%d",&q[rear]);
   }
}

}