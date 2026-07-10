class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();

        vector<int> extra;
        for(int i = n; i > 0; i--)
            extra.push_back(i);

        for(int i = 0; i < n; i++)
        {
            if(citations[i] >= extra[i])
                return extra[i];
        }

        return 0;
    }
};