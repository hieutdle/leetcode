package algorithms

import "github.com/goldennovember/leetcode-go/gods"

type TreeNode = gods.TreeNode

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}

	var result [][]int

	// Use a queue to store the nodes in the same level
	var queue []*TreeNode

	// Add the root to the queue
	queue = append(queue, root)

	for len(queue) > 0 {

		// currenLevelVal stores the values of the nodes in the current level
		var currentLevelVal []int

		// nextLevel stores the nodes in the next level
		var nextLevel []*TreeNode

		// Iterate through the nodes in the current level
		for _, node := range queue {

			// Add the value of the node to the currentLevelVal
			currentLevelVal = append(currentLevelVal, node.Val)

			// Add the left and right nodes (next level) to the nextLevel variable
			if node.Left != nil {
				nextLevel = append(nextLevel, node.Left)
			}
			if node.Right != nil {
				nextLevel = append(nextLevel, node.Right)
			}
		}

		// Add the values of the nodes in the current level to the result
		result = append(result, currentLevelVal)

		// Update the queue to the next level
		queue = nextLevel
	}

	return result
}
