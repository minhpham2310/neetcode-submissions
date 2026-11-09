class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int item : nums) {
            ++frequencyMap[item];
        }
        std::vector<vector<int>> bucket(nums.size()+1);
        for (auto [key, item] : frequencyMap) {
            bucket[item].push_back(key);
        }
        vector<int> outTest;
        for (auto& item : bucket) {
            outTest.insert(outTest.end(), item.begin(), item.end());
        }
        outTest.erase(outTest.begin(), outTest.end() - k);
        return outTest;
    }
};
