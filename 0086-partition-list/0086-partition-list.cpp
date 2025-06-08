class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    
        ListNode* smallDummy = new ListNode(-1);
        ListNode* largeDummy = new ListNode(-1);

        ListNode* smallerNode = smallDummy;
        ListNode* greaterNode = largeDummy;

        ListNode* temp = head;

        while (temp != NULL) {
            if (temp->val < x) {
                smallerNode->next = temp;
                smallerNode = smallerNode->next;
            } else {
                greaterNode->next = temp;
                greaterNode = greaterNode->next;
            }
            temp = temp->next;
        }

   
        greaterNode->next = nullptr;

        smallerNode->next = largeDummy->next;

        return smallDummy->next;
    }
};
