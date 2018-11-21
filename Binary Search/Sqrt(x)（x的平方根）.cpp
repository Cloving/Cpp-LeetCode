/* Valid Perfect Square（有效的完全平方数） */

/* 第一种: 从头往后遍历 */
class Solution {
public:
  int mySqrt(int x) {
    if (x == 0) {
      return 0;
    }
    int i = 1;
    while(i <= x / i) {
      if (i * i > x) {
        break;
      }
      i++;
    }
    return i-1;
  }
};

/* 第二种: 二分法*/
class Solution {
public:
  int mySqrt(int x) {
    int left = 0, right = x;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      long temp = mid * mid;
      if (temp == x) {
        return mid;
      } else if (temp < x) {
        left = mid + 1;
      } else if (temp > x) {
        right = mid - 1;
      }
    }
    return right;
  }
};

/* 第三种: 牛顿迭代法*/
class Solution {
public:
  int mySqrt(int x) {
    long temp = x;
    while (temp * temp > x) {
      temp = (temp + x / temp) / 2; 
    }
    return temp;
  }
};