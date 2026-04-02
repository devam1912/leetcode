class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int n = nums.size();
       int left = 0;
       int right = 0;
       int maxi = INT_MIN;
       int counter=0;
       while(right<n)
       {
        if(nums[right]==0) counter++;
        if(counter > k)
        {
            
            while(counter>k)
            {
                if(nums[left]==0) counter--;
                left++;
            }
        }
        maxi = max(maxi,(right-left)+1);
            right++;
       } 
       return maxi;
    }
};