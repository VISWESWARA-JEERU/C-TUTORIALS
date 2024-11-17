#include<stdio.h>
#include<stdlib.h>
 struct Node{
     int key;
     struct Node *left,*right;
     int height;

};
int max(int a,int b){
     return a>b?a:b;
}
int height(struct Node *N){
     if(N==NULL)
       return 0;
     return N->height;
}
struct Node* newnode(int key){
     struct Node *node = (struct Node*)malloc(sizeof(struct Node));
     node->key = key;
     node->left = node->right = NULL;
     node->height = 1;
     return node;

}
struct Node* rightrotate(struct Node *temp1){
     struct  Node *temp2 = temp1->left;
      struct Node *temp3 = temp2->right;

     temp2->right = temp1;
     temp1->left = temp3;
     temp1->height = 1+max((height(temp1->left)),(height(temp1->right)));
     temp2->height = 1+max((height(temp2->left)),(height(temp2->right)));
     return temp2;

}
struct Node *leftrotate(struct Node *temp1){
    struct  Node *temp2 = temp1->right;
     struct Node *temp3 = temp2->left;

       temp2->left = temp1;
       temp1->right = temp3;
     temp1->height = 1+ max((height(temp1->left)),(height(temp1->right)));
     temp2->height = 1+ max((height(temp2->left)),(height(temp2->right)));
     return temp2;

}
int getbalance(struct Node *node){
     if(node ==NULL)
     return 0;
     
     return height(node->left)- height(node->right);
}
struct Node* insert(struct Node* node,int key){

     if(node==NULL){
          return (newnode(key));
      }
      if(key <node->key){
          node->left = insert(node->left,key);
      }else if(key>node->key){
          node->right = insert(node->right,key);
       }
     else{
          return node;
     }
     node->height = 1+max(height(node->left),height(node->right));
     int balance = getbalance(node);
     if(balance >1 && key <node->left->key){
          return rightrotate(node);
     }
     if(balance > 1 && key > node->left->key){
          node->left = leftrotate(node->left);
          return rightrotate(node);

     }
     if(balance < -1 && key > node->right->key){
         return  leftrotate(node);

     }
     if(balance <-1 && key<node->right->key){
          node->right = rightrotate(node->right);
          return leftrotate(node);
}
return node;

}
void preorder(struct Node* root){
     if(root !=  NULL){
    
    printf("%d ->",root->key);
    preorder(root->left);
    preorder(root->right);
    }
    }
int main(){
     struct Node *root =NULL;
     root =insert(root,10);
     root =insert(root,20);
     root = insert(root,30);
     root = insert(root,40);
     root =insert(root,50);
     root = insert(root,25);
    printf("preorder of the avl tree  is :");
    preorder(root);
return 0;
}

