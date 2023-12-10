// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1, R = n;
        while(L < R) {
            int mid = L + (R - L) / 2;
            cout << L << "    " << R << "      " << mid << endl; 
            if(!isBadVersion(mid)) 
                L = mid + 1;
            else 
                R = mid;
        }

        return L;
    }
};