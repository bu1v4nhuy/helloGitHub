/*
    Placing N chess queens on an NxN chessboard so that no two queens threaten each other
    Note: 1 is no threaten, 0 is threaten
    row: 1->n, column: 1->n
*/
#include<stdio.h>
#include<stdlib.h>

int count=0;

void Result(int *row, int n) {
    int i;
    for(i=1;i<=n;i++) {
        printf("(%d;%d) ",i,row[i]);
        if(i==n) printf("\n\n");
    }
}

void PlacingQueen(int *row, int *column, int *diagonal_1, int *diagonal_2, int n, int i) {
    int j;
    for(j=1;j<=n;j++) {
        if(column[j]==1 && diagonal_1[i-j+n-1]==1 && diagonal_2[i+j]==1) {
            row[i]=j;
            column[j]=0;
            diagonal_1[i-j+n-1]=0;
            diagonal_2[i+j]=0;
            if(i==n) {
                Result(row,n);
                count++;
            }
            else PlacingQueen(row,column,diagonal_1,diagonal_2,n,i+1);
            column[j]=1;
            diagonal_1[i-j+n-1]=1;
            diagonal_2[i+j]=1;
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    if(n>1 && n<4) printf("No solution");
    else {
        int *row = (int*) calloc (n+1,sizeof(int)); // value of row is index of column
        int *column = (int*) calloc (n+1,sizeof(int)); // value of column is 1 or 0
        int *diagonal_1 = (int*) calloc (2*n-1,sizeof(int)); // value of diagonal_1(i-j=const) is 1 or 0
        int *diagonal_2 = (int*) calloc (2*n+1,sizeof(int)); // value of diagonal_2(i+j=const) is 1 or 0
        int i,j;
        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) {
                column[j]=1;
                diagonal_1[i-j+n-1]=1;
                diagonal_2[i+j]=1;
            }
        }
        i=1;
        PlacingQueen(row,column,diagonal_1,diagonal_2,n,i);
        printf("The number of solution is %d",count);
    }
    return 0;
}