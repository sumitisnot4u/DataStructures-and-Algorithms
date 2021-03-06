//Question: Given an Array, find the array of minimums to the right of each element of the given array.
// Time Complexity: O(n)

#include<stdio.h>
#include<stdlib.h>

void NextMinArray(int *A,int n,int *ans)
{
    int *stack = malloc(n*sizeof(int));

    int top = -1;
    for(int i =0;i<n;i++)
    {
        if(top < 0)
            stack[++top] = i;
        else if(A[stack[top]] < A[i])
            stack[++top] = i;
        else if(A[stack[top]] > A[i])
        {
            while(top >= 0 && A[stack[top]] > A[i])
                ans[stack[top--]] = i;
            stack[++top] = i;
        }
    }
    while(top >=0)
        ans[stack[top--]] = -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int *arr= malloc(n*sizeof(int));
    int *ans = malloc(n*sizeof(int));
    for(int i =0;i<n;i++)
        scanf("%d",&arr[i]);
    NextMinArray(arr,n,ans);
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;   
}
