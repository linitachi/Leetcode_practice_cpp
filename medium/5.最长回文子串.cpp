/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (32.16%)
 * Likes:    2916
 * Dislikes: 0
 * Total Accepted:    420.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 示例 1：
 *
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 *
 *
 * 示例 2：
 *
 * 输入: "cbbd"
 * 输出: "bb"
 *
 *
 */

// @lc code=start
using namespace std;
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() == 1) return s;
    if (s.size() == 0) return "";
    std::vector<std::vector<int>> dp;
    std::vector<int> row;
    row.assign(s.size(), 0);
    dp.assign(s.size(), row);
    int length = 0;
    int start = 0;

    for (int j = 1; j < s.size(); j++) {
      for (int i = 0; i < j; i++) {
        if (s[i] == s[j]) {
          //   代表子字串小於三個字
          if (j - i < 3) dp[i][j] = 1;
          // 子字串大於3個字的話，頭尾一樣就看前一個子字串是否是回文
          else
            dp[i][j] = dp[i + 1][j - 1];
        } else
          dp[i][j] = 0;
        if (dp[i][j] == 1) {
          if (j - i + 1 > length) {
            length = j - i + 1;
            start = i;
          }
        }
      }
    }

    std::reverse(s.begin() + start, s.begin() + start + length);
    std::string answer = s.substr(start, length);
    if (answer != "")
      return answer;
    else {
      std::string tem(1, s[0]);
      return tem;
    }
  }
};
// @lc code=end
