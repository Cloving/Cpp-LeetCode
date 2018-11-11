/* Partition Array into Disjoint Intervals（以不相交的区间分割数组） */

/* 要取得cur之前的最大值，需要每次都遍历最大值，
 * 更新cur的时候，顺便更新。因为此时cur与maxValue是同步的索引 */
class Solution {
public:
  int partitionDisjoint(vector<int>& A) {
    int maxValue = A[0], cur = 0, preMaxValue = A[0];
    for (int i = 0; i < A.size(); i++) {
      maxValue = max(maxValue, A[i]);
      if (A[i] < preMaxValue) {
        preMaxValue = maxValue;
        cur = i;
      }
    }
    return cur+1;
  }
};