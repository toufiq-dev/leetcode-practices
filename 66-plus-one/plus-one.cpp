class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       vector<int> ans;
       int carry = 0;
       int digitsSize = digits.size() - 1;

       for(int i = digitsSize; i >= 0; i--) {
           int sum;

           if(i == digitsSize) {
               sum = digits[i] + 1;   
           } else {
               sum = digits[i] + carry;
           }

           if(digitsSize == 0 && sum > 9) {
               ans.push_back(1);
               ans.push_back(0);
           } else {
                if(sum > 9) {
                    carry = sum / 10;
                    sum = sum % 10;
                } else {
                    carry = 0;
                }

                ans.insert(ans.begin(), sum);
            }
       }

       if(carry) {
           ans.insert(ans.begin(), carry);
       }

       return ans;
    }
};