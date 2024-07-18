package algorithms

func checkInclusion(s1 string, s2 string) bool {

	// Create a slice to store the frequency of characters in s1
	count := [26]int{}

	// Iterate through s1 and store the frequency of each character
	for _, c := range s1 {
		count[c-'a']++
	}

	for i := 0; i < len(s2); i++ {

		// If we have found a character in s2 that is present in s1
		if count[s2[i]-'a'] > 0 {

			// Create a slice to check the sliding window
			check := [26]int{}

			if i+len(s1) <= len(s2) {

				// Add the characters in the sliding window to the check slice
				for j := i; j < i+len(s1); j++ {
					check[s2[j]-'a']++
				}

				if count == check {
					return true
				}
			}
		}
	}

	return false
}
