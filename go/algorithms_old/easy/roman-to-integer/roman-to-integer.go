package algorithms

func romanToInt(s string) int {

	m := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	l := len(s)

	// If length = 0, return 0
	// If length = 1, just return this character
	if l == 0 {
		return 0
	} else if l == 1 {
		return m[s[0]]
	}

	// Store the value of the last character
	result := m[s[l-1]]

	for i := l - 2; i >= 0; i-- {

		// If the value of the character from this direction: <- is smaller than the previous one
		if m[s[i]] < m[s[i+1]] {
			// Minus the value
			result -= m[s[i]]
		} else {
			// Just add the value to our result
			result += m[s[i]]
		}
	}
	return result

}
