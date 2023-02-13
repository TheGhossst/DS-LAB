#include <stdio.h>

void display(int a[],int n){
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
}
void heapify(int a[],int heapsize,int i){
    int left=2*i+1,right=2*i+2,largest=i,temp;
    if(left<heapsize && a[left]>a[largest])  
        largest=left;
    if(right<heapsize && a[right]>a[largest]) 
        largest=right;
    if(largest!=i){
        temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        heapify(a,heapsize,largest);
    }
}
void heapsort(int a[],int heapsize){
    int i,temp;
    for(i=(heapsize/2)-1;i>=0;i--)
        heapify(a,heapsize,i);
    for(i=heapsize-1;i>=0;i--){
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}
void main(){
    int i,n,heapsize;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    heapsize=n;
    for(i=0;i<n;i++){
        printf("Enter element a[%d]: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nThe array before sorting: ");
    display(a,n);
    heapsort(a,heapsize);
    printf("\nThe array after sorting: ");
    display(a,n);
}