package algorithms

import "github.com/goldennovember/leetcode-go/gods"

type TreeNode = gods.TreeNode

func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}

	min := -1 << 63
	max := 1<<63 - 1

	return isValid(root, min, max)
}

func isValid(root *TreeNode, min int, max int) bool {
	if root == nil {
		return true
	}

	// check if the current node's value is in the range
	if root.Val <= min || root.Val >= max {
		return false
	}

	// When we go to the left, the max value should be the current node's value
	// The min value should be the same as the min value of the previous node

	// When we go to the right, the min value should be the current node's value
	// The max value should be the same as the max value of the previous node
	return isValid(root.Left, min, root.Val) && isValid(root.Right, root.Val, max)
}
