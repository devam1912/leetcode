class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> freq;
        string ans = "";


        for (char c : s) {
            freq[c]++;
        }

        for (char c : order) {
            if (freq.count(c)) {
                ans.append(freq[c], c);  
                freq[c] = 0;             
            }
        }

        for (auto &it : freq) {
            if (it.second > 0) {
                ans.append(it.second, it.first);
            }
        }

        return ans;
    }
};