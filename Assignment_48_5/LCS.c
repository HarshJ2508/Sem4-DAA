#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
      char str1[20], str2[20];
      printf("Enter 1st string:");
      scanf("%s",str1);
      for(int i = strlen(str1); i >= 1; i--) {
          str1[i] = str1[i-1];
      }
      str1[0] = 'x';

      printf("\nEnter 2nd string:");
      scanf("%s",str2);
      for(int i = strlen(str2); i >= 1; i--) {
          str2[i] = str2[i-1];
      }
      str2[0] = 'y';

      int rows = strlen(str1);

      int columns = strlen(str2);
      int dp[rows][columns], direction[rows][columns];
      clock_t start, end;
      double cpu_time_used;
      start = clock();
      // 0 for diagonal arrow, 1 for up and -1 for left arrow 
      for(int i = 0 ; i < rows ; i++) {
          for(int j = 0 ; j < columns; j++) {
              dp[i][j] = 0;
          }
      }
      for(int i = 1; i < rows; i++) {
          for(int j = 1; j < columns; j++) {
              if(str1[i] == str2[j]) {
                  dp[i][j] = dp[i-1][j-1] + 1;
                  direction[i][j] = 0;

              }
              else if(str1[i] != str2[j]) {
                  if(dp[i-1][j] >= dp[i][j-1]) {
                      dp[i][j] = dp[i-1][j];
                      direction[i][j] = 1;
                  }
                  else {
                      dp[i][j] = dp[i][j-1];
                      direction[i][j] = -1;
                  }
              }
          }
      }
      printf("\nAuxillary Table:\n");
      for(int i = 0 ; i < rows ; i++) {
          for(int j = 0 ; j < columns; j++) {
              printf("%d\t",dp[i][j]);
          }
          printf("\n");
      }
      printf("\nArrow Direction Table:\n0 represents diagonal arrow\n1 represents upward\n-1 represents left direction\n");
      for(int i = 1 ; i < rows ; i++) {
          for(int j = 1 ; j < columns; j++) {
              printf("%d\t",direction[i][j]);
          }
          printf("\n");
      }
      // int ans[(rows < columns)? rows - 1 : columns - 1], k = -1;
      int ans[10], k = -1;
      for(int i = rows - 1 ; i >= 1 ; ) {
          for(int j = columns - 1 ; j >= 1; ) {
              // diagonal arrow
              if(direction[i][j] == 0) {
                  ans[++k] = i;
                  i -= 1;
                  j -= 1;
              }
              // Up
              else if(direction[i][j] == 1) {
                  i--;
              }
              // Left arrow
              else {
                  j--;
              }
              if(i < 1 || j < 1) break;
              // printf("\n%d\t%d\t%d\n",i,j,direction[i][j]);
          }
          printf("\n");
      }
      printf("Longest Common Subsequence from X and Y is : ");
      for(int i = k ; i >= 0; i--) {
          printf("%c",str1[ans[i]]);
      }
      end = clock();
      cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
      printf("\n\nTime taken for calculating longest common subsequence is: %f s",cpu_time_used);
      return 0;
}
