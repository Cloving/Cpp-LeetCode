class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vec(n-1, true);
        int res = 0, lim = sqrt(n);
        vec[0] = false;
        for (int i = 2; i <= lim; i++) {
            if (vec[i-1] == true) {
                for (int j = i*i; j < n; j += i) {
                    vec[j-1] = false;
                }
            }
        }
        for (int i = 1; i < n-1; i++) {
            if (vec[i]) {
                res++;
            }
        }
        return res;
    }
};