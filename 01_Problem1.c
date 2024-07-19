/*
Problem Statement :- write a program that takes an array and Find Second largest element in an array
For example -: Input: array = [12, 35, 1, 10, 34, 1]
Output: The second largest element is 34.
*/
#include <stdio.h>
#include <limits.h>

int findSecondLargest(int arr[], int n)
{
    int first, second;

    if (n < 2)
    {
        printf("Array should have at least two elements.\n");
        return -1;
    }

    first = second = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first)
        {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
    {
        printf("There is no second largest element.\n");
        return -1;
    }

    return second;
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int secondLargest = findSecondLargest(arr, n);

    if (secondLargest != -1)
    {
        printf("The second largest element is %d.\n", secondLargest);
    }

    return 0;
}