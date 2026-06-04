class Solution {
public:
int wavy(int n)
{
    if(n < 100) return 0;

    vector<int> store;

    while(n > 0)
    {
        store.push_back(n % 10);
        n /= 10;
    }

    int ans = 0;

    for(int i = 1; i < store.size() - 1; i++)
    {
        bool peak =
            store[i] > store[i-1] &&
            store[i] > store[i+1];

        bool valley =
            store[i] < store[i-1] &&
            store[i] < store[i+1];

        if(peak || valley)
            ans++;
    }

    return ans;
}
    int totalWaviness(int num1, int num2) {
       int ans=0;
        for(int i=num1;i<=num2;i++)
        {
            int wave = wavy(i);
             ans+=wave;
        }   
        return ans;
    }
};