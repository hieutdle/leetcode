package algorithms

func isIsomorphic(s string, t string) bool {

	// Store the length of the first string
	l := len(s)

	// If the length of the two strings are not equal, return false
	if l != len(t) {
		return false
	}

	// Create a map to store the mapping of the characters
	m := make(map[byte]byte)

	// Second map to calculate the length of unique characters from the second strings
	m2 := make(map[byte]bool)

	for i := 0; i < l; i++ {
		// If the character is not present in the map, add it
		// If it exists, check if the value is same as previous one.
		if _, ok := m[s[i]]; !ok {
			m[s[i]] = t[i]
		} else if m[s[i]] != t[i] {
			return false
		}
		// Store the unique characters from the second string
		m2[t[i]] = true
	}

	// If the length of the map is not equal to the length of the second string
	// Mean unique characters are not equal between two strings
	// Return false
	if len(m) != len(m2) {
		return false
	}

	return true

}
