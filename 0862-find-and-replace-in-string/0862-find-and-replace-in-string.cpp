class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> sortedIndices;
    
        for (int i = 0; i < indices.size(); ++i) {
            sortedIndices.push_back({indices[i], i});
        }
        
        sort(sortedIndices.rbegin(), sortedIndices.rend());

        for (auto& entry : sortedIndices) {
            int index = entry.first;
            int i = entry.second;

            string source = sources[i];
            string target = targets[i];

            if (s.substr(index, source.size()) == source) {
                s = s.substr(0, index) + target + s.substr(index + source.size());
            }
        }

        return s;
    }
};