package algorithms

import "github.com/goldennovember/leetcode-go/gods"

type ListNode = gods.ListNode

func detectCycle(head *ListNode) *ListNode {
	m := map[*ListNode]bool{}

	for head != nil {
		if !m[head]{
			m[head] = true
			head = head.Next
		} else {
			return head
		}
	}
	return head
}
