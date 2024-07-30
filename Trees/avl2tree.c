#include<stdio.h>
#include<stdlib.h>
struct node *leftrotate(struct node*);
struct node *rightrotate(struct node*);
struct node{
     int key;
     struct node *left,*right;
     int height;

};
int max(int a, int b){
     return (a>b)?a:b;
}
int height (struct node *n){
     if(n==NULL){
        return 0;
     }else{
         return n->height;
     }
}
struct node *newnode(int key){
     struct node *node = (struct node *)malloc (sizeof(struct node));
     node->key = key;
     node->left = NULL;
     node->right = NULL;
     node->height = 1;
     }
 struct node  *rightrotate(struct node*)
 {
  struct node *x = y->left;
  struct node *T2 = x->right;
  
  y->height = max(height(y->left),height(y->right));
  x->height = max(height(x->left),height(x->right));
  return x;
}
struct node *leftrotate(struct node*)
{
     struct node *y = x->right;
     struct node *T2 = y->left;

     y->left = x;
     x->right = T2;
     
     x->height = max(height(x->left),height(->right));
     
     return y;

}
sturct node *insertnode(struct node *,int key){
     if(node == NULL){
         return (newnode(key));
     }
     if(key<node->key){
         node->left = insert(node->left,key);
         }
      else if(key>node->key){
         node->right = insert(node->right,key);
         }else{
             return node;
             }
     node->height = 1+ max(height(node->left),height(node->right) );       
         
}
int balance = getbalance(node);
if()