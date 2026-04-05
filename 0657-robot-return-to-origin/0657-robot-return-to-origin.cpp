class Solution {
public:
    bool judgeCircle(string moves) {
      int cl=0;
      int cu=0;
      int cr=0;
      int cd=0;
      for(char m : moves)
      {
        if(m=='L')cl++;
        if(m=='R')cr++;
        if(m=='U')cu++;
        if(m=='D')cd++;
      }
      if(cl != cr) return false;
      if(cu != cd) return false;
      return true;
    }
};