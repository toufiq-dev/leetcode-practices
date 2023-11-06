class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto prefix = strs[0];
        
        for (auto &str : strs) {
            int i = 0;
            while (i < prefix.size() && i < str.size() && prefix[i] == str[i]) {
                i++;
            }
            prefix = prefix.substr(0, i); // Extract the common prefix.
            if (prefix.empty()) {
                break; // No common prefix, no need to check further.
            }
        }
        
        return prefix;
    }
};
