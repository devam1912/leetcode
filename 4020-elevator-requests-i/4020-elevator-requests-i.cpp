class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int sum = requests[0];
        int s = requests.size();
        for(int i=1;i<s;i++)
        {
            sum+=abs(requests[i]-requests[i-1]);
        }
        return sum;
    }
};