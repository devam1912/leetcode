class Solution {
public:
    int passwordStrength(string password) {
        set<char> s;
        int ans = 0;

        for(char ch : password) {
            s.insert(ch);
        }

        for(char ch : s) {
            if(ch >= 'a' && ch <= 'z') ans += 1;
            else if(ch >= 'A' && ch <= 'Z') ans += 2;
            else if(ch >= '0' && ch <= '9') ans += 3;
            else ans += 5;
        }

        return ans;
    }
};