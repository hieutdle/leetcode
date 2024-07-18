package algorithms

import (
	"github.com/goldennovember/leetcode-go/gods"
)

type LinkedList = gods.LinkedList
type ListNode = gods.ListNode

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {

	// If one of the list is empty, return the other list
	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	}

	ans := LinkedList{}
	var node *ListNode

	// Compare the first node of each list
	// Take the smaller one as the head of the answer list
	if list1.Val > list2.Val {
		ans.Head = list2
		node = list2
		list2 = list2.Next
	} else {
		ans.Head = list1
		node = list1
		list1 = list1.Next
	}

	// Compare the elements of the two lists until one of them is empty
	for list1 != nil && list2 != nil {
		if list1.Val > list2.Val {
			node.Next = list2
			list2 = list2.Next
		} else {
			node.Next = list1
			list1 = list1.Next
		}
		node = node.Next
	}

	// If one of the list is not empty, append it to the answer list
	if list1 != nil {
		node.Next = list1
	}

	if list2 != nil {
		node.Next = list2
	}

	return ans.Head
}
