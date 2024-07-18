package algorithms

func smallerNumbersThanCurrent(nums []int) []int {
	ans := []int{}
	for _, v := range nums {
		count := 0
		for _, v2 := range nums {
			if v > v2 {
				count++
			}
		}
		ans = append(ans, count)
	}
	return ans
}
