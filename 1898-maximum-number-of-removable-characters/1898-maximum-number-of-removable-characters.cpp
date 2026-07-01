class Solution {
public:

    bool check(string &s, string &p, vector<int> &removable, int k)
    {
        vector<bool> removed(s.size(), false);

        for(int i = 0; i < k; i++)
        {
            removed[removable[i]] = true;
        }

        int j = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(removed[i])
                continue;

            if(j < p.size() && s[i] == p[j])
                j++;
        }

        return j == p.size();
    }

    int maximumRemovals(string s, string p, vector<int>& removable)
    {
        int low = 0;
        int high = removable.size();
        int ans = 0;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(check(s, p, removable, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};