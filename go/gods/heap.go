package gods

import "fmt"

type Heap struct {
	Array []int
}

// Insert adds an element to the heap
func (h *Heap) Insert(key int) {
	h.Array = append(h.Array, key)
	h.HeapifyUp(len(h.Array) - 1)
}

// Extract returns the largest key, and removes it from the heap.
func (h *Heap) Extract() int {
	extracted := h.Array[0]
	l := len(h.Array) - 1

	if len(h.Array) == 0 {
		fmt.Print("cannot extract because Array length is 0")
		return -1
	}

	h.Array[0] = h.Array[l]
	h.Array = h.Array[:l]

	h.HeapifyDown(0)
	return extracted
}

// HeapifyUp will heapify from bottom top
func (h *Heap) HeapifyUp(index int) {
	for h.Array[parent(index)] < h.Array[index] {
		h.swap(parent(index), index)
		index = parent(index)
	}
}

// HeapifyDown will be heapify top to bottom
func (h *Heap) HeapifyDown(index int) {

	// loop while index at least one child
	lastIndex := len(h.Array) - 1
	l, r := left(index), right(index)
	childToCompare := 0
	for l <= lastIndex {
		if l == lastIndex {
			// when left child is the only child
			childToCompare = l
		} else if h.Array[l] > h.Array[r] {
			//when left child is larger
			childToCompare = l
		} else {
			// when right child is larger
			childToCompare = r
		}

		// compare Array value of current index
		// to larger child and swap if smaller

		if h.Array[index] < h.Array[childToCompare] {
			h.swap(index, childToCompare)
			index = childToCompare
			l, r = left(index), right(index)
		} else {
			// it means it find the right place
			return
		}

	}
}

// get the parent index
func parent(i int) int {
	return (i - 1) / 2
}

// get the left child index
func left(i int) int {
	return 2*i + 2
}

// get the right child index
func right(i int) int {
	return 2*i + 1
}

// swap keys in the Array
func (h *Heap) swap(i1, i2 int) {
	h.Array[i1], h.Array[i2] = h.Array[i2], h.Array[i1]
}
