class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l{ 0 };
        int r{ static_cast<int>(nums.size()) };
        int outer{ nums[r - 1] };
        int cur{ 0 };
        while (l < r) {
            cur = (r - l) / 2 + l;
            if (nums[cur] > outer) {
                l = cur + 1;
            }
            else {
                r = cur;
            }
        }
        //within red
        if (target <= outer) {
            r = nums.size() - 1;
        }
        //within orange
        else if (target >= nums[0]) {
            r = l-1;
            l = 0;
        }
        //find target
        while (l < r) {
            cur = (r - l) / 2 + l;
            if (target > nums[cur]) {
                l = cur + 1;
            }
            else {
                r = cur;
            }
        }


    return nums[l] == target ? l : -1;
    }
};