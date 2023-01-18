#include<stdio.h>

int i=0;

void move(int n,char source,char target,char temp) {
    if(n==1) {
        printf("move one disk from %c to %c\n",source,target);
        i++;
    }
    else {
        move(n-1,source,temp,target);
        move(1,source,target,temp);
        move(n-1,temp,target,source);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    move(n,'A','C','B');
    printf("sum of move = %d",i);
    return 0;
}