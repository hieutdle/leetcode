package algorithms

func countOdds(low int, high int) int {
	// | is the bitwise OR operator
	// 1 | 0 = 1
	// 1 | 1 = 1
	// 0 | 0 = 0
	// 0 | 1 = 1
	return (high-low)/2 + (low%2 | high%2)
}
