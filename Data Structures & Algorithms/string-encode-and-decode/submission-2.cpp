class Solution {
public:

    string encode(vector<string>& strs) {
        string out{};
        char unitSeparator = 31;
        for (string& item : strs) {
            out.append(to_string(item.size()));
            out.push_back(unitSeparator);
            out.append(item);
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> out;
        char unitSeparator = 31;
        for (int i{ 0 }; i < s.size();) {
            char* startOfPayload{ &s[i] };
            char* endOfPayload;
            do {
                endOfPayload = &s[i];
                ++i;
            } while (*endOfPayload != unitSeparator);
            int strLength{ stoi(string{startOfPayload,endOfPayload}) };
            i += strLength;
            out.emplace_back(string{endOfPayload+1, endOfPayload+1+strLength});
        }
        return out;
    }
};
