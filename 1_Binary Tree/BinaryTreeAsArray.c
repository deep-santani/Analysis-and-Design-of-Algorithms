#include<stdio.h>
#include<conio.h>

struct BinaryTree
{
    int value;
    int leftChild;
    int rightChild;
};

struct BinaryTree tree[50] = {'\0'}; 


void insert(int num, int root){

    if (tree[root].value =='\0'){
        tree[root].value=num;
        tree[root].leftChild=((2*root)+1);
        tree[root].rightChild=((2*root)+2);
    }

    else if (num>tree[root].value){
        int a = ((2*root)+2);
        insert(num,a);
    }

    else if (num<tree[root].value){
        int a = ((2*root)+1);
        insert(num,a);
    }
}

void print(){
    printf("Tree in Array");
    printf("\nVAL \t LFT \t RGT\n");
    for(int i=0;i<50; i++){
        if(tree[i].value!='\0'){
            printf("\n%d \t %d \t %d\n",tree[i].value,tree[tree[i].leftChild].value,tree[tree[i].rightChild].value);
        }
    }
}

void main()
{ 
    int c=1,num;
    while(c!=2)
    {
        printf("\nEnter which function you want to execute:");
        printf("\n(1)Insert\n(2)Print\n(3)Exit\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("Enter the number:\n");
            scanf("%d",&num);
            insert(num,0);
            break;
        case 2:
            print();
            break;
        case 3:
            c=2;
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}