class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> stk;
        stk.push({"", 1});
        int times = 0;

        for(auto c : s) {
            if (isdigit(c)) {
                times = (times * 10) + (c - '0');
            }
            else if (c == '[') {
                stk.push({"", times});
                times = 0;
            }
            else if (c == ']') {
                int repeat = stk.top().second;
                string str = stk.top().first;
                stk.pop();
                while(repeat--) {
                    stk.top().first += str;
                }
            }
            else {
                stk.top().first.push_back(c);
            }
        }

        return stk.top().first;
    }
};