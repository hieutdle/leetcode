package algorithms

import "github.com/goldennovember/leetcode-go/gods"

type TreeNode = gods.TreeNode

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	// if p and q are both smaller than root, then the LCA must be in the left subtree
	if p.Val < root.Val && q.Val < root.Val {
		return lowestCommonAncestor(root.Left, p, q)
	}

	// if p and q are both larger than root, then the LCA must be in the right subtree
	if p.Val > root.Val && q.Val > root.Val {
		return lowestCommonAncestor(root.Right, p, q)
	}

	// otherwise, root is the LCA
	return root
}
