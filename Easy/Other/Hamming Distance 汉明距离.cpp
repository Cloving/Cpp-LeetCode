class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, XOR = x ^ y;
        for (int i = 0; i < 32; i++) {
            if (XOR != 0) {
                res += (XOR >> i) & 1;
            }
        }
        return res;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, XOR = x ^ y;
        while(XOR != 0) {
            XOR = XOR & (XOR - 1);
            res++;
        }
        return res;
    }
};