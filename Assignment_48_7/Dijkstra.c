#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void display(int vertex, int arr[][vertex]) {
    printf("Displaying Graph:\n");
    for(int i = 0; i < vertex; i++) {
        for(int j = 0; j < vertex; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
void displayAtInstant(int vertex,int *ans) {
    printf("\n");
    for(int i = 0; i < vertex; i++) {
        if(ans[i] == INT_MAX) printf("inf\t");
        else printf("%d\t",ans[i]);
    }
    printf("\n");
}
void checkShortest(int vertex, int Graph[][vertex], int *ans, int *flag, int i, int dist[][vertex]) {
    int minIndex = -1;
    for(int j = 0; j < vertex; j++) {
        if(Graph[i][j] >= 1 && flag[j] == INT_MAX) {
            if(ans[j] > ans[i] + dist[i][j]) {
                ans[j] = ans[i] + dist[i][j];
                minIndex = j;
            }
        }
    }
    if(minIndex != -1) flag[minIndex] = 0;
}
void shortestPath(int vertex, int Graph[][vertex], int dist[][vertex], int src) {
    printf("\nisplaying Graph:\n");
    display(vertex, Graph);
    printf("\nDisplaying Distance between edges:\n");
    display(vertex, dist);
    int ans[vertex], minDist = INT_MAX, flag[vertex], i = src, j, minIndex;
    for(int i = 0; i < vertex; i++) {
        ans[i] = flag[i] = INT_MAX;
    }
    ans[src] = flag[src] = 0;
    printf("\nShortest Minimum Index:%d\tMinimum Distance:%d",src,0);
    displayAtInstant(vertex, ans);
    for(int f = 0; f < vertex - 1; f++) {
        for(j = 0; j < vertex; j++) {
            if(Graph[i][j] >= 1 && flag[j] == INT_MAX) {
                if(f == 0) {
                    ans[j] = dist[i][j];
                    if(minDist > ans[j]) {
                        minDist = ans[j];
                        minIndex = j;
                    }
                }
                else {
                    if(ans[j] > ans[i] + dist[i][j]) {
                        ans[j] = ans[i] + dist[i][j];
                    }
                    
                }
            }
            if(flag[j] == INT_MAX) {
                if(minDist >= ans[j]) {
                    minDist = ans[j];
                    minIndex = j;
                }
            }
        }
        printf("\nShortest Minimum Index:%d\tMinimum Distance:%d",minIndex,minDist);
        minDist = INT_MAX;
        flag[minIndex] = 0;
        displayAtInstant(vertex, ans);
        // displayAtInstant(vertex, flag);
        // for(j = 0; j < vertex; j++) {
        //     if(ans[j] == ans[minIndex] && flag[j] == INT_MAX) checkShortest(vertex,Graph,ans,flag,j,dist);
        // }
        i = minIndex;
    }
    
}
int main()
{
    int vertex = 5, edge = 10, v0, v1, distance, src;
    printf("Enter number of vertex:");
    scanf("%d",&vertex);
    printf("Enter number of edges:");
    scanf("%d",&edge);
    int Graph[vertex][vertex];
    int dist[vertex][vertex];

    for(int i = 0; i < vertex; i++) {
        for(int j = 0; j < vertex; j++) {
            Graph[i][j] = 0;
            dist[i][j] = 0;
        }
    }
    printf("Assuming vertex starting from 0, 1, 2,...n\n");
    char a, b;
    for(int i = 0; i < edge; i++) {
        printf("Enter edge from v0 to v1:");
        scanf(" %c %c",&a, &b);
        v0 = a - 65;
        v1 = b - 65;
        getchar();
        Graph[v0][v1] = 1;
        
        printf("Enter distance between %c and %c:",a,b);
        scanf("%d",&distance);
        dist[v0][v1] = distance;
    }
    getchar();
    printf("Enter starting source:");
    scanf("%c",&a);
    src = a - 65;
    shortestPath(vertex, Graph, dist, src);
    return 0;
}
