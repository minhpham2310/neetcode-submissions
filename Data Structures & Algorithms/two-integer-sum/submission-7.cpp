using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> out(nums.size());
        for (int i{ 0 }; i < static_cast<int>(nums.size()); ++i) {
            out[i].first = i;
            out[i].second = nums[i];
        }
        std::sort(out.begin(), out.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
            });
        std::pair<int, int>* left{ &out[0] };
        std::pair<int, int>* right{ &out[out.size() - 1] };
        while (left < right) {
            if (left->second + right->second < target) {
                ++left;
            }
            else if (left->second + right->second > target) {
                --right;
            }
            else {
                break;
            }
        }
        if (left->first < right->first)
            return {left->first, right->first};
        else 
            return {right->first, left->first};

    }
};
