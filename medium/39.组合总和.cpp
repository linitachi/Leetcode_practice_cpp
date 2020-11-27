/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (71.57%)
 * Likes:    1063
 * Dislikes: 0
 * Total Accepted:    182.7K
 * Total Submissions: 254.9K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的数字可以无限制重复被选取。
 *
 * 说明：
 *
 *
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 *
 *
 * 示例 1：
 *
 * 输入：candidates = [2,3,6,7], target = 7,
 * 所求解集为：
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * 示例 2：
 *
 * 输入：candidates = [2,3,5], target = 8,
 * 所求解集为：
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * candidate 中的每个元素都是独一无二的。
 * 1 <= target <= 500
 *
 *
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> answers;
    vector<int> answer;
    helper(candidates, target, answer, answers);
    return answers;
  }

  void helper(vector<int> candidates, int target, vector<int> answer,
              vector<vector<int>>& answers) {
    sort(candidates.begin(), candidates.end());
    for (size_t i = 0; i < candidates.size(); i++) {
      if (candidates[i] == target) {
        answer.push_back(candidates[i]);
        answers.push_back(answer);
        answer.erase(answer.end() - 1);
      } else if (candidates[i] < target) {
        answer.push_back(candidates[i]);
        vector<int> next_candidate;
        for (size_t j = i; j < candidates.size(); j++) {
          next_candidate.push_back(candidates[j]);
        }
        helper(next_candidate, target - candidates[i], answer, answers);
        answer.erase(answer.end() - 1);
      } else {
        return;
      }
    }
  }
};
// @lc code=end
