class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = INT_MIN;
        vector<int>mxi;
        long long ans = 0;
        vector<long long>prefgcd;
        long long n = nums.size();
        for(int i=0;i<n;i++)
        {
            mx = max(mx,nums[i]);
            mxi.push_back(mx);
        }
        for(int i=0;i<n;i++)
        {
            long long num = gcd(nums[i],mxi[i]);
            prefgcd.push_back(num);
        }
        sort(prefgcd.begin(),prefgcd.end());
        
        long long i=0;
        long long j=n-1;
        while(i<j)
        {
            long long val = gcd(prefgcd[i],prefgcd[j]);
            ans += val;
            i++;
            j--;
        }
        return ans;
    }
};