class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tChar;
        if (t.size() > s.size()) return "";
        for (char letter : t) {
            ++tChar[letter];
        }
        char* right{ &s[0] };
        char* left{ right - 1 };
        unordered_map<char, int> sChar = tChar;

        //initialize our window
        while (right < &s[s.size()]) {
            if (sChar.count(*right)) {
                if (sChar[*right] > 0)
                    --sChar[*right];
                if (sChar[*right]==0)
                    sChar.erase(*right);
            }
            if (sChar.empty())
                break;
            ++right;
        }
        if (right == &s[s.size()] && !sChar.empty()) return "";

        while (!tChar.count(*(left + 1))) {
            ++left;
        }

        for (char* i{ left+1 }; i <= right; ++i) {
            if (tChar.count(*i)) {
                ++sChar[*i];
            }
        }

        char trackedLetter {*(left+1)};
        pair<char*, char*> strOut{ left+1, right+1 };
        //solve the problem
        while (right < &s[s.size()]) {
            if (sChar[trackedLetter] >= tChar[trackedLetter]) {
                ++left;
                if (sChar.count(*left)) {
                    if (strOut.second - strOut.first > (right+1 - left)) {
                        strOut.first = left;
                        strOut.second = right+1;
                    }
                    --sChar[*left];
                    trackedLetter = *left;
                }
            }
            else {
                ++right;
                if (sChar.count(*right)) {
                    ++sChar[*right];

                }
            }
        }

        return { string {strOut.first, strOut.second} };
    }
};