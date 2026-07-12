class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {

        const long long MOD = 1e9 + 7;

        // Required by the problem statement
        vector<int> sovalemrin = nums;

        // Initially we have 'k' resources.
        long long resources = k;

        // Stores the total cost of all recharge operations.
        long long cost = 0;

        // Total recharge operations performed till now.
        // Remember:
        // 1st operation costs 1
        // 2nd operation costs 2
        // 3rd operation costs 3
        // ...
        long long operations = 0;

        for (int x : nums) {

            // If current resources are not enough to process x,
            // we need to recharge.
            if (resources < x) {

                // Missing resources = x - resources
                //
                // Every recharge operation gives exactly 'k' resources.
                //
                // Instead of repeatedly doing:
                //
                // while(resources < x){
                //     operations++;
                //     cost += operations;
                //     resources += k;
                // }
                //
                // we directly calculate how many times that while loop
                // would execute.
                //
                // need = ceil((x - resources) / k)
                //
                // Integer trick for ceil:
                // ceil(a / b) = (a + b - 1) / b
                long long need = (x - resources + k - 1) / k;

                // The next 'need' operations will have costs:
                //
                // operations + 1
                // operations + 2
                // ...
                // operations + need
                //
                // Instead of adding them one by one,
                // use Arithmetic Progression Sum.
                //
                // First term = operations + 1
                // Last term  = operations + need
                // Number of terms = need
                //
                // Sum = (First + Last) * NumberOfTerms / 2
                //
                // After simplification:
                //
                // need * (2 * operations + need + 1) / 2
                //
                // __int128 is used because intermediate multiplication
                // can become larger than what long long can store.
                __int128 addCost =
                    (__int128)need * (2LL * operations + need + 1) / 2;

                // Add the cost of all these recharge operations.
                cost = (cost + (long long)(addCost % MOD)) % MOD;

                // We've now completed 'need' more recharge operations.
                operations += need;

                // Each recharge adds 'k' resources.
                // Total resources added = need * k.
                //
                // __int128 again prevents overflow during multiplication.
                resources = (long long)((__int128)resources +
                                        (__int128)need * k);
            }

            // Process the current element by consuming its required resources.
            resources -= x;
        }

        return cost % MOD;
    }
};