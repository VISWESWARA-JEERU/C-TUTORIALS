#include<stdio.h>
void insert_front();
struct node{
     int data;
     struct node *l;
}*first,*temp,*pre;
void main(){
    insert_front();
}
void insert_front(){
    struct node *newnode;
    newnode = (struct node*)malloc (sizeof(struct node));
    newnode->l= NULL;
    if(first == NULL){ 
        newnode = first;
    }else{
         newnode->l= first;
         first = newnode;
    }
     
}