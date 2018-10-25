class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        int curtotalRow = n, curtotalCol = n, circle = (n+1) / 2;
        int count = 1;
        for (int i = 0; i < circle; ++i, curtotalRow -= 2, curtotalCol -= 2) {
            for (int curCol = i; curCol < i + curtotalCol; curCol++) {
                res[i][curCol] = count++;
            }
            for (int curRow = i + 1; curRow < i + curtotalRow; curRow++) {
                res[curRow][i+curtotalCol-1] = count++;
            }
            for (int curCol = i + curtotalCol - 2; curCol >= i; curCol--) {
                res[i+curtotalRow-1][curCol] = count++;
            }
            for (int curRow = i + curtotalRow - 2; curRow > i; curRow--) {
                res[curRow][i] = count++;
            }
        }
        return res;
    }
};