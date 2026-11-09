class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, int> anagramMap;     // key -> index into out
        vector<vector<string>> out;
        for (auto& item : strs) {
            array<int, 26> temp{};
            for (char c : item) {
                ++temp[c - 'a'];
            }
            auto [it, inserted] = anagramMap.try_emplace(temp, out.size());
            if (inserted) out.emplace_back();    // first time seeing this key: new group
            out[it->second].push_back(item);
        }
        return out;
    }
};
