package algorithms

func maximumWealth(accounts [][]int) int {
	richest := 0

	for i := range accounts {
		sum := 0
		for _, v := range accounts[i] {
			sum += v
		}
		if richest < sum {
			richest = sum
		}
	}
	return richest
}
