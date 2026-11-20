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
private:
    int size(ListNode* head){
        ListNode* ptr1 = head;
        int cnt = 1;
        while(ptr1->next!=NULL){
            ptr1 = ptr1->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int n = size(head);
        if(n == 1) return head;
        if(k == n) return head;
        if(k>n) k = k%n;


        for(int i = 0; i<k; i++){
            ListNode* tail = head;
            ListNode* prevTail = head;
            while(tail->next!=NULL){
                tail = tail->next;
                if(prevTail->next->next == NULL || prevTail->next == NULL) continue;
                else prevTail = prevTail->next;
            }
            prevTail->next = NULL;
            tail->next = head;
            head = tail;
        }
        return head;
    }
};