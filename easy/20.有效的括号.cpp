/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (43.16%)
 * Likes:    1996
 * Dislikes: 0
 * Total Accepted:    462.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 *
 *
 * 注意空字符串可被认为是有效字符串。
 *
 * 示例 1:
 *
 * 输入: "()"
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: "()[]{}"
 * 输出: true
 *
 *
 * 示例 3:
 *
 * 输入: "(]"
 * 输出: false
 *
 *
 * 示例 4:
 *
 * 输入: "([)]"
 * 输出: false
 *
 *
 * 示例 5:
 *
 * 输入: "{[]}"
 * 输出: true
 *
 */

// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    map<char, char> answer_map = {{'{', '}'}, {'(', ')'}, {'[', ']'}};
    vector<char> answer_list;
    for (string::const_iterator it = s.begin(); it != s.end(); it++) {
      //   如果找到{、(、[就把他們的另一邊加入倒answer_list裡面
      if (answer_map.find(*it) != answer_map.end()) {
        answer_list.push_back(answer_map.find(*it)->second);
      }
      //   出現}、)、]的話，就按照出現的順序看answer_list裡面是否有符合的。
      //   越晚加入要越先出現
      else {
        if (answer_list.size() == 0) return false;
        if (answer_list.back() != *it) return false;
        answer_list.pop_back();
      }
    }
    if (answer_list.size() > 0) return false;
    return true;
  }
};
// @lc code=end
