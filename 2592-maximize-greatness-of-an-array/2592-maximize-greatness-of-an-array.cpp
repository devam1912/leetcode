class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n  = nums.size();
        if (n<2) return 0;
        int i=0;
        int j=1;
        int count=0;
        while(j<n)
        {
            if(nums[i]!=nums[j])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
};