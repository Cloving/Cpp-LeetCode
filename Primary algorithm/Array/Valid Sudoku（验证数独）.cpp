/**
 * 2018-8-20：验证数独是否合理
 * 验证给定二维数组的每个数是否规则内出现过，如果出现过返回false
 * 如果没有出现过，则标记该数字已出现过
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        int m = board.size(), n = board[0].size();
        // 2018-8-20: row是一个mxn维的二维数组，表示在第m行中字符c是否出现过，
        // col与cell也表示对应的含义
        vector<vector<bool>> row(m, vector<bool>(n, false));
        vector<vector<bool>> col(m, vector<bool>(n, false));
        vector<vector<bool>> cell(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int c = board[i][j] - '1';
                    if (row[i][c] || col[c][j] || cell[3*(i/3)+j/3][c]) {
                        return false;
                    }
                    row[i][c] = true;
                    col[c][j] = true;
                    cell[3*(i/3)+j/3][c] = true;
                }
            }
        }
        return true;
    }
};