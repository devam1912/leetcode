class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        
        int sp = 0;                    
        int n = spaces.size();         

        for (int i = 0; i < s.length(); i++) {

            // check boundary FIRST
            if (sp < n && i == spaces[sp]) {
                ans += ' ';
                sp++;
            }

            ans += s[i];
        }

        return ans;
    }
};