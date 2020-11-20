/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (40.42%)
 * Likes:    1113
 * Dislikes: 0
 * Total Accepted:    282.6K
 * Total Submissions: 697.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 *
 * 示例：
 *
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 *
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 *
 *
 * 说明：
 *
 * 给定的 n 保证是有效的。
 *
 * 进阶：
 *
 * 你能尝试使用一趟扫描实现吗？
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> answer_list;
    ListNode* tem = head;
    while (tem != NULL) {
      answer_list.push_back(tem);
      tem = tem->next;
    }

    int size = answer_list.size();
    if (n == size) {
      return head->next;
    }
    if (n > 1) {
      answer_list[size - n - 1]->next = answer_list[size - n + 1];
    } else {
      answer_list[size - n - 1]->next = NULL;
    }
    return head;
  }
};
// @lc code=end
