#include<stdio.h>
#define N 6
int q[N],front=-1,rear=-1;
void enqueue(int x );
void dequeue();
void display();
void enqueue(int x ){
 
 if( front==-1 && rear==-1){
     front = rear = 0;
     q[rear]= x;
   }  
   else if ( (rear+1)%N == front){
     printf("\n queue is full"); 
   }
   else{
      rear =(rear+1)%N ;
      q[rear]=x;
   }

}
void dequeue(){
     if(front ==-1&& rear == -1){
        printf("\n queue is empty");
     }
     else if(front == rear){
        front = rear = -1;
     }else{
         printf("\n dequeue element is %d",q[front]);
         front = (front+1)%N ;
     }

}
void display(){
     int i;
      i= front;
     if(i==rear){
        printf("\n queue is empty");
     }else{
         while(i!=rear){
            printf(" ->%d ",q[i]);
            i = (i+1)%N;

         }
         printf(" ->%d ",q[rear]);
     }
     }
void main(){
     enqueue(68);
     enqueue(3);
     enqueue(8);
     enqueue(34);
     enqueue(567);
     enqueue(45);
     enqueue(456);
     display();
     dequeue();
     dequeue();
     dequeue();
     display();
}

