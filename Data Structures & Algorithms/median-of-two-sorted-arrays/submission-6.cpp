class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int totalSize = static_cast<int>(nums1.size() + nums2.size());
        int half = totalSize / 2;
        int l1{ 0 };
        int r1 = static_cast<int>(nums1.size()) - 1;
        while (true) {
            int median1 = floor((l1 + r1) / 2.0);
            int median2 = half - median1 - 2;
            
            int n1l, n1r, n2l, n2r;

            if (median1 >= 0) n1l = nums1[median1]; else n1l = numeric_limits<int>::lowest();
            if (median1 + 1 < static_cast<int>(nums1.size())) n1r = nums1[median1 + 1]; else n1r = numeric_limits<int>::max();
            if (median2 >= 0) n2l = nums2[median2]; else n2l = numeric_limits<int>::lowest();
            if (median2 + 1 < static_cast<int>(nums2.size())) n2r = nums2[median2 + 1]; else n2r = numeric_limits<int>::max();
            if (n1l <= n2r && n2l <= n1r) {
                if (totalSize % 2) {
                    return min(n1r, n2r);
                }
                return (static_cast<double>(max(n1l, n2l)) + static_cast<double>(min(n1r, n2r))) / 2;
            }
            else if (n1l > n2r)
                r1 = median1 - 1;
            else
                l1 = median1 + 1;
        }

    }
};