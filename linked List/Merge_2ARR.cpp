#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size(), m = arr2.size();
    vector<int> merged;
    int i = 0, j = 0;

    // Merge both arrays into 'merged'
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j])
            merged.push_back(arr1[i++]);
        else
            merged.push_back(arr2[j++]);
    }

    // Append remaining elements
    while (i < n) merged.push_back(arr1[i++]);
    while (j < m) merged.push_back(arr2[j++]);

    // Copy back to arr1 and arr2
    for (int k = 0; k < n; ++k)
        arr1[k] = merged[k];
    for (int k = 0; k < m; ++k)
        arr2[k] = merged[n + k];
}
