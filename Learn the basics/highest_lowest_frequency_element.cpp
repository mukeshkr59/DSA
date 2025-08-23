#include <bits/stdc++.h>
using namespace std;

void countFreq(int arr[], int n)
{
    vector<bool> visited(n, false);
    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    for (int i = 0; i < n; i++) {

        // Skip this element if already processed
        if (visited[i] == true)
            continue;

        // Count frequency
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        if (count > maxFreq) {
            maxEle = arr[i];
            maxFreq = count;
        }
        if (count < minFreq) {
            minEle = arr[i];
            minFreq = count;
        }
    }
    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";
}

int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
}



// Time Complexity: O(n^2)
// Space Complexity: O(n)           

// Efficient Approach using Hashing
/*  
#include <bits/stdc++.h>
using namespace std;        
*/

void countFreq(int arr[], int n)
{
    unordered_map<int, int> freqMap;
    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    for (int i = 0; i < n; i++) {
        freqMap[arr[i]]++;
    }

    for (const auto& pair : freqMap) {
        if (pair.second > maxFreq) {
            maxEle = pair.first;
            maxFreq = pair.second;
        }
        if (pair.second < minFreq) {
            minEle = pair.first;
            minFreq = pair.second;
        }
    }

    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";
}   

int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
}
