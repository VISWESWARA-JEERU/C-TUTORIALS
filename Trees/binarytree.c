#include<stdio.h>
#include<stdlib.h>
void insert();
 struct node* searchingnode(int x, struct node *root );
//void deletenode();
struct bstree
    {
        int data;
        struct bstree *left,*right;
    }*newnode,*root=NULL,*temp,*pre;
    int x,se,k;
   
 void insert(){
     
     do{
     newnode = (struct bstree*)malloc(sizeof(struct bstree));
     printf("\n enter the  node value");
     newnode->left = newnode->right = NULL;
     scanf("%d",&newnode->data);
     if(root == NULL){
         root = newnode;
     }
     else {
        temp = root;
        while(temp!= NULL){
            pre = temp;
             if(temp->data > newnode->data){
                 temp=temp->left ;
             }else{
                temp = temp->right;
             }

         if(pre->data < newnode->data){
            pre->right = newnode;
         }else{
            pre->left= newnode;
         }    
        }
       }
    printf("\n enter 1 for for continue o 0  for stop");
    scanf("%d",&x);
     }while(x!=0);
    
    

  }  
void main(){

insert();
printf("\n ener the searching element ");
scanf("%d",&se);
 k=searchingnode(se,root);
 printf("%d",k);


}
// //void deletenode(){
//     printf("\n enter the deleting node ");
//     scanf("%d",&deleteNode);
//     if(pre->left == deleteNode)
//      pre->left = NULL;
//      else
//      pre->right = NULL;
//     }
//}
struct node* searchingnode(int x ,struct node *root){
    if(x == (root->data) ){
        printf("element is found  %d",root->data);
    }else if(x < root->data){
        return root = searchingnode(x,root->left);
    }else{
       return root = searchingnode(x,root->right);
    }
}
