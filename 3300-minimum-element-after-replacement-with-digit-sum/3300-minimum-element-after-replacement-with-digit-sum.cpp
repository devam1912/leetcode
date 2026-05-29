class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int temp=0;
            while(nums[i]>0)
            {
                int rem = nums[i]%10;
                 temp+=rem;
                 nums[i]/=10;
            }
            ans = min(ans,temp);
        }
        return ans;
    }
};