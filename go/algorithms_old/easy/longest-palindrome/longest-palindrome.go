package algorithms

func longestPalindrome(s string) int {

	// Map to store the count of each character
	m := map[rune]int{}

	ans := 0
	hasOdd := 0

	// Iterate over the string and count the number of each character
	for _, c := range s {
		m[c]++
	}


	for _, v := range m {

		// If the number of the character is even, add it to the answer
		if v%2 == 0 {
			ans += v
		} else {
			// If the number of the character is odd, we don't remove it
			// We add the even part of it to the answer, which is v-1
			ans += v - 1

			// We also set hasOdd to 1, which means we have an odd number of characters
			hasOdd = 1
		}
	}
	return ans + hasOdd
}
