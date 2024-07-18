package gods

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

type LinkedList struct {
	Head   *ListNode
	Length int
}

// Add a ListNode to the front of the list

func (l *LinkedList) Prepend(n *ListNode) {
	second := l.Head
	l.Head = n
	l.Head.Next = second
	l.Length++
}

// Add a ListNode to the end of the list

func (l *LinkedList) Append(n *ListNode) {
	if l.Length == 0 {
		l.Head = n
		l.Length++
		return
	}
	toAppend := l.Head

	// Travel to the last node
	for toAppend.Next != nil {
		toAppend = toAppend.Next
	}
	toAppend.Next = n
	l.Length++
}

// Add a ListNode with position

func (l *LinkedList) Insert(n *ListNode, position int) bool {
	if position > l.Length {
		return false
	}
	if position == 1 {
		l.Prepend(n)
		return true
	}
	if position == l.Length {
		l.Append(n)
		return true
	}
	toInsert := l.Head

	// Move to the node next to the position. E.g. if position is 3, move to the second node.
	for i := 1; i < position-1; i++ {
		toInsert = toInsert.Next
	}

	// Point the new node to the previous node of the position (this node become the 4th node now)
	n.Next = toInsert.Next

	// Point the node next to the position to the new node ( 2 -> 3 )
	toInsert.Next = n
	l.Length++
	return true
}

// toDelete means the previous node next to the node you want to delete

// Delete with value

func (l *LinkedList) DeleteWithValue(value int) {

	// If the head is the value we want to delete
	if l.Head.Val == value {
		l.Head = l.Head.Next
		l.Length--
		return
	}

	toDelete := l.Head

	// Travel to the node next to the node we want to delete
	for toDelete.Next != nil {

		// If the next node is the value we want to delete
		if toDelete.Next.Val == value {

			// Skip the node to delete
			toDelete.Next = toDelete.Next.Next
			l.Length--
			return
		}

		// Move to the next node
		toDelete = toDelete.Next
	}
}

// Delete with position

func (l *LinkedList) Delete(position int) bool {
	if position > l.Length {
		return false
	}
	if position == 1 {
		l.Head = l.Head.Next
		l.Length--
		return true
	}
	toDelete := l.Head

	// Move to the node next to the position. E.g. if position is 3, move to the second node.
	for i := 1; i < position-1; i++ {
		toDelete = toDelete.Next
	}

	// Skip the node to delete
	toDelete.Next = toDelete.Next.Next
	l.Length--
	return true
}

// Print the list

func (l LinkedList) PrintListVal() {
	toPrint := l.Head
	for l.Length != 0 {
		fmt.Printf("%d ", toPrint.Val)
		toPrint = toPrint.Next
		l.Length--
	}
	fmt.Println("\n")
}

// Convert a list to a slice of int (for LeetCode)

func List2Ints(head *ListNode) []int {
	res := []int{}
	for head != nil {
		res = append(res, head.Val)
		head = head.Next
	}
	return res
}

// Convert a slice of int to a list (for LeetCode)

func Ints2List(nums []int) *ListNode {
	var head *ListNode
	for i := len(nums) - 1; i >= 0; i-- {
		head = &ListNode{Val: nums[i], Next: head}
	}
	return head
}
