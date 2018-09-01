/**
 * 加一
 * 第一种
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        if (digits[0] == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

/**
 * 加一
 * 第二种：通过分别取出个位数与十位数来判断
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size(), begin = 1;
        for (int i = len-1; i >= 0; i--) {
            if (begin == 0) {
                return digits;
            } else {
                digits[i] += 1;
                begin = digits[i] / 10;
                int end = digits[i] % 10;
                digits[i] = end;
            }
        }
        if (digits[0] == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};