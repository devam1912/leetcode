class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            long long operations = 0;
            
            for (int x : nums) {
                operations += (x - 1) / mid;
            }
            
            if (operations <= maxOperations) {
                ans = mid;        // possible answer
                right = mid - 1;  // try smaller
            } else {
                left = mid + 1;   // need bigger max size
            }
        }
        
        return ans;
    }
};