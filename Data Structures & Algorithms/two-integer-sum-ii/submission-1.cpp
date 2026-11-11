using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int* left{ &numbers[0] };
        int* right{ &numbers[numbers.size() - 1] };
        while (left < right) {
            if (*left + *right > target) {
                --right;
            }
            else if (*left + *right < target) {
                ++left;
            }
            else {
                return { static_cast<int>(left - &numbers[0]) + 1, static_cast<int>(right - &numbers[0]) + 1 };
            }
        }
        return {};
    }
};