class Solution {
public:
    int reverse(int n)
    {
        int ans=0;
        while(n>0)
        {
            int rem = n%10;
            ans=(ans*10)+rem;
            n/=10; 
        }
        return ans;
    }

  int countprime(int s, int e)
{
    int sum = 0;

    for(int i = s; i <= e; i++)
    {
        if(i < 2) continue;

        bool prime = true;

        for(int j = 2; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                prime = false;
                break;
            }
        }

        if(prime)
            sum += i;
    }
    return sum;
}

    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);
        int mini = min(rev,n);
        int maxi = max(rev,n);
        int p = countprime(mini,maxi);
        return p;
    }
};