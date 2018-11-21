/* Valid Perfect Square（有效的完全平方数） */

/* 第一种：二分法 */
class Solution {
public:
  bool isPerfectSquare(int num) {
    int left = 0, right = num;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      long temp = mid * mid;
      if (temp == num) {
        return true;
      } else if (temp < num) {
        left = mid + 1;
      } else if (temp > num) {
        right = mid - 1;
      }
    }
    return false;
  }
};

/* 第二种 */
class Solution {
public:
  bool isPerfectSquare(int num) {
    for (int i = 1; i <= num / i; ++i) {
      if (i * i == num) {
        return true;
      }
    }
    return false;
  }
};

/* 第三种：完全平方数是一部分奇数之和 */
class Solution {
public:
  bool isPerfectSquare(int num) {
    int odd = 1;
    while (num > 0) {
      num -= odd;
      odd += 2;
    }
    return num == 0;
  }
};

/* 第四种：牛顿迭代法 */
class Solution {
public:
  bool isPerfectSquare(int num) {
    long cur = num;
    while (cur * cur > num) {
      cur = (cur + num / cur) / 2;
    }
    return cur * cur == num;
  }
};

