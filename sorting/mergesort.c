#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int left,int m, int right){
    int i,j,k;
    int n1 = m-left+1;
    int n2 = right-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i]= arr[left+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]= R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=L[i];
         i++;k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;k++;
    }
}
void mergesort(int arr[],int left ,int right){
         if(left<right){
            int m = left+(right-left)/2;
            mergesort(arr,left,m);
            mergesort(arr,m+1,right);
            merge(arr,left,m,right);
         }
}
void printArray(int arr[] ,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}
int main(){
    int arr[]= {12,11,13,5,6,8,45,34,36,87,49,50,19,43,33};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\n given array is :");
    printArray(arr,n);
    mergesort(arr,0,n-1);
    printf("\n sorted array is :");
    printArray(arr,n);
    return 0;
    }