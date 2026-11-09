class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> stack;
        vector<int> continuous(heights.size());
        for (size_t i{ 0 }; i < heights.size(); ++i) {
            while (!stack.empty() && heights[i] < heights[stack.back()]) {
                continuous[stack.back()] = i - stack.back();

                stack.pop_back();
            }
            stack.push_back(i);
        }
        stack.clear();
        vector<int> continuous2(heights.size());
        for (int i{ static_cast<int>(continuous.size()) - 1 }; i >= 0; --i) {
            if (continuous[i] == 0) continuous[i] = continuous.size() - i;
            while (!stack.empty() && heights[i] < heights[stack.back()]) {
                continuous2[stack.back()] = stack.back()-i;

                stack.pop_back();
            }
            stack.push_back(i);
        }
        int bestArea{ 0 };
        for (size_t i{ 0 }; i < continuous.size(); ++i) {
            if (continuous2[i] == 0) continuous2[i] = (i-0);
            else --continuous2[i];
            int width{ continuous2[i] + continuous[i] };
            int area{ width * heights[i] };
            bestArea = area > bestArea ? area : bestArea;
        }
        return bestArea;
    }
};