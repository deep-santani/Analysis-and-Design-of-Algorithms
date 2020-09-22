#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void maxHeap(int a[],int i, int n){
	int largest=i,t;
	int l=(2*i)+1;
	int r=(2*i)+2;
	while((l<=n) && (a[l]>a[largest]))
		largest=l;
	while((r<=n) && (a[r]>a[largest]))
		largest=r;
	if(largest!=i){
		t=a[largest];
		a[largest]=a[i];
		a[i]=t;
		maxHeap(a,largest,n);
	}
}

void heapSort(int a[],int n){
	int i,t;
	for(i=(n/2)-1;i>=0;i--)
			maxHeap(a,i,n);
	for(i=n-1;i>=0;i--){
			t=a[0];
			a[0]=a[i];
			a[i]=t;
			maxHeap(a,0,i-1);
		}
}

void main(){
    
    int n,i;
    int *array;
    int t1,t2;
    float t3,t4;
    int tt1,tt2;
    struct timeval tv;
    struct timezone tz;

    printf("\nHow many values You want to enter:");
    scanf("%d",&n);

    array = (int*)malloc(n*sizeof(int));

    for(i=0 ; i < n ;i++){
        //array[i]=rand()%1000;        //For Average Case
        //array[i]=i+1;             //For Best Case
        array[i]=n-i;            //For Worst Case
    }

    gettimeofday(&tv,&tz);
    tt1 = tv.tv_sec;
    t1 = tv.tv_usec;
    
    heapSort(array,n);
    
    gettimeofday(&tv,&tz);
    tt2 = tv.tv_sec;
    t2 = tv.tv_usec;

    tt1 = tt1%100;
    t3 = (float)t1*(0.000001);
    t3 = t3 + (float)tt1;
    tt2 = tt2%100;
    t4 = (float)t2*(0.000001);
    t4 = t4 + (float)tt2;

    printf("\nStart : %d.%d",tt1,t1);
    printf("\nEnd   : %d.%d",tt2,t2);

    if(t4>t3)
        printf("\nDifferenc1 : %f",t4-t3);
    else
        printf("\nDifferenc2 :  %f",t3-t4);

    free(array);
}
