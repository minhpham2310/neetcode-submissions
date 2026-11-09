using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int item : nums) {
            ++map[item];
        }
        std::vector<int> out;
        bool found{ false };
        out.reserve(2);
        for (size_t i{ 0 }; i < nums.size(); ++i) {
            if (map[target - nums[i]] && (map[target - nums[i]] == 2 || target - nums[i] != nums[i])) {
                out.push_back(i);
            }
        }
        return out;
    }
};
