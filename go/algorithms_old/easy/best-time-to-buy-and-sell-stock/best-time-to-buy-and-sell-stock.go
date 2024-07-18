package algorithms

func maxProfit(prices []int) int {

	profit := 0
	maxProfit := 0

	for i := 1; i < len(prices); i++ {
		profit += prices[i] - prices[i-1]
		// We should not start to buy profit if it is negative
		if profit < 0 {
			profit = 0
		}

		if maxProfit < profit {
			maxProfit = profit
		}
	}

	return maxProfit
}
