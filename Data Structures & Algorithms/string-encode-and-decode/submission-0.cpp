class Solution {
public:

    string encode(vector<string>& strs) {
        string out{};
        char unitSeparator = 31;
        for (string& item : strs) {
            out.append(item);
            out.push_back(unitSeparator);
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> out;
        char unitSeparator = 31;
        for (int i{ 0 }; i < s.size();) {
            string temp{};
            char* startOfString{ &s[i] };
            char* endOfString;
            do {
                endOfString = &s[i];
                ++i;
            } while (*endOfString != unitSeparator);
            temp.append(startOfString, endOfString);
            out.push_back(temp);
        }
        return out;
    }
};
