class Solution {
public:
    int calculateVolume(const int* start, const int* end) {
        int areaOut{ 0 };
        int height = *start > *end ? *end : *start;
        while (++start != end) {
            areaOut += height - *start;
        }
        return areaOut;
    }
    int trap(vector<int>& height) {
        int max = max_element(height.begin(), height.end())- height.begin();
        //right iterate
        vector<pair<int, int>> stack{};
        stack.push_back({max, height[max] });
        for (int i{ max+1 }; i < height.size(); ++i) {
            while (!stack.empty() && height[i] > height[stack.back().first]) {
                stack.pop_back();
            }
            stack.push_back({ i, height[i] });
        }
        int volume{ 0 };
        for (int i{ static_cast<int>(stack.size() - 1) }; i > 0; --i) {
            volume += calculateVolume(&height[stack[i - 1].first], &height[stack[i].first]);
            stack.pop_back();
        }

        for (int i{ max - 1 }; i >= 0; --i) {
            while (!stack.empty() && height[i] > height[stack.back().first]) {
                stack.pop_back();
            }
            stack.push_back({ i, height[i] });
        }
        for (int i{ static_cast<int>(stack.size() - 1) }; i > 0; --i) {
            volume += calculateVolume(&height[stack[i].first], &height[stack[i-1].first]);
            stack.pop_back();
        }

        return volume;
    }
};