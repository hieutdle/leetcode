package algorithms

func isAnagram(s string, t string) bool {

	// If they don't have the same length, return false
	if len(s) != len(t) {
		return false
	}

	// Create a hashmap to count character
	m := map[rune]int{}

	// Loop through the first string and count the characters
	for _, v := range s {
		m[v]++
	}

	// Loop through the second string and decrease the count to 0
	for _, v := range t {
		m[v]--
	}

	// Loop through the hashmap to check if all the count are 0
	for _, v := range m {
		if v != 0 {
			return false
		}
	}

	return true
}
