package algorithms

func singleNumber(nums []int) int {
	ans := 0
	for _, v := range nums {
		// XOR
		// 0^0 == 0
		// 1^0 == 1
		// 0^1 == 1
		// 1^1 == 1
		ans ^= v
	}
	return ans
}
