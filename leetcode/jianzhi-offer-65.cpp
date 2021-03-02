class Solution {
public:
    int add(int a, int b) {
        while(b != 0) {
            unsigned int c = static_cast<unsigned int>(a & b) << 1;
            a ^= b;
            b = c;
        }
        return a;
    }
};
