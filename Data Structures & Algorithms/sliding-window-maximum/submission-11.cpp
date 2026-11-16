class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //edgecases
        if (k >= nums.size()) {
            return { *max_element(nums.begin(),nums.end()) };
        }

        //init window
        deque < pair<int, int>> minMaxQueue{ {nums[0], 0} };
        for (int i{ 1 }; i < k; ++i) {
            if (nums[i] > minMaxQueue.front().first) {
                minMaxQueue.push_front({ nums[i], i });
            }
            else {
                while (!minMaxQueue.empty() && nums[i] >= minMaxQueue.back().first) {
                    minMaxQueue.pop_back();
                }
                minMaxQueue.push_back({ nums[i],i });
            }
        }

        //solve
        vector<int> out{minMaxQueue.front().first};
        for (int l = 1, r = k; r < nums.size(); ++r, ++l) {
            while (!minMaxQueue.empty() && minMaxQueue.front().second < l)
                minMaxQueue.pop_front();
            while (!minMaxQueue.empty() && nums[r] >= minMaxQueue.back().first) {
                minMaxQueue.pop_back();
            }
            minMaxQueue.push_back({ nums[r],r });
            out.push_back(minMaxQueue.front().first);
        }
        return out;
    }
};