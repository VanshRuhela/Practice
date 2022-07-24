/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<int> ans;
        if(m == 0) return ans;
        int n = matrix[0].size();
        
        int up = 0, down = m - 1;
        int right = n - 1, left = 0;

        while (ans.size() < n * m) {
            for (int j = left; j <= right && ans.size() < n * m; j++)
                ans.push_back(matrix[up][j]);

            for (int i = up + 1; i <= down - 1 && ans.size() < n * m; i++)
                ans.push_back(matrix[i][right]);

            for (int j = right; j >= left && ans.size() < n * m; j--)
                ans.push_back(matrix[down][j]);

            for (int i = down - 1; i >= up + 1 && ans.size() < n * m; i--)
                ans.push_back(matrix[i][left]);

            left++;
            right--;
            up++;
            down--;
        }
        return ans;
    }
};
// @lc code=end
