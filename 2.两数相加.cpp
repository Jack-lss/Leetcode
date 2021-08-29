/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     long long int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(long long int x) : val(x), next(nullptr) {}
 *     ListNode(long long int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
		ListNode* head = ans;
		int add = 0;
		while (l1 != NULL || l2 != NULL) {
			int leftNum = 0, rightNum = 0;
			if (l1) {
				leftNum = l1->val;
				l1 = l1->next;
			}
			if (l2) {
				rightNum = l2->val;
				l2 = l2->next;
			}
			ans->next = new ListNode((leftNum + rightNum + add) % 10);
			ans = ans->next;
			add = (leftNum + rightNum + add) / 10;
		}
		if (add > 0) ans->next = new ListNode(add);
		return head->next;
    }
};
// @lc code=end

