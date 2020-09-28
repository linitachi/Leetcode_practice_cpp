/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (65.56%)
 * Likes:    354
 * Dislikes: 0
 * Total Accepted:    107.6K
 * Total Submissions: 159.4K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows > 0)
        {
            vector<vector<int>> final_list = {{1}};
            vector<int> temp_list = {1};
            while (numRows > 1)
            {
                temp_list = calculate_next_row(temp_list);
                final_list.push_back(temp_list);
                numRows -= 1;
            }
            return final_list;
        }
        else
        {
            return {};
        }
    }

    vector<int> calculate_next_row(vector<int> input_list)
    {
        vector<int> next_list = {};
        next_list.push_back(1);
        for (int i = 1; i < input_list.size(); i++)
        {
            next_list.push_back(input_list[i - 1] + input_list[i]);
        }
        next_list.push_back(1);
        return next_list;
    }
};
// @lc code=end
