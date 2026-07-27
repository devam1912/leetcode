class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int n = nums.size();
        int pro1=(nums[0]-1)*(nums[1]-1);
        int pro2=(nums[n-1]-1)*(nums[n-2]-1);
        return max(pro1,pro2);
    }
};