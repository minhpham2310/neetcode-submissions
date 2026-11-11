using namespace std;
class Solution {
public:
    int calculateArea(int* left, int* right) {
        int height = *left < *right ? *left : *right;
        return (right - left) * height;
    }
    int maxArea(vector<int>& heights) {
        int* maxColumnHeight = &*max_element(heights.begin(), heights.end());
        int* left{ &heights[0] };
        int* right{ &heights[heights.size() - 1] };
        int out{ 0 };
        for (;right >= maxColumnHeight; --right) {
            left = &heights[0];
            while (left <= maxColumnHeight) {
                int temp{ calculateArea(left, right) };
                out = out > temp ? out : temp;
                ++left;
            }
        }
        return out;
    }
};