using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, pair<int,int>> letterMap;
        string outSeq{};
        int startCurrent{ 0 };
        int endCurrent{ 0 };
        for (int i{ 0 }; i < s.size(); ++i) {
            if (++letterMap[s[i]].second > 1) {
                if (outSeq.size() <= i - startCurrent) {
                    outSeq = s.substr(startCurrent, i - startCurrent);
                }
                for (char let : s.substr(startCurrent, letterMap[s[i]].first - startCurrent)) {
                    letterMap[let].second = 0;
                }
                startCurrent = letterMap[s[i]].first+1;
                letterMap[s[i]].second = 1;
            }
            else {
                endCurrent = i+1;
            }
            letterMap[s[i]].first = i;
        }
        int xx = endCurrent - startCurrent;
        int yy = outSeq.size();
        if (xx > yy) {
            outSeq = s.substr(startCurrent, s.size()-startCurrent);
        }
        return outSeq.size();
    }
};