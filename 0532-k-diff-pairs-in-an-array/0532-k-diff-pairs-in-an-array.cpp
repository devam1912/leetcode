class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = 1;
        int count = 0;

        while (right < n) {
            if (left == right || nums[right] - nums[left] < k) {
                right++;
            }
            else if (nums[right] - nums[left] > k) {
                left++;
            }
            else { 
                count++;
                left++;
                right++;
                
                while (right < n && nums[right] == nums[right - 1]) {
                    right++;
                }
            }
        }
        return count;
    }
};
