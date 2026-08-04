class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
     sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=0;i<nums.size()-1;i++)
            {
                int current = nums[i];
                int next=nums[i+1];
                while(current+1<next)
                {
                    ans.push_back(current+1);
                    current++;
                }
            }
        return ans;
    }
};