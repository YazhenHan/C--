package Leetcode.Leetcode10;

public class NumIslands {
    private void dfs(char[][] grid, boolean[][] isView, int i, int j) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || isView[i][j] || grid[i][j] == '0') return;
        isView[i][j] = true;
        dfs(grid, isView, i + 1, j);
        dfs(grid, isView, i - 1, j);
        dfs(grid, isView, i, j + 1);
        dfs(grid, isView, i, j - 1);
    }

    public int numIslands(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] isView = new boolean[m][n];
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!isView[i][j] && grid[i][j] == '1') {
                    ans++;
                    dfs(grid, isView, i, j);
                }
            }
        }
        return ans;
    }
}
