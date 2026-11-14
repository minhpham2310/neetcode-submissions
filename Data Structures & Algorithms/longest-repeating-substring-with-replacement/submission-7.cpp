class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map <char, int> frequency;
        int length{ 0 };
        int beginWindow{ 0 };
        int remainder{ 0 };
        char trackedLetter{ s[0] };
        frequency[trackedLetter] = 1;
        int i{ 0 };
        while (true) {
            int window{ i+1 - beginWindow };
            if (window - frequency[trackedLetter] > k) {
                length = length > window-1 ? length : window-1;
                while (s[beginWindow] == trackedLetter) {
                    --frequency[trackedLetter];
                    ++beginWindow;
                }
                trackedLetter = s[beginWindow];
                remainder = 0;
            }
            else if (i < s.size()){
                ++i;
                ++frequency[s[i]];
            }
            else {
                int temp = (*max_element(frequency.begin(), frequency.end(), [](const auto& a, const auto& b) {
                    return a.second < b.second;
                    })).second;
                length = length > temp + k ? length : temp + k;
                length = min(length, static_cast<int>(s.size()));
                break;
            }
        }
        return length;
    }
};