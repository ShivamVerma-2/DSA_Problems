// class Solution {
// public:
#include<vector>
#include<iostream>
using namespace std;
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        if (n < 3) return 0;

        for (int i = 0; i < n - 2; i++) {
            // Check if nums[i+1] is exactly twice (nums[i] + nums[i+2])
            // but here it's "sum = half of middle"
            // So: nums[i] + nums[i+2] == nums[i+1] / 2
            // Ensure nums[i+1] is even if we expect an exact half
            if (nums[i+1] % 2 == 0 && nums[i] + nums[i+2] == nums[i+1] / 2) {
                count++;
            }
        }
        return count;
    }
int main(){
    cout<<"Enter the number of  elements"<<endl;
   int n;
   cin>>n;
   vector<int>nums(n);
   cout<<"Enter the elements"<<endl;
   for(int i=0;i<n;i++){
    cin>>nums[i];
   }
   int ans;
    ans=countSubarrays(nums);
    cout<<"the anser is"<<ans;
   return 0;
}