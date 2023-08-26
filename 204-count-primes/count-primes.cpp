class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;

        vector<bool> prime (n, true);
        prime[0] = prime[1] = false;
        int ans = 0;

        for(int i = 2; i * i < n; i++) {
            if(prime[i]) {
                int j = i * i;

                while(j < n) {
                    prime[j] = false;
                    j += i;
                }
            }
        }

        int primeSize = prime.size();

        for(int i = 0; i < primeSize; i++) {
            if(prime[i] == true) {
                ans++;
            }
        }

        return ans;
    }
};