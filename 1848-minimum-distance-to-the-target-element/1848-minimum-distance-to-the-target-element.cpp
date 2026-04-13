class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        vector<int>store;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target) store.push_back(i);
        }
        for(int i=0;i<store.size();i++)
        {
            int r = abs(store[i]-start);
            ans = min(ans,r);
        }
        return ans;
    }
};