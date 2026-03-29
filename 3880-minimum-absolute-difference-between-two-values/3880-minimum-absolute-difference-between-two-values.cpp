class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        vector<pair<int,int>>store;
        int count1=0;
        int count2=0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1 || nums[i]==2)
            {
                store.push_back({i,nums[i]});
            }
            if(nums[i]==1)count1++;
            if(nums[i]==2)count2++;
        }
        if(count1==0 || count2==0) return -1;
        sort(store.begin(),store.end());
        int  m = store.size();
        int mini = INT_MAX;
        for(int i=1;i<m;i++)
        {
            if(store[i].second != store[i-1].second)
            {
                int num = (store[i].first-store[i-1].first);
                mini = min(mini,num);
            }
        }
        return mini;
    }
};