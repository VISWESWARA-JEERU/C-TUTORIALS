#include<stdio.h>
#include<stdlib.h>
#define N 50
int stack[N],size =5, top= -1,k;
void push();
int pop();
void display();
void main(){
     int choice;
     do
    {
        printf("\n 1.push 2. pop 3.display 4.exit");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : push();
                 break;
        case 2 : k= pop();
                 printf("\n pop ele %d",k);
                 break;
        case 3 : display();
                  break;
        case 4 : exit(0);                  
                  break;
        default:printf("\n invalid entered");
            
     }
      } while(choice !=4);
}
    void push(){
         int ele;
         if( top == size-1 ){
            printf("\n overflow");
         }else{
            top++;
            printf("\n enter the element");
            scanf("%d",&ele);
            stack[top]= ele;
         }
    } 
    int pop(){
         int temp;
         if(top==-1){
            printf("\n underflow");
         }else{
             temp = stack[top];
             top--;
             
         }
         return temp;
    } 
    void display(){
         int i;
         if(top==-1){
             printf("\n stack is empty");
         }else{
            for(i=0;i<=top;i++){
                 printf(" %d",stack[i]);
            }
             
         }
    }
