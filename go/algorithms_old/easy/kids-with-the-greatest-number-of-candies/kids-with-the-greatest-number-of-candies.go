package algorithms

func kidsWithCandies(candies []int, extraCandies int) []bool {
	max := candies[0]

	result := make([]bool, 0, len(candies))

	for i := range candies {
		if candies[i] > max {
			max = candies[i]
		}
	}

	for i := range candies {
		if candies[i]+extraCandies >= max {
			result = append(result, true)
		} else {
			result = append(result, false)
		}
	}
	return result
}
