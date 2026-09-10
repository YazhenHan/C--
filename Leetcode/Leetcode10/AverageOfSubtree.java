class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class AverageOfSubtree {
    private void getSum(TreeNode root, int[] ans) {
        if (root == null) return;
        ans[0] += root.val;
        ans[1]++;
        getSum(root.left, ans);
        getSum(root.right, ans);
    }

    public int averageOfSubtree(TreeNode root) {
        if (root == null) return 0;
        int[] ans = {0, 0};
        getSum(root, ans);
        return ans[0] / ans[1] == root.val ? averageOfSubtree(root.left) + averageOfSubtree(root.right) + 1 : averageOfSubtree(root.left) + averageOfSubtree(root.right); 
    }
}
