#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int i;
//static int  n =0;
 void  swap(int *a,int *b){
     int temp = *a;
       *a = *b;
       *b = temp;
       }
void minheapify(int arr[],int n,int i) {
    int smallest ,left,right;
    smallest =i;
    left = 2*i+1;
    right = 2*1+2;
    if(left<n && arr[left]<arr[smallest]){
        smallest = left;
    }
    if(right <n && arr[right]<arr[smallest]){
        smallest = right;
    }
    if(smallest !=i){
        swap(&arr[i],&arr[smallest]);
        minheapify(arr,n,smallest);
    }
}
void insert(int arr[],int *n,int key)  {
    if((*n) >= MAXSIZE){
        printf("\n stack overflow");
        return ;
    }
    (*n)++;
    i = (*n)-1;
    arr[i]= key;
    while( i!=0 && arr[(i-1)/2] > arr[i]){
        swap(&arr[i],&arr[(i-1)/2]);
        i= (i-1)/2;

    }
    }
void display(int arr[],int n){
     for (int i =0;i<(n);i++){
         printf("%d ",arr[i]);
         }
    }
 void delete(int arr[],int *n,int key){
    int i;
    for(i=0;i<*n;i++){
        if(arr[i]==key){
            break;
        }
    }
    if(i<*n)
    {
        swap(&arr[i],&arr[*n-1]);
        (*n)--;
        minheapify(arr,int(*n),i);
    }else{
        printf("element not found");
    }
 }

 void main(){
    int arr[MAXSIZE],key,choice,n=0;
     do{
        printf("\n enter the choice 1.insert 2.display 3.delete 4. exit");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("\n enter the element");
                     scanf("%d",&key);
                     printf("\n inseted ele is %d",key);
                     insert(arr,&n,key);
                     break;
            case 2  : display(arr,n);break;

            case 3  :printf("enter the elements u want to delete ");
                      scanf("%d",&key);
                      printf("deleted ele is %d",key);
                       delete(arr,&n,key);break;
            case 4   : exit(0);break;         
        }
     }while(choice!=4);

     
 }

 