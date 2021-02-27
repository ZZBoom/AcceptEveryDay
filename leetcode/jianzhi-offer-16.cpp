class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        long long m = n;
        if (n < 0) {
            x = 1 / x;
            m = -m;
        }
        double res = 1.0;
        while (m) {
            if (m & 1) {
                res = res * x;
            }
            x = x * x;
            m >>= 1;
        }
        return res;
    }
};
