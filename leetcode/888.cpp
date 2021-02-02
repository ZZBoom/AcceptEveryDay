class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        long long sumA = 0;
        long long sumB = 0;
        std::unordered_map<int, int> mp;
        std::for_each(A.begin(), A.end(),[&sumA](int x) {
            sumA += x;
        });
        std::for_each(B.begin(), B.end(),[&sumB, &mp](int x) {
            sumB += x;
            mp[x] = 1;
        });
        for (auto item : A) {
            long long s1 = sumA - item;
            long long s2 = sumB + item;
            long long ff = std::abs(s1 - s2);
            long long f = ff / 2;
            if ((sumA - item + f == sumB - f + item) && mp[f]) {
                return {item, (int)f};
            }
        }
        return {};
    }
};
