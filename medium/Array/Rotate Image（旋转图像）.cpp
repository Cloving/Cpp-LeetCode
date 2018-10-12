/**
 * 第一种：
 * 直接旋转，每次循环都确定一部分数组元素旋转之后的位置
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int maxIndex = matrix.size();
        for (int i = 0; i < maxIndex/2; i++) {
            for (int j = i; j < maxIndex-1 - i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[maxIndex-1-j][i];
                matrix[maxIndex-1-j][i] = matrix[maxIndex-1-i][maxIndex-1-j];
                matrix[maxIndex-1-i][maxIndex-1-j] = matrix[j][maxIndex-1-i];
                matrix[j][maxIndex-1-i] = temp;
            }
        }
    }
};

/**
 * 第二种：
 * 首先沿对角线翻转，之后按行上下翻转
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for(int i = 0; i < len-1; i++) {
            for (int j = 0; j < len - i; j++) {
                swap(matrix[i][j], matrix[len-1-j][len-1-i]);
            }
        }
        for (int i = 0; i < len / 2; i++) {
            for (int j = 0; j < len; j++) {
                swap(matrix[i][j], matrix[len-1-i][j]);
            }
        }
    }
};

/**
 * 第三种：
 * 首先进行转置操作，之后对后的每行整体反转
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};