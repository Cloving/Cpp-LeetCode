/* Integer to Roman（整数转罗马数字） */

/* 第一种 */
class Solution {
public:
    string intToRoman(int num) {
      string res;
      vector<int> numVal{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
      vector<string> charVal{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
      for (int i = 0; i < numVal.size(); ++i) {
        while (num >= numVal[i]) {
          res += charVal[i];
          num -= numVal[i];
        }
      }
      return res;
    }
};

/* 第二种 */
class Solution {
public:
    string intToRoman(int num) {
      string s;
      vector<int> numVal{1000, 500, 100, 50, 10, 5, 1};
      vector<char> charVal{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
      for (int i = 0; i < numVal.size(); i += 2) {
        int temp = num / numVal[i];
        if (temp <= 3) {
          for (int k = 1; k <= temp; k++) {
            s += charVal[i];
          }
        } else if (temp == 4) {
          /* 此时为CD、XL都是相邻的，注意和temp == 9时的区别。 */
          s += charVal[i];
          s += charVal[i-1];
        } else if (temp >= 5 && temp <= 8) {
          s += charVal[i-1];
          for (int k = 5; k < temp; k++) {
            s += charVal[i];
          }
        } else if (temp == 9) {
          /* 此时为CM、XC都是中间隔一个的，注意和temp == 4时的区别。 */
          s += charVal[i];
          s += charVal[i-2];
        }
        num %= numVal[i];
      }
      return s;
    }
};