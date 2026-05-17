class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
       int n = s.size();
       int checker;
       for(int i=1;i<n;i++)
       {
            checker = abs((s[i]-'0')-(s[i-1]-'0'));
            if(checker>2) return false;
       } 
       return true;
    }
};