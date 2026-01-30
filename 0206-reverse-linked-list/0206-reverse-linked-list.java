/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverse(ListNode head){
        if(head.next == null) return head;
        //pick the first node
        ListNode firstnode = head;
        //baki recursion krega
        ListNode secondnode = head.next;
        ListNode newHead = reverse(secondnode);
        secondnode.next = firstnode;
        firstnode.next = null;
        return newHead;
    }
    public ListNode reverseList(ListNode head) {
        if(head == null) return head;
        return reverse(head);

    }
}