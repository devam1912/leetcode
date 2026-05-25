class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
            if(freq[nums[i]]>k) continue;
            ans.push_back(nums[i]);
        }
        return ans;
    }
};