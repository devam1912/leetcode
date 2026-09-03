class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int mini = INT_MAX;   
        bool odd = false;     

  
        for(auto t : nums1){
            if(t % 2){                
                odd = true;            
                mini = min(mini, t);   
            }
        }

        if(!odd) return true;

        //  Try to convert all EVEN numbers to ODD
        // Using: even - odd = odd
        // BUT condition: nums1[j] < nums1[i] → odd must be smaller than even

        for(int t : nums1){
            
            // If current number is EVEN
            // and smallest odd is greater than this even
            if(t % 2 == 0 && mini > t)
                return false;
                /*
                Explanation:
                We want to do: t - mini (to make it odd)

                But condition requires:
                mini < t

                If mini > t:
                - No smaller odd exists
                - Can't perform subtraction
                - Can't convert this even → odd
                - So impossible
                */
        }

        // Step 4: If all evens can be converted → success
        return true;
    }
};