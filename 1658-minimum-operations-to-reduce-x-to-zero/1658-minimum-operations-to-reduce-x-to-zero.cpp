class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left=0;
        int right=0;
        int n = nums.size();
       int sum = accumulate(nums.begin(), nums.end(), 0);
       int ans = INT_MAX;
       if (sum < x) return -1; 
        if(sum == x) return n;
        while(right<n)
        {
            sum -=nums[right];

            if(sum<=x)
            {
              while(left <= right && sum<x)
              {
                sum+=nums[left];
                left++;
              }
              if(sum == x) 
              {
                ans = min(ans, n - ((right-left)+1));
              }
            }
            right++;
        }
       return (ans == INT_MAX) ? -1 : ans;
    }
};