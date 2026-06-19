class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum = sum + gain[i];
            maxi = max(maxi, sum);
        }
        if(maxi<0) return 0;
        return maxi;
    }
};