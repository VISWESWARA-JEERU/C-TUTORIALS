#include<stdio.h>
#include<stdlib.h>

struct node* create();
struct node 
    {
        int data;
        struct node *left,*right;
    };
   
void main(){
    
   struct node *root;
     root = 0;
     root=create();

};
 struct node* create() 
 {   
     struct node *newnode;
     newnode = (struct node*) malloc(sizeof(struct node));
     printf("\n enter the data value and enter -1 for no node");
     scanf("%d",&newnode->data);
     if(newnode->data==-1){
        return 0;
     }
     printf("\n enter data for left child %d ",newnode->data);
     newnode->left =create();
     printf("\n enter data for right child %d ",newnode->data);
     newnode->right =create();


 }  

