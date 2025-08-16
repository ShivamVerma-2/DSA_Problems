
class Solution {
public:
    int missingNum(vector<int>& arr) {
        int i = 0;
        int n = arr.size();
        
        while (i < n) {
            int correct = arr[i] - 1;
            if (arr[i] <= n && arr[i] != arr[correct]) {
                swap(arr[i], arr[correct]);
            } else {
                i++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
