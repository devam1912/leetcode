class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int sum=0;
        int k=0;
        int n = cost.size();
        for(int i=0;i<n;i++)
        {
            k++;
            if(k==3)
            {
                k=0;
            }
            else
            {
                sum+=cost[i];
            }
        }
        return sum;
    }
};