using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        for (int* current{ &nums[0] }; current < &nums[nums.size() - 2];) {
            int* left = current + 1;
            int* right = &nums[nums.size() - 1];
            while (left < right) {
                if (*left + *right < -*current) {
                    ++left;
                }
                else if (*left + *right > -*current) {
                    --right;
                }
                else {
                    out.push_back({ *current, *left, *right });
                    do {
                        ++left;
                    } while (left < right && *(left - 1) == *left);
                    do {
                        --right;
                    } while (left < right && *(right + 1) == *right);
                }
            }
            do {
                ++current;
            } while (current < right && *(current - 1) == *current);
        }
        return out;
    }
};

