class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string &base = strs[0];
        int lcp_len = 0;
        bool status = true;
        for (; lcp_len < base.size(); lcp_len++){
            for (auto &str : strs) {
                status = status & (str[lcp_len] == base[lcp_len]);
            }
            if (status == false) break;
        }
        return base.substr(0, lcp_len);
    }
};