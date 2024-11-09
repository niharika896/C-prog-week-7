#include <stdio.h>
#include <stdlib.h>

void findLargest(int *arr,int n){
    int largest=arr[0];
    for(int i=0;i<n;i++)if(arr[i]>largest)largest=arr[i];
    printf("The largest value is %d",largest);
}
int main(){
    int n;
    printf("ENter size of array"); scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    findLargest(a,n);
    free(a);
}
