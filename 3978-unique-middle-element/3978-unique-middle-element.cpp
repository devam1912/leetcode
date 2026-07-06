class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n=nums.size();
        int mid = (0+n)/2;
        int num = nums[mid];
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        if(freq[nums[mid]]==1) return true;
        return false;
    }
};