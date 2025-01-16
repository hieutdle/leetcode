/*
 * @lc app=leetcode id=36 lang=java
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms Medium (61.24%) Likes: 11171 Dislikes: 1176 Total Accepted: 1.8M Total Submissions: 3M
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",
 * ".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1",
 * "9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according
 * to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition. Each column must contain the
 * digits 1-9 without repetition. Each of the nine 3 x 3 sub-boxes of the grid must contain the
 * digits 1-9 without repetition.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily solvable. Only the filled
 * cells need to be validated according to the mentioned rules.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = [["5","3",".",".","7",".",".",".","."] ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."] ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"] ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."] ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]] Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["8","3",".",".","7",".",".",".","."] ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."] ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"] ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."] ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]] Output: false Explanation: Same as Example 1, except with
 * the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3
 * sub-box, it is invalid.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9 board[i].length == 9 board[i][j] is a digit 1-9 or '.'.
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] rows = new boolean[9][9];
        boolean[][] cols = new boolean[9][9];
        boolean[][] boxes = new boolean[9][9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                // Convert the char (digit) to int
                // C++: If using a vector instead of a hashmap
                // the index should range from 0 to 8.
                // int num = board[i][j] - '0' - 1;
                // Java: int num = board[i][j] - '0';
                // error: Index 9 out of bounds for length 9
                int num = board[i][j] - '0' - 1;

                // (i / 3 * 3) represents the row of the sub-box:
                // 0 1 2
                // 3 4 5
                // 6 7 8
                // For i = 0, 1, 2 → sub-box: 0 + j.
                // For i = 3, 4, 5 → sub-box: 3 + j.
                // For i = 6, 7, 8 → sub-box: 6 + j.
                // [2,8] -> (2/3*3) + (8/3) = 0 + 2 = 2
                // [4,1] -> (4/3*3) + (1/3) = 3 + 0 = 4
                int k = (i / 3 * 3) + (j / 3);

                if (rows[i][num] || cols[j][num] || boxes[k][num])
                    return false;

                rows[i][num] = true;
                cols[j][num] = true;
                boxes[k][num] = true;
            }
        }
        return true;
    }
}
// @lc code=end
