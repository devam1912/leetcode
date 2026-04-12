class Solution {
public:
    int counter(int num,int dig)
    {
        int r=0;
        while(num>0)
        {
            int rem = num%10;
            if(rem == dig) r++;
            num/=10;
        }
        return r;
    }

    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int num;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            num = counter(nums[i],digit);
            ans+=num;
        }
        return ans;
    }
};