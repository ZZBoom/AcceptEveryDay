class Solution {
public:
  // x
  // x x1 x2 x3 x4 x5  x6 x7 x8 x9
  long long get_count(long long prefix, long long n) {
    long long cnt = 0;
    long long a = prefix, b = prefix + 1;
    while (a <= n) {
      cnt += min(n + 1, b) - a;
      a *= 10;
      b *= 10;
    }
    return cnt;
  }
  int findKthNumber(int n, int k) {
    int i = 1;
    int p = 1;
    while (p < k) {
      int count = get_count(i, n);
      if (p + count > k) {
        i *= 10;
        p++;
      } else {
        p += count; 
        i++;
      }
    }
    return i;
  }
};
