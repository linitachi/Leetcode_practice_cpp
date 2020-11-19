/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (35.79%)
 * Likes:    4601
 * Dislikes: 0
 * Total Accepted:    729.4K
 * Total Submissions: 2M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 * 示例 1:
 *
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<char> buffer;
    int longest = 0;
    int i = 0;
    vector<char>::iterator iter;
    while (s.size() > i) {
      // 尋找字元，如果沒找到的話
      iter = find(buffer.begin(), buffer.end(), s[i]);
      if (iter == buffer.end())
        //   加入到vector裡面
        buffer.push_back(s[i]);
      else {
        //   如果發現重複的元素 嘗試更新最大值
        if (longest < buffer.size()) {
          longest = buffer.size();
        }
        //  並且從最左邊的元素開始刪除，直到buffer裡面沒有重複的元素
        while (1) {
          buffer.erase(buffer.begin());
          iter = find(buffer.begin(), buffer.end(), s[i]);
          if (iter == buffer.end()) break;
        }
        buffer.push_back(s[i]);
      }
      i++;
    }
    if (longest < buffer.size()) {
      longest = buffer.size();
    }
    return longest;
  }
};
// @lc code=end
