class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;
        if (s.size() != t.size())
            return false;
        for (size_t i{ 0 }; i < s.size(); ++i) {
            ++mapS[s[i]];
            ++mapT[t[i]];
        }
        for (char item : s) {
            if (mapS[item] != mapT[item])
                return false;
        }
        return true;
    }
};
