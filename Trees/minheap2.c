#include<stdio.h>
#include <conio.h>
#define MAX_SIZE 100
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int arr[],int n,int i){
	int smallest,left,right;
	smallest=i;
	left=2*i+1;
	right=2*i+2;
	if(left<n && arr[left]<arr[smallest]){
		smallest=left;
	}
	if(right<n && arr[right]<arr[smallest]){
		smallest=right;
	}
	if(smallest!=i){
		swap(&arr[i],&arr[smallest]);
		heapify(arr,n,smallest);
	}
}
void buildMinHeap(int arr[],int n){
	int i;
	for(i=n/2-1;i>=0;i++){
		heapify(arr,n,i);
	}
}
void insert(int arr[],int (*n),int key){
	int i;
	if(*n>=MAX_SIZE){
		printf("full");
		return;
	}
	(*n)++;
	i=*n-1;
	arr[i]=key;
	while(i!=0&&arr[(i-1)/2]>arr[i]){
		swap(&arr[(i-1)/2],&arr[i]);
		i=(i-1)/2;
	}
}
void delete(int arr[],int *n){
	if(*n<=0){
		printf("empty");
		return;
	}
	arr[0]=arr[*n-1];
	(*n)--;
	heapify(arr,*n,0);
}
void display(int arr[],int size){
	int i;
	printf("displaying...");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
void main(){
	int arr[MAX_SIZE];
	int n=0;
	insert(arr,&n,13);
	insert(arr,&n,16);
	insert(arr,&n,31);
	insert(arr,&n,41);
	insert(arr,&n,51);
	insert(arr,&n,100);
	delete(arr,&n);
	display(arr,n);


}