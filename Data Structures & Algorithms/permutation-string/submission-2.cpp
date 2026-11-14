using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        array<int, 26> s1letters{};
        for (char letter : s1) {
            ++s1letters[letter - 'a'];
        }
        array<int, 26> s2letters{};
        char* right{ &s2[0] };
        char* left{ right - 1 };
        while (right - left <= static_cast<int>(s1.size()) && right != &s2[s2.size()]) {
            int cur{ *right - 'a' };
            ++s2letters[cur];
            while (s2letters[cur] > s1letters[cur]) {
                ++left;
                --s2letters[*left - 'a'];
            }
            ++right;
        }
        for (size_t i{ 0 }; i < 26; ++i) {
            if (s1letters[i] != s2letters[i])
                return false;
        }
        return true;
    }
};