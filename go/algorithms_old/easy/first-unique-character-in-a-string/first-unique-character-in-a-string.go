package algorithms

func firstUniqChar(s string) int {

	m := map[rune]int{}

	// count the number of each character
	for _, c := range s {
		m[c]++
	}

	// The first unique character is the first character that appears only once
	// Iterate over the string to find that first character and check it in the map
	for i, c := range s {
		if m[c] == 1 {
			return i
		}
	}
	return -1
}
