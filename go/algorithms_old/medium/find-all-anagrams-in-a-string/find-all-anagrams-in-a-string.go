package algorithms

func findAnagrams(s string, p string) []int {

	// Create a slice to store the frequency of characters in s1
	count := [26]int{}

	ans := []int{}

	// Iterate through s1 and store the frequency of each character
	for _, c := range p {
		count[c-'a']++
	}

	for i := 0; i < len(s); i++ {

		// If we have found a character in s2 that is present in s1
		if count[s[i]-'a'] > 0 {

			// Create a slice to check the sliding window
			check := [26]int{}

			if i+len(p) <= len(s) {

				// Add the characters in the sliding window to the check slice
				for j := i; j < i+len(p); j++ {
					check[s[j]-'a']++
				}

				if count == check {
					ans = append(ans, i)
				}
			}
		}
	}

	return ans

}
