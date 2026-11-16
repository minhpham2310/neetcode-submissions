class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //edgecases
        if (k >= nums.size()) {
            return { *max_element(nums.begin(),nums.end()) };
        }

        //initialize window 
        bool (*comp)(pair<int,int>, pair<int, int>) = [](pair<int, int> a, pair<int, int> b) {return a.first < b.first;};

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> maxQueue(comp);

        for (int l = 0, r = 0;r < l + k; ++r) {
            maxQueue.push({ nums[r], r });
        }

        //solution
        vector<int> out{maxQueue.top().first};
        for (int l = 1, r = l+k-1; r < nums.size(); ++r, ++l) {
            while (!maxQueue.empty() && maxQueue.top().second < l) {
                maxQueue.pop();
            }
            maxQueue.push({ nums[r], r });
            out.push_back(maxQueue.top().first);
        }
        return out;
    }
};
