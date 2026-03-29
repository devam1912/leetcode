class Solution {
public:
    bool canBeEqual(string s1, string s2) {
     for(int i=0;i<4;i++)
     {
        if(s1[i]==s2[i])continue;
        if(i==0 || i==1)
        {
            if(s1[i]!=s2[i+2] || s2[i]!=s1[i+2]) return false;
        }
        else
        {
            if(s1[i]!=s2[i-2] || s2[i]!=s1[i-2]) return false;
        }
     }
     return true;
     
      
    }
};