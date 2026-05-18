class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        int oddc=0;
        int evenc=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0) evenc++;
            else oddc++;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                evenc--;
                ans.push_back(oddc);
            }
            else
            {
                oddc--;
                ans.push_back(evenc);
            }
        }
        return ans;
    }
};