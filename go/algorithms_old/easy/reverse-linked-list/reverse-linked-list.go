package algorithms

import "github.com/goldennovember/leetcode-go/gods"

type ListNode = gods.ListNode
type LinkedList = gods.LinkedList

func reverseList(head *ListNode) *ListNode {
	ans := LinkedList{}
	if head == nil || head.Next == nil {
		return head
	}

	for head != nil {
		node := &ListNode{Val: head.Val}
		ans.Prepend(node)
		head = head.Next
	}
	return ans.Head
}
