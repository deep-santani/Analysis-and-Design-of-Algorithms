#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void insertionSort(int a[], int length){
	int i, index, p, j, temp;
	for(i=1; i<length; i++){
		p = a[i];
		for(j=i-1; (p < a[j] && j >= 0 ); j--){
			a[j+1]=a[j];
			a[j] = p;
		}
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
        array[i]=i+1;             //For Best Case
        //array[i]=n-i;            //For Worst Case
    }

    gettimeofday(&tv,&tz);
    tt1 = tv.tv_sec;
    t1 = tv.tv_usec;
    
    insertionSort(array,n);

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