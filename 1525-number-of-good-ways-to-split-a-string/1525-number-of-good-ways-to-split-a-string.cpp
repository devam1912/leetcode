class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int>freqall;
        unordered_map<char,int>freqleft;
        int n = s.size();
        int counter=0;
        for(int i=0;i<n;i++)
        {
            freqall[s[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            freqleft[s[i]]++;
            freqall[s[i]]--;
            if(freqall[s[i]]==0) freqall.erase(s[i]);
            if(freqleft.size()==freqall.size()) counter++;
        }
        return counter;
    }
};