class Solution {
public:
    bool startsWith(string &str, string&pref) {
        if (str.size() < pref.size())
            return false;
        
        for (int i = 0; i < pref.size(); ++i) {
            if(pref[i] != str[i])
                return false;
        }

        return true;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> results;

        string pref = "";
        for (auto &ch : searchWord) {
            pref.push_back(ch);
            vector<string> result;

            for (auto &product: products) {
                if (startsWith(product, pref)) 
                    result.push_back(product);
                if(result.size() == 3) 
                    break;
            }
            
            results.push_back(result);
        }

        return results;
    }
};