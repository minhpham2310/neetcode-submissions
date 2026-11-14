using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, pair<int,int>> letterMap;
        if (s.empty()) return 0;
        int startCurrent{ 0 };
        int endCurrent{ 0 };
        int length { 1 };
        for (int i{ 0 }; i < s.size(); ++i) {
            if (++letterMap[s[i]].second > 1) {
                for (char let : s.substr(startCurrent, letterMap[s[i]].first - startCurrent)) {
                    letterMap[let].second = 0;
                }
                int thisLength = i - startCurrent;
                length = length > thisLength ? length : thisLength;
                startCurrent = letterMap[s[i]].first+1;
                letterMap[s[i]].second = 1;
            }
            else {
                endCurrent = i+1;
            }
            letterMap[s[i]].first = i;
        }
        int xx = endCurrent - startCurrent;
        int yy = length;
        if (endCurrent - startCurrent > length) {
            length = endCurrent - startCurrent;
        }
        return length;
    }
};