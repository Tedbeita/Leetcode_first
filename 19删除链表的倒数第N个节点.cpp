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
class Solution {        //用双指针，快指针比慢指针快n个位置，当快指针到头了，慢指针就OK了
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* fast = dummyhead;
        ListNode* slow = dummyhead;
        while(n-- && fast != nullptr)
        {
            fast = fast->next;
        }
        
        while(fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyhead->next;
    }
};/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {        //用双指针，快指针比慢指针快n个位置，当快指针到头了，慢指针就OK了
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* fast = dummyhead;
        ListNode* slow = dummyhead;
        while(n-- && fast != nullptr)
        {
            fast = fast->next;
        }
        
        while(fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyhead->next;
    }
};
