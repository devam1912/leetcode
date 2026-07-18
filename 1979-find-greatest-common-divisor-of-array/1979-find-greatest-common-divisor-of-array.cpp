class Solution {
public:
    int findGCD(vector<int>& nums) {
     int small = INT_MAX;
     int big = INT_MIN;
     int n= nums.size();
     for(int i=0;i<n;i++)
     {
        small = min(small,nums[i]);
        big = max(big,nums[i]);
     }   
     return gcd(small,big);
    }
};