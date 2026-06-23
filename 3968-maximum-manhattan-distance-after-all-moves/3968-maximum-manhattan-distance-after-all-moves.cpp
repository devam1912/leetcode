class Solution {
public:
    int maxDistance(string moves) {
        int l = 0, r = 0, u = 0, d = 0, us = 0;

        for (char c : moves) {
            if (c == 'L') l++;
            else if (c == 'R') r++;
            else if (c == 'U') u++;
            else if (c == 'D') d++;
            else us++;  
        }

        return abs(r - l) + abs(u - d) + us;
    }
};