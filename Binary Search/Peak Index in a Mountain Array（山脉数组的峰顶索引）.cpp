/* Peak Index in a Mountain Array（山脉数组的峰顶索引） */

/* 第一种 */
class Solution {
public:
  int peakIndexInMountainArray(vector<int>& A) {
    for (int i = 1; i < A.size()-1; ++i) {
      if (A[i] > A[i+1]) {
        return i;
      }
    }
  }
};

/* 第二种 */
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
      int left = 1, right = A.size() - 2;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] > A[mid+1] && A[mid] > A[mid-1]) {
          return mid;
        } else if (A[mid] < A[mid+1]) {
          left = mid + 1;
        } else if (A[mid] > A[mid+1]) {
          right = mid;
        }
      }
    }
};