package algorithms

func average(salary []int) float64 {
	sum := 0
	min, max := salary[0], salary[0]

	for _, v := range salary {
		sum += v
		if v < min {
			min = v
		}
		if v > max {
			max = v
		}
	}

	return float64(sum-max-min) / float64(len(salary)-2)
}
