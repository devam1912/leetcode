class Solution {
public:
    bool isGood(vector<int>& nums) {

        if(nums.size() < 2)
            return false;

        sort(nums.begin(), nums.end());

        int n = nums.size() - 1;

        for(int i = 0; i < n - 1; i++) {
            if(nums[i] != i + 1)
                return false;
        }

        if(nums[n - 1] != n || nums[n] != n)
            return false;

        return true;
    }
};