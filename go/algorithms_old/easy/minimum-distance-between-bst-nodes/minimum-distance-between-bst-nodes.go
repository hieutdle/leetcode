package algorithms

import "github.com/goldennovember/leetcode-go/gods"

type TreeNode = gods.TreeNode

func minDiffInBST(root *TreeNode) int {

	ans := 1<<31 - 1
	var dfs func(*TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}

		if node.Left != nil {
			ans = min(ans, node.Val-node.Left.Val)
		}
		if node.Right != nil {
			ans = min(ans, node.Right.Val-node.Val)
		}

		dfs(node.Left)
		dfs(node.Right)
	}

	dfs(root)
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
