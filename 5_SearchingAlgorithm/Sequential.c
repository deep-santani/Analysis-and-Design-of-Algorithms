#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int sequentialSearch(int list[],int totalElement,int findNum){
	int i;
    for(i=0;i<totalElement;i++){
		if(list[i]==findNum)
			break;
	}
    return i;
}

void main(){
    int num,i,index;
    int *array;
    int t1,t2;
    float t3,t4;
    int tt1,tt2;
    struct timeval tv;
    struct timezone tz;

    printf("\nWhat value you want to find : ");
    scanf("%d",&num);

    array = (int*)malloc(100000*sizeof(int));

    for(i=0 ; i < 100000 ;i++)
        array[i]=i+1;      
    
    gettimeofday(&tv,&tz);
    tt1 = tv.tv_sec;
    t1 = tv.tv_usec;
    
    index = sequentialSearch(array,100000,num);

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
