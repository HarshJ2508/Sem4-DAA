#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Print paranthesis recursive function that divides matrices sequence into two parts
void printParenthesis(int i, int j, int n, int paranthesis[][10], char *matrices)
{
    if(i < 0 || j > n) return;
    
    if(i == j) {
        printf("%c",matrices[i-1]);
        return;
    }
    
    printf("(");
    printParenthesis(i,paranthesis[i][j],n,paranthesis,matrices);
    printParenthesis(paranthesis[i][j] + 1,j,n,paranthesis,matrices);
    printf(")");
    
}
int main()
{
    int n; //n = 10
    printf("Enter total no. of Dimensions of Matrices:");
    scanf("%d",&n);
    int *dim = (int *)malloc(sizeof(int) * n);
    //Randomly generated number between 15 and 46
    printf("Randomly Generated Dimension:\n");
    for(int i = 0; i < n; i++) {
        dim[i] = rand() % 46 + 15;
        printf("Dimension at %d index: %d\n",i,dim[i]);
    }
    int dp[n][n], paranthesis[n][n];
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n; j++) {
            dp[i][j] = 0;
            paranthesis[i][j] = 0;
        }
    }
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int d = 0;
    for(int k = 0; k < n - 1; k++) {
        d = d + 1;
        int j = d;
        for(int i = 1 ; i <= n - d; i++, j++) {
            if(i == j) {
                 dp[i][j] = 0;
                 paranthesis[i][j] = 0; 
            }
            else {
                int m = i;
                int min = dp[i][m] + dp[m+1][j] + dim[i-1]*dim[m]*dim[j];
                paranthesis[i][j] = i;
                for(m = i + 1; m < j; m++) {
                    if(min > dp[i][m] + dp[m+1][j] + dim[i-1]*dim[m]*dim[j]) {
                        min = dp[i][m] + dp[m+1][j] + dim[i-1]*dim[m]*dim[j];
                        paranthesis[i][j] = m;
                    }
                }
                dp[i][j] = min;
            }
        }
    }
    
    printf("\nAuxillary table:\n");
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n; j++) {
            printf("%d\t",dp[i][j]);
        }
        printf("\n");
    }
    printf("\nTable for storing value of k:\n");
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n; j++) {
            printf("%d\t",paranthesis[i][j]);
        }
        printf("\n");
    }
    int i = 1, j = n - 1;
    char matrices[9] = "ABCDEFGHI";
    printf("\nOptimal cost for multiplication of 10 Matrices : %d\n",dp[1][9]);
    printf("\nOptimal Paranthesizing : ");
    printParenthesis(i, j, n, paranthesis,matrices);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTime taken for calculating optimal cost and paranthesization is: %fs",cpu_time_used);
    return 0;
}
