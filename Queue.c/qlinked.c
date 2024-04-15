#include<stdio.h>
#include<stdlib.h>
 void enqueue();
 void dequeue();
 void display();
struct node{
     int data;
     struct node *l;
}*front,*rear,*temp;
void main (){
     int k ;
       do{
        printf("\n enter choice 1. enqueue 2.dequeue 3. display 4.exit ");
        scanf("%d",&k);
         switch(k){
         case 1 : enqueue();break;
         case 2: dequeue();break;
         case 3 : display();break;
         case 4 : exit(0);break;
         default : printf("\n invalid entered");
         }
      }while(k!=4);
}
void enqueue(){
     struct node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));
     newnode->l= NULL;
     printf("\n enter the node data");
     scanf("%d",&newnode->data);
     if(front==NULL && rear == NULL){
         front = newnode;
         rear = newnode;
     }
    else{
         rear->l= newnode;
         rear = newnode;
    }
}
void dequeue(){
     if(front ==NULL && rear ==NULL){
           printf("\n queue is empty");
     }else if(front == rear)
     { 
          printf("\n deleting node is %d",front->data);
          free(front);
          free(rear);
     }else{
           temp = front;
           printf("\n deleting node is %d",front->data);
           front = front->l;
           free(temp);
           }
     
}
 void display(){
      if(front==NULL && rear == NULL){
          printf("\n queue is empty");
           
      }
      temp = front;
      while(temp!=NULL){
           printf(" %d->",temp->data);
           temp = temp->l;
      }
     
}

