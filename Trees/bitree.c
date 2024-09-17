#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert();
void inorder();
struct node{
     int data;
     struct node *left ;
     struct node *right;

}*newnode,*root,*temp,*pre;
int k;
void insert(){
    do{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the node value ");
    scanf("%d",&newnode->data);
    if(root == NULL){
         root = newnode;
    }
    else{
    temp = root;
    while(temp!=NULL){
        pre = temp;
        if(newnode->data <= temp->data){
             temp = temp->left;
        }
        else{
             temp = temp->right;
        }
    }
    if(pre->data > newnode->data){
         pre->left = newnode;
    }else{
         pre->right = newnode;
    }
    }
    printf("\n enter 1 for continue , 0 for stop");
    scanf("%d",&k);

}while(k!=0);
}

void inorder(struct node* root){
    inorder(root->left);
    printf("%d ->",root->data);
    inorder(root->right);
}
void main(){
     insert();
     inorder(root);
     }
