class Solution {
public:
    int calcVol(int prefix, int suffix, int height) {
        int tempVol{ min(prefix, suffix) - height };
        return tempVol > 0 ? tempVol : 0;
    }
    int trap(vector<int>& height) {
        int* left{ &height[0] };
        int* right{ left+2 };
        int max{ height[0]};
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());
        for (int i{ 1 }; i < (height.size() - 1); ++i) {
            prefix[i] = max;
            max = height[i] > max ? height[i] : max;
        }
        max = *(height.end() - 1);
        for (int i{ static_cast<int>(height.size()) - 2 }; i >= 1; --i) {
            suffix[i] = max;
            max = height[i] > max ? height[i] : max;
        }
        int volOut{ 0 };
        for (size_t i{ 1 }; i < height.size()-1; ++i) {
            volOut += calcVol(prefix[i], suffix[i], height[i]);
        }

        return volOut;
    }
};
