package algorithms

func canConstruct(ransomNote string, magazine string) bool {
	m := map[rune]int{}

	if len(ransomNote) > len(magazine) {
		return false
	}

	// Count character in magazine
	for _, c := range magazine {
		m[c]++
	}

	// Reduce count for each character in ransomNote
	for _,c := range ransomNote {

		// If the count of a character is already 0, return false
		if m[c] == 0 {return false}
		m[c]--
	}

	return true
}