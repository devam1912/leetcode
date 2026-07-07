class Solution {
public:
    long long sumAndMultiply(int n) {
        long long place=1;
        long long sum=0;
        long long filter=0;
        while(n>0)
        {
            int  rem= n%10;
             n = n/10;

             if(rem!=0)
             {
                 filter += rem*place;
                place*=10;
                sum+= rem;
             } 
            
        }
        long long ans = sum*filter;
        return ans;
    
    }
};