package algorithms

func smallestEvenMultiple(n int) int {

	// If the number is even, return it
	if n%2 == 0 {
		return n
	}
	// Otherwise, multiply it by 2
	return n * 2
}
