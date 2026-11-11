using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        char* left{ &s[0] };
        char* right{ &s[s.size() - 1] };
        if (s.empty()) return true;
        while (left < right) {
            if (ispunct(*left) || *left == ' '){
                ++left;
                continue;
            }
            if (ispunct(*right) || *right == ' '){
                --right;
                continue;
            }
            if (tolower(*left) != tolower(*right)) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};