class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>freq;
        int ans=0;
        while(n>0)
        {
            int rem = n%10;
            freq[rem]++;
            n/=10;
        }
    for (auto &[num, count] : freq)
        {
            ans += num * count;
        }
        return ans;
    }
};