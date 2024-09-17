#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int i;
//static int  n =0;
 int  swap(int *a,int *b){
     int temp = *a;
       *a = *b;
       *b = temp;
       return 1;
       }
void insert(int arr[],int *n,int key)  {
    if((*n) >= MAXSIZE){
        printf("\n stack overflow");
        return ;
    }
    (*n)++;
    i = (*n)-1;
    while( i!=0 && arr[(i-1)/2] > arr[i]){
        swap(&arr[(i-1)/2],&arr[i]);
        i= (i-1)/2;

    }
    }
void display(int arr[],int *n){
     for (int i =0;i<(*n);i++){
         printf("%d ",arr[i]);
         }
    }
 

 void main(){
    int arr[MAXSIZE],key,choice,n=0;
     do{
        printf("\n enter the choice 1.insert 2.display 3.exit");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("\n enter the element");
                     scanf("%d",&key);
                     printf("\n inseted ele is %d",key);
                     insert(arr,&n,key);
                     break;
            case 2  : display(arr,&n);break;
            case 3   : exit(0);break;         
        }
     }while(choice!=3);

     
 }