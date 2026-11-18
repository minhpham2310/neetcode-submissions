using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l{ 0 };
        int r{ static_cast<int>(nums.size()) };
        int cur{ 0 };
        while (((r - l) / 2 + l) != cur) {
            cur = (r - l) / 2 + l;
            if (nums[cur] == target) {
                return cur;
            }
            else if (target > nums[cur]) {
                l = cur;
            }
            else {
                r = cur;
            }
        }
        return target == nums[cur] ? cur : -1;
    }
};