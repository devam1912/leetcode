class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp; // value -> index

    RandomizedSet() {

    }

    bool insert(int val) {

        // Already exists
        if (mp.count(val))
            return false;

        nums.push_back(val);
        mp[val] = nums.size() - 1;

        return true;
    }

    bool remove(int val) {

        // Doesn't exist
        if (!mp.count(val))
            return false;

        int index = mp[val];
        int lastElement = nums.back();

        // Move last element to removed element's position
        nums[index] = lastElement;

        // Update moved element's index
        mp[lastElement] = index;

        // Remove last element
        nums.pop_back();

        // Remove from map
        mp.erase(val);

        return true;
    }

    int getRandom() {

        int index = rand() % nums.size();

        return nums[index];
    }
};