class Solution {
public:
    int findMin(vector<int>& nums) {
        int l{ 0 };
        int r{ static_cast<int>(nums.size()) };
        if (nums[0] < nums[r - 1]) return nums[0];
        int outer = nums[r - 1];
        int cur{0};
        while (l < r) {
            cur = (r - l) / 2 + l;
            if (outer >= nums[cur]) {
                r = cur;
            }
            else if (outer < nums[cur]) {
                l = cur + 1;
            }
        }
        return nums[l];
    }
};
