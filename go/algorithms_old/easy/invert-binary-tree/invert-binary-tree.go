package algorithms

import "github.com/goldennovember/leetcode-go/gods"

type TreeNode = gods.TreeNode

func invertTree(root *TreeNode) *TreeNode {

	if root == nil {
		return nil
	}

	root.Left, root.Right = root.Right, root.Left

	invertTree(root.Left)
	invertTree(root.Right)

	return root
}