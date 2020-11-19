/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (29.86%)
 * Likes:    2758
 * Dislikes: 0
 * Total Accepted:    365.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c
 * ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 * 示例：
 *
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 *
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 *
 */

// @lc code=start
#include <algorithm>
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) {
      return {};
    }

    vector<vector<int>> answer;
    // 採用三指標法
    // 首先先sort nums
    sort(nums.begin(), nums.end());
    vector<int>::iterator second_index;
    vector<int>::iterator third_index;
    for (vector<int>::iterator one_index = nums.begin();
         one_index < nums.end() - 2; ++one_index) {
      //當 one_index跟上一個數字一樣就跳過，這樣才不會重複
      if (one_index > nums.begin() and *one_index == *(one_index - 1)) {
        continue;
      }
      //  初始化
      second_index = one_index + 1;
      third_index = nums.end() - 1;
      while (second_index < third_index) {
        if (*one_index + *second_index + *third_index == 0) {
          answer.push_back({*one_index, *second_index, *third_index});
          second_index++;
          //   跳過重複的數字
          while (second_index < third_index and
                 *second_index == *(second_index - 1)) {
            second_index += 1;
          }
        } else if (*one_index + *second_index + *third_index > 0) {
          third_index -= 1;
          while (second_index < third_index and
                 *third_index == *(third_index + 1)) {
            third_index -= 1;
          }
        } else {
          second_index += 1;
          while (second_index < third_index and
                 *second_index == *(second_index - 1)) {
            second_index += 1;
          }
        }
      }
    }

    if (answer.empty()) {
      return {};
    }

    return answer;
  }
};
// @lc code=end
