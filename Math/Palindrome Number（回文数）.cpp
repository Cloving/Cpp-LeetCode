/* Palindrome Number（回文数） */

/* 第一种：反转数与原数比较 */
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int sum = 0, tail = 0, temp = x;
    while (temp > 0) {
      if (sum < INT_MAX / 10) {
        sum = sum * 10 + temp % 10;
        temp = temp / 10;
      } else {
        return false;
      }
    }
    return sum == x;
  }
};

/* 第二种：首尾比较 */
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int head = 0, tail = 0, div = 1;
    while (x / div >= 10) {
      div *= 10;
    }
    while (x > 0) {
      tail = x % 10;
      head = x / div;
      if (head != tail) {
        return false;
      }
      x = (x % div) / 10;
      div = div / 100;
    }
    return true;
  }
};


/* 第三种：反转后半部分与前半段比较 */
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) {
      return false;
    }
    int behindPart = 0, temp = 0;
    while (behindPart < x) {
      behindPart = behindPart * 10 + x % 10;
      x = x / 10;
    }
    return x == behindPart || x == behindPart / 10;
  }
};
