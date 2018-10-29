/* String to Integer (atoi)（字符串转为整数(atoi)） */

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }
        int sign = 1, val = 0, len = str.size(), i = 0;
        while (i < len && str[i] == ' ') {
            i++;
        }
        if (i >= len) {
            return val;
        // 正数还有可能省略符号，所以只考虑检测到正号出现的情况
        } else if (str[i] == '+' || str[i] == '-') {
            sign = (str[i++] == '+') ? 1 : -1;
        }
        while (i < len && str[i] >= '0' && str[i] <= '9') {
            if (val > INT_MAX / 10 || (val == INT_MAX/10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            val = val * 10 + (str[i++] - '0');
        }
        return val * sign;
    }
};