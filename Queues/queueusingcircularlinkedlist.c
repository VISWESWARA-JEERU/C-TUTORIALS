#include<stdio.h>
#include<stdlib.h>
struct node{
     int data;
     struct node *l;
}*front,*rear,*temp;
void enqueue();
void dequeue();
void display();
void enqueue(){
    struct node *newnode;
    newnode = (struct node*)malloc (sizeof(struct node ));
     printf("\n enter the data ");
     scanf("%d",&newnode->data);
     newnode->l= NULL;
     if(front==NULL && rear== NULL){
        front = newnode;
        rear= newnode;
        rear->l= front;
     }else{
         rear->l= newnode;
         rear = newnode;
         rear->l=front;
          }
     
}
void dequeue(){
     if(front==NULL && rear == NULL){
         printf("\n queue is empty");
     }else if( front==rear){
         printf("\n deleting node is %d",front->data);
         front= rear= NULL;
         free(front);

     }else{
         temp = front;
         front= front->l;
         rear->l= front;
         printf("\n deleting node is %d",temp->data);
         free(temp);
         }
 }
 void display(){
     if(front== NULL && rear == NULL){
         printf("\n queue  is empty");
     }else{
         temp = front;
         while(temp->l != front){
            printf(" %d->",temp->data);
            temp = temp->l;
         }
         printf(" %d->",temp->data);
     }
 }
void main(){
     int k; 
     while(1){ 
      printf("\n enter choice 1.enqueue 2. dequeue 3.display 4. exit ");
      scanf("%d",&k);
       switch(k){
         case 1 : enqueue();  break;
          case 2 : dequeue();  break;
           case 3 : display();  break;
            case 4 : exit(0);  break;
             default : printf("\n invalid entered ");
       }
     }
}