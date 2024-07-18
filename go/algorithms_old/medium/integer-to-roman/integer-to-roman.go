package algorithms

func intToRoman(num int) string {

	// Slice to hold values
	values := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}

	// Slice to hold roman numerals
	symbols := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}

	res := ""

	// Index to iterate through values and symbols
	i := 0

	for num != 0 {
		// If the current value in the value slice is less than the number
		if num >= values[i] {
			// Add the roman numeral to the result
			res += symbols[i]

			// Subtract the value from the number
			num -= values[i]
		} else {
			// Increment the index to move to the next value and roman numeral
			i++
		}
	}

	return res

}
