// 只能解决无符号数
class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned int res =0;
        while (n >0)
        {
            if((n &1) ==1) 
                res++;
            n >>=1; 
        }
        return res;
    }
};

// 可以解决有符号数
class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned int res = 0;
        int flag = 1;
        while (flag != 0) {
            if ((n & flag) != 0) {
                res++;
            }
            flag = flag<<1;
        }
        return res;
    }
};

// 同时满足有符号数和无符号数
class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned int res =0;
        while (n != 0) {
            n = n & n-1;
            res++;
        }
        return res;
    }
};