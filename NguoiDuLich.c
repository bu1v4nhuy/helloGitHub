#include<stdio.h>
#include<stdlib.h>

int NumCity;
int min;
int cost=0;
int BestCost=INT_MAX;
int MatrixCost[107][107];
int Visited[107];
int Path[117];
int FinalPath[117];

int MinCost() {
    int min=MatrixCost[1][1];
    for(int i=1;i<=NumCity;i++) {
        for(int j=1;j<=NumCity;j++) {
            if(MatrixCost[i][j]<=min && i!=j) min=MatrixCost[i][j];
        }
    }
    return min;
}

void FindPath(int i) {
    for(int j=2;j<=NumCity;j++) {
        if(Visited[j]==0) {
            Path[i]=j;
            Visited[j]=1;
            cost=cost+MatrixCost[Path[i-1]][Path[i]];
            if(i==NumCity) {
                int sum=cost+MatrixCost[Path[NumCity]][1];
                if(sum<BestCost){
                    BestCost=sum;
                    for(int i=1;i<=NumCity;i++) {
                        FinalPath[i]=Path[i];
                    }
                }
            }
            else {
                if(cost+(NumCity-i+1)*min<BestCost) FindPath(i+1);
            }
            Visited[j]=0;
            cost=cost-MatrixCost[Path[i-1]][Path[i]];
        }
    }
}
int main() {
    scanf("%d",&NumCity);
    for(int i=1;i<=NumCity;i++) {
       for(int j=1;j<=NumCity;j++) {
        scanf("%d",&MatrixCost[i][j]);
       }
    }
    Path[1]=1;
    Visited[1]=1;
    for(int i=2;i<=NumCity;i++) {
        Visited[i]=0;
    }
    min=MinCost();
    int i=2;
    FindPath(i);
    for(int i=1;i<=NumCity;i++) {
        printf("%d ",FinalPath[i]);
        if(i==NumCity) printf("1\n");
    }
    printf("%d",BestCost);
    return 0;
}