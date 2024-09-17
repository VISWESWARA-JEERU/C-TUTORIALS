#include<stdio.h>
#include<stdlib.h>
struct node* create();               // These are 
void preorder(struct node *root);    //          all the 
void inorder(struct node *root);     //            declaration of
void postorder(struct node *root);   //                 user defined functions
struct node 
    {
        int data;                  //  This is a 
        struct node *left,*right;  //           creation of 
    };                             //               self-referential structure 
   
void main(){
    
   struct node *root;
     root = 0;
     root=create();
     printf("\npre-order is : ");
     preorder(root); // function to call preorder
     printf("\nin-order is : ");
     inorder(root);  // funtion to call inorder
     printf("\npost-order is : ");
     postorder(root); // function to call postorder
};
struct  node* create() 
 {   
     struct node *newnode;
     newnode = (struct node*) malloc(sizeof(struct node));// creation of dynamic memory
     printf("\n enter the data value and enter -1 for no node");
     scanf("%d",&newnode->data);// taking the vlaues of nodes from user
     if(newnode->data==-1){
        return 0;               // terminate the active function 
     }
     printf("\n enter data for left child %d ",newnode->data);
     newnode->left =create();    // store the address in left node
     printf("\n enter data for right child %d ",newnode->data);
     newnode->right =create();   // stroes the address in right node 
}  
void preorder(struct node *root){  //  function  prints the preorder
      if(root == 0)
      {
         return;      // terminate the function here
      }
    printf("%d ->",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root){     //   function prints the inorder
    if(root == 0){
         return;      // terminate the function here 
    }
    inorder(root->left);
    printf("%d ->",root->data);
    inorder(root->right);
}
void postorder(struct node *root){  // functon prints the postorder 
    if(root == 0){
         return ;     // terminate the function here 
    }
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ->",root->data);
}
