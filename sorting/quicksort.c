#include<stdio.h>
#include<stdlib.h>
int i,j,p,q,x,m;
void swap(int *a,int *b){
    int temp = *a;
    *a =*b;
    *b = temp;
}
int  partition(int arr[],int p,int q){
    x= arr[p];
    i=p;
    for(j=p+1;j<=q;j++){
        if(arr[j]<=x){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[p],&arr[i]);
    return i;
    }
  void quicksort(int arr[],int p,int r){
       if(p<r){
        int q = partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
       }
  } 
  void printArray(int arr[],int n){
 for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
  }
  int main(){
    int arr[] = {4,2,3,5,1,7,67,76,22,35,74,77,78,85,89,97,69,108,104};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d",n);
    printf("\n enter a random index <=size");
    scanf("%d",&m);
    swap(&arr[0],&arr[m]);
    printf("\n given array is :");
    printArray(arr,n);
    quicksort(arr,0,n-1);
    printf("\n after th quick sort :");
    printArray(arr,n);
  }