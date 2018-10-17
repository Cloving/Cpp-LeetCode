/* Add Binary(二进制求和) */

/* 第一种：直接法（自写，较复杂，留着吧） */
class Solution {
public:
    string addBinary(string a, string b) {
        if (b.empty()) {
          return a;
        }
        if (a.empty()) {
          return b;
        }
        if (a.size() < b.size()) {
          string temp = a;
          a = b;
          b = temp;
        }
        int aPos = a.size(), bPos = b.size(), carry = 0;
        while (--bPos >= 0 && --aPos >= 0) {
          int tempValue = a[aPos] - '0' + b[bPos] - '0' + carry;
          if (tempValue == 0) {
            a[aPos] = '0';
            carry = 0;
          } else if (tempValue == 1) {
            a[aPos] = '1';
            carry = 0;
          } else if (tempValue == 2) {
            a[aPos] = '0';
            carry = 1;
          } else if (tempValue == 3) {
            a[aPos] = '1';
            carry = 1;
          }
        }
        if (carry == 0) {
          return a;
        } else {
          while (--aPos >= 0) {
            int tempValue = a[aPos] - '0' + carry;
            if (tempValue == 2) {
              a[aPos] = '0';
              carry = 1;
            } else {
              a[aPos] = '1';
              carry = 0;
              break;
            }
          }
        }
        if (carry == 1) {
          a = '1' + a;
        }
        return a;
    }
};

/* 第二种： */
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string str = "";
        while(!a.empty() || !b.empty()) {
          int add_a = 0;
          if (!a.empty()) {
            add_a = a.back() - 48;
            a.pop_back();
          }
          int add_b = 0;
          if (!b.empty()) {
            add_b = b.back() - 48;
            b.pop_back();
          }
          int temp = add_a + add_b + carry;
          // 十进制也是这样求解的
          carry = temp / 2;
          char c = temp % 2 + 48;
          str = c + str;
        }
        return carry == 0 ? str : '1' + str;
    }
};


