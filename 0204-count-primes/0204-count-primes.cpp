class Solution {
public:
    int countPrimes(int n) {
        vector<bool> mark(n + 1, false);
        mark[1] = true;
        for (int i = 2; i * i <= n; i++) {
            if (mark[i] == false) {
                for (int m = i * i; m <= n; m += i) {
                    mark[m] = true;
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i < mark.size(); i++) {
            if (mark[i] == false) cnt++;
        }

        return cnt;
    }
};