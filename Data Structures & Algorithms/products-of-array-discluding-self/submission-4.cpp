class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct {1};
        int zeroNum {0};
        for (int item : nums){
            if (item)
                totalProduct *= item;
            else
                ++zeroNum;
        }
        vector<int> out;
        out.reserve(nums.size());
        if (zeroNum >= 2){
            for (int i {0}; i < nums.size(); ++i){
                out.push_back(0);
            }
        } else{
            for (int item : nums){
                if (item != 0){
                    out.push_back(-totalProduct*(zeroNum-1)/item);
                }
                else {
                    out.push_back(totalProduct);
                }
            }
        }
        return out;
    }

};
