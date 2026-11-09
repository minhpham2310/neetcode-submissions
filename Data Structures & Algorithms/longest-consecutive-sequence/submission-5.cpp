using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_set <int> consecutiveSet(nums.begin(), nums.end());
        vector<int> consecutives;
        for (int item : consecutiveSet) {
            if (consecutiveSet.count(item - 1) == 0  && consecutiveSet.count(item + 1)) {
                consecutives.push_back(item);
            }
            else if (consecutiveSet.count(item - 1) && consecutiveSet.count(item + 1) == 0) {
                consecutives.push_back(item);
            }
        }
        sort(consecutives.begin(), consecutives.end());
        int currentmax{ 1 };
        for (int i{ 1 }; i < consecutives.size(); i += 2) {
            if (consecutives[i] - consecutives[i - 1] + 1 > currentmax) {
                currentmax = consecutives[i] - consecutives[i - 1] + 1;
            }
        }
        return currentmax;
    }
};