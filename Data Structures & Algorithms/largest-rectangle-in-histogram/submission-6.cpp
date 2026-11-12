using namespace std;
class Solution {
public:
    int calcArea(int height, int end, int start) {
        int width = end - start;
        return height * width;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int,int>> stack;
        stack.push_back({ 0,heights[0]});
        int largest{ 0 };
        for (int i{ 1 }; i < heights.size(); ++i) {
            if (heights[i] == heights[i - 1]) continue;
            int last_pop_index{ i };
            while (!stack.empty() && heights[i] <= stack.back().second) {
                int temp{ calcArea(stack.back().second, i, stack.back().first)};
                largest = largest > temp ? largest : temp;
                last_pop_index = stack.back().first;
                stack.pop_back();
            }
            stack.push_back({ last_pop_index, heights[i] });
        }
        for (auto& item : stack) {
            int temp{ calcArea(item.second, heights.size(), item.first)};
            largest = largest > temp ? largest : temp;
        }
        return largest;
    }
};