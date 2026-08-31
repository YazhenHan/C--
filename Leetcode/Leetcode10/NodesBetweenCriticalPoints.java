class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class NodesBetweenCriticalPoints {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int temp1 = -1, temp2 = -1;
        ListNode prev = head;
        ListNode curr = prev.next;
        ListNode next = curr.next;
        int i = 1;
        int ans1 = Integer.MAX_VALUE;
        while (next != null) {
            if (curr.val < prev.val && curr.val < next.val || curr.val > prev.val && curr.val > next.val) {
                if (temp2 == -1) {
                    temp1 = i;
                } else {
                    ans1 = Math.min(ans1, i - temp2);
                }
                temp2 = i;
            }
            i++;
            prev = curr;
            curr = next;
            next = next.next;
        }
        int[] ans = new int[2];
        if (temp1 != -1 && temp2 != temp1) {
            ans[1] = temp2 - temp1;
            ans[0] = ans1;
        } else {
            ans[0] = -1;
            ans[1] = -1;
        }
        return ans;
    }
}
