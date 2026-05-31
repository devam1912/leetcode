class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long sum = mass;

        for (int asteroid : asteroids) {
            if (sum < asteroid)
                return false;

            sum += asteroid;
        }
        return true;
    }
};