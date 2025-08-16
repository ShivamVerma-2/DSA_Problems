// #include <iostream>
// #include <vector>
// using namespace std;

// vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
//     vector<vector<int>> result;
//     int n = intervals.size();
//     int i = 0;

//     // Step 1: Add all intervals before newInterval
//     while (i < n && intervals[i][1] < newInterval[0]) {
//         result.push_back(intervals[i]);
//         i++;
//     }

//     // Step 2: Merge overlapping intervals
//     while (i < n && intervals[i][0] <= newInterval[1]) {
//         newInterval[0] = min(newInterval[0], intervals[i][0]);
//         newInterval[1] = max(newInterval[1], intervals[i][1]);
//         i++;
//     }
//     result.push_back(newInterval);

//     // Step 3: Add all remaining intervals
//     while (i < n) {
//         result.push_back(intervals[i]);
//         i++;
//     }

//     return result;
// }

// int main() {
//     vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
//     vector<int> newInterval = {17, 19};

//     vector<vector<int>> ans = insertInterval(intervals, newInterval);

//     for (auto& interval : ans) {
//         cout << "[" << interval[0] << "," << interval[1] << "] ";
//     }
//     return 0;
// }



#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int n = intervals.size();
    int i = 0;

    // Step 1: Add all intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }

    // Step 2: Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);

    // Step 3: Add all remaining intervals
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter intervals (start end) in any order:\n";
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    // Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    vector<int> newInterval(2);
    cout << "Enter new interval (start end): ";
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> ans = insertInterval(intervals, newInterval);

    cout << "Merged intervals:\n";
    for (auto& interval : ans) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
