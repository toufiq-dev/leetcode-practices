class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto &c : s) {
            if(c == '(' || c == '{' || c == '[') stk.push(c);
            else {
                if(stk.empty()) return false;
                auto top = stk.top();
                stk.pop();
                if((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
                    return false;
            }
        }

        return stk.empty();
    }
};