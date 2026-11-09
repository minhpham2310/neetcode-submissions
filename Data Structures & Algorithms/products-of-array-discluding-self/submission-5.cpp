class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct(nums.size());
        prefixProduct[0] = 1; 
        for (size_t i{ 1 }; i < nums.size(); ++i) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
        }
        vector<int> suffixProduct (nums.size());
        suffixProduct[nums.size() - 1] = 1;
        for (int i{ static_cast<int>(nums.size() - 2) }; i >= 0; --i) {
            suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
        }
        vector<int> out(nums.size());
        for (size_t i{ 0 }; i < out.size(); ++i) {
            out[i] = prefixProduct[i] * suffixProduct[i];
        }
        return out;
    }

};
