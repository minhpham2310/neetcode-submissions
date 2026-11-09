class Solution {
public:
    bool validClose(char openingParenthesis, char closingParenthesis) {
        switch (openingParenthesis) {
        case '{':
            return closingParenthesis == '}';
        case '[':
            return closingParenthesis == ']';
        case '(':
            return closingParenthesis == ')';
        default:
            return false;
        }
    }

    bool isValid(string s) {
        vector<char> parenthesesStack;
        for (char item : s) {
            if (item != '(' && item != '[' && item != '{') {
                if (parenthesesStack.empty()) {
                    return false;
                }
                else if (!validClose(parenthesesStack.back(), item))
                    return false;
                parenthesesStack.pop_back();
            }
            else {
                parenthesesStack.push_back(item);
            }
        }
        if (!parenthesesStack.empty())
            return false;
        return true;
    }
};
