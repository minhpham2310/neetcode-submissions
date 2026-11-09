class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> anagramMap;
        for (auto& item : strs) {
            array<int, 26> temp{0};
            for (char c : item) {
                c = tolower(c);
                ++temp[static_cast<size_t>(c) - 97];
            }
            anagramMap[temp].push_back(item);
        }
        vector<vector<string>> out;
        for (auto& [key, item] : anagramMap) {
            out.push_back(move(item));
        }
        return out;
    }
};
