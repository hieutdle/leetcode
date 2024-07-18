package algorithms

func groupAnagrams(strs []string) [][]string {
	var ans [][]string

	// Return if there is nothing in the array
	if len(strs) == 0 {
		return ans
	}

	// Create a hashmap with the key is the array that stores the count of characters
	m := map[[26]int][]string{}

	// When the right pattern is found, append the string to the value of this pattern (key)
	for _, v := range strs {
		c := countCharacters(v)
		m[c] = append(m[c], v)
	}

	for _, v := range m {
		ans = append(ans, v)
	}
	return ans
}

func countCharacters(s string) [26]int {

	// Create array to store the count of characters
	c := [26]int{}
	for _, v := range s {
		c[v-'a']++
	}
	return c
}
