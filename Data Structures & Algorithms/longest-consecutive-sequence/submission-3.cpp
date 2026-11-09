class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_map<int, int> consecutiveMap;
        vector<int> temp;
        temp.reserve(nums.size());
        for (int item : nums) {
            if (consecutiveMap[item] == 0) {
                consecutiveMap[item] = 1;
                temp.push_back(item);
            }
        }
        vector<int> consecutives;
        for (int item : temp) {
            if (consecutiveMap[item - 1] && consecutiveMap[item + 1]) {
                consecutiveMap[item] = 2;
            }
            else if (consecutiveMap[item - 1]) {
                consecutiveMap[item] = -1;
                consecutives.push_back(item);
            }
            else if (consecutiveMap[item + 1]) {
                consecutiveMap[item] = 1;
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
