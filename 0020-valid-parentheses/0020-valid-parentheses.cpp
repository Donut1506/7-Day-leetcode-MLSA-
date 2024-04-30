class Solution {
public:
    bool isValid(string s)
    {
         stack<char> parentheses;
        unordered_map<char, char> mapping = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        
        for (char bracket : s) {
            if (bracket == ')' || bracket == '}' || bracket == ']') {
                if (parentheses.empty() || mapping[parentheses.top()] != bracket) {
                    return false;
                }
                parentheses.pop();
            } else {
                parentheses.push(bracket);
            }
        }
        
        return parentheses.empty();
    }
};