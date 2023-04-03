#include <stdio.h>
int main()
{
    int n, maxKnap, i;
    float sum = 0, maxVal = 0, lastItem;
    printf("Enter numer of items:");
    scanf("%d",&n);
    int W[n], V[n], I[n], ans[n];
    for(int i = 0; i < n; i++) {
        printf("For %d item ~\n", i+1);
        printf("Enter value of weight (in kg):");
        scanf("%d",&W[i]);
        printf("Enter value for %d kg weight:",W[i]);
        scanf("%d",&V[i]);
        I[i] = i+1;
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1; j++) {
            float valToWeight = (float)(V[j])/W[j];
            if(valToWeight < (float)V[j+1]/W[j+1]) {
                int temp = W[j];
                W[j] = W[j+1];
                W[j+1] = temp;
                
                temp = V[j];
                V[j] = V[j+1];
                V[j+1] = temp;
                
                temp = I[j];
                I[j] = I[j+1];
                I[j+1] = temp;
            }
        }
    }
    printf("--------------------------------------------\nEnter maximum weight limit:");
    scanf("%d",&maxKnap);
    for(i = 0; i < n; i++) {
        sum += W[i];
        maxVal += V[i];
        if(maxKnap >= sum) {
            ans[i] = I[i];
        }
        else if(sum > maxKnap) {
            ans[i] = I[i];
            sum = sum - W[i];
            maxVal = maxVal - V[i];
            int req = maxKnap - sum;
            sum = sum + req;
            maxVal = maxVal + (req * V[i])/(float)W[i];
            lastItem = (req)/(float)W[i];
            // printf("%f, %f",sum,maxVal);
            printf("Maximum weight that can be obtain: %0.2f\nMaximum value that can be obtain: %0.2f",sum,maxVal);
            break;
        }
        else break;
    }
    printf("\nItems in Order:\n");
    for(int j = 0; j < i; j++) {
        printf("%d  ",ans[j]);
    }
    printf("%0.2f of %d",lastItem, ans[i]);
    return 0;
}
