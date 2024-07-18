package algorithms

import "github.com/goldennovember/leetcode-go/gods"

type ListNode = gods.ListNode

func middleNode(head *ListNode) *ListNode {
	single, double := head, head
	for double != nil && double.Next != nil {
		single = single.Next
		double = double.Next.Next
	}
	return single
}
