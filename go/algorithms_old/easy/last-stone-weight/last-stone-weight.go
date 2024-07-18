package algorithms

import "github.com/goldennovember/leetcode-go/gods"

type Heap = gods.Heap

func lastStoneWeight(stones []int) int {
	heap := Heap{Array: stones}
	l := len(stones)

	for l > 1 {
		x := heap.Extract()
		heap.HeapifyDown(0)
		heap.HeapifyDown(0)
		y := heap.Extract()
		if x != y {
			heap.Insert(x - y)
		}
		l = len(heap.Array)
	}

	if len(heap.Array) == 0 {
		return 0
	}

	return heap.Array[0]
}
