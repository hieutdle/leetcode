package algorithms

func isAlienSorted(words []string, order string) bool {
	m := map[byte]int{}

	// Store the order and its index in a map
	for i, c := range order {
		m[byte(c)] = i
	}

	for i := 0; i < len(words)-1; i++ {
		// Compare each word with the next one
		// If the current word is not sorted, return false
		if !isSorted(words[i], words[i+1], m) {
			return false
		}
	}
	return true
}

func isSorted(a, b string, m map[byte]int) bool {
	for i := 0; i < len(a) && i < len(b); i++ {
		// Compare the index of the characters in two words
		// If they are equal, continue to compare the next character
		// If not, return if the index of the first character is less than the second one
		if a[i] != b[i] {
			return m[a[i]] < m[b[i]]
		}
	}

	// If both words have the same characters
	// Check if the first word is shorter than the second one
	return len(a) <= len(b)
}
