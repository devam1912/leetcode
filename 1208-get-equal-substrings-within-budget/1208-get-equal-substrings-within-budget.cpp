class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left =0;
        int n = s.size();
        int right=0;
        int dif=0;
        int ans = INT_MIN;
        int length;
        while(right<n)
        {
            if(s[right]!=t[right])
            {
                dif+=abs((s[right]-'a')-(t[right]-'a'));
            }
            if(dif>maxCost)
            {
                while(dif>maxCost && left<n)
                {
                    dif-=abs((s[left]-'a')-(t[left]-'a'));
                    left++;
                }
            }
            length= right-left+1;
            ans = max(ans,length);
            right++;
        }
        return ans;
    }
};