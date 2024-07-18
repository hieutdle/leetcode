package algorithms

func addToArrayForm(num []int, k int) []int {
	res := make([]int, len(num))
	copy(res, num)

	for i := len(res) - 1; i >= 0; i-- {

		// Add the last digit of k to the current digit of num
		res[i] += k % 10

		// Remove the last digit of k
		k /= 10

		// If the current digit of num is greater than 10, add 1 to the next digit for k
		if res[i] >= 10 {
			k++

			// Remove 10 from the current digit of num
			res[i] -= 10
		}
	}

	// Add the remaining digits of k to the beginning of the result
	for k > 0 {
		res = append([]int{k % 10}, res...)
		k /= 10
	}

	return res
}
