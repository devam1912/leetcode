class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        int n = prices.size();
        int m = discounts.size();
        int i=0;
        int j=0;
        double ans = 0;
        while(i<n && j<m)
        {
            double dis = 100-discounts[j];
            double num = prices[i]*dis;
            ans+= num/100;
            i++;
            j++;
        }
        for(int l =i;l<n;l++)
        {
            ans+=prices[l];
        }
        return ans;
    }
};