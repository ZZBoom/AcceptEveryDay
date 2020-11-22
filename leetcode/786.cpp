class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        std::vector<int> ans(2);
        double left = 0, right = 1;
        while(left + 1e-9 < right) {
            double mid = (left + right) / 2.0;
            auto res = Judge(mid, A);
            if (res[0] < K) {
                left = mid;
            } else {
                ans[0] = res[1];
                ans[1] = res[2];
                right = mid;
            }
        }
        return ans;
    }
    std::vector<int> Judge(double val, std::vector<int> &A) {
        int i = -1, count = 0, p = 0, q = 1;
        for (int j = 1; j < A.size(); j++) {
            while(A[i + 1] < A[j] * val - 1e-9) {
                i++;
            }
            count += i + 1;
            if (i >= 0 && p * A[j] < q * A[i]) {
                p = A[i];
                q = A[j];
            }
        }
        return {count, p, q};
    }
};
