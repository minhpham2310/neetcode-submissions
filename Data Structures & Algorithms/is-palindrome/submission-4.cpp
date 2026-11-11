using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        for (size_t i{ 0 }; i < s.size(); ++i) {
            if (ispunct(s[i]) || s[i] == ' ') {
                s.erase(i, 1);
                --i;
            }
        }
        char* left{ &s[0] };
        char* right{ &s[s.size() - 1] };
        if (s.empty()) return true;
        while (left < right) {
            if (tolower(*left) != tolower(*right)) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};