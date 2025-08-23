#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
    // Base Case: range == 1.
    if (n == 1) return;

    int didSwap = 0;
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            didSwap = 1;
        }
    }

    // if no swapping happens.
    if (didSwap == 0) return;

    //Range reduced after recursion:
    bubble_sort(arr, n - 1);
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);
    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

// Time Complexity: O(n^2) in worst and average case, O(n) in best case
// Space Complexity: O(n) due to recursion stack

// Stable Sort  
// In-Place Sort
// Adaptive Sort
// Online Sort
// Recursive Approach
// Not a Comparison Sort
// Not a Divide and Conquer Algorithm   

// Not a Stable Sort in this implementation as we are swapping adjacent elements


// Stable Sort can be implemented by removing the swapping part and shifting elements instead.

// Not a In-Place Sort in this implementation as we are using recursion stack space
// In-Place Sort can be implemented by using iterative approach instead of recursion.
// Not a Divide and Conquer Algorithm as we are not dividing the array into subarrays
// Divide and Conquer Algorithm can be implemented by using Merge Sort or Quick Sort instead.
// Not a Online Sort as we are not sorting the array as we receive the elements
// Online Sort can be implemented by using Insertion Sort instead.