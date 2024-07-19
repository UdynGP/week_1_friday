/*
Problem Statement : write a program that will moves all Zeroes to end of an array
For example -: Input: array = [1,2,0,4,3,0,5,0];
Output : array = [1, 2, 4, 3, 5, 0, 0, 0]
*/

#include <stdio.h>
// Function to move all zeroes to the end of the array
void moveZeroesToEnd(int arr[], int n)
{
    int count = 0; // Count of non-zero elements

    // Traverse the array. If the element is non-zero, then
    // replace the element at index 'count' with this element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[count++] = arr[i]; // Here count is incremented
        }
    }

    // Now all non-zero elements have been shifted to the front
    // and 'count' is set as the index of the first 0.
    // Make all elements 0 from count to end.
    while (count < n)
    {
        arr[count++] = 0;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:-\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    moveZeroesToEnd(arr, n);

    printf("Array after moving all zeroes to the end: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}