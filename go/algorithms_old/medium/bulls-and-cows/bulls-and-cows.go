package algorithms

import "fmt"

func getHint(secret string, guess string) string {

	// or we can use array instead of map to store the count: [10]int
	m := map[byte]int{}

	// count A and B
	a, b := 0, 0

	for i := 0; i < len(secret); i++ {
		if secret[i] == guess[i] {
			a++
		} else {
			// Count and store the number in the map
			m[secret[i]]++
		}
	}

	for i := 0; i < len(guess); i++ {
		// If the number is in the map, it means that the number is in the secret
		// and it is not in the right position
		if secret[i] != guess[i] && m[guess[i]] > 0 {
			b++
			m[guess[i]]--
		}
	}

	return fmt.Sprintf("%dA%dB", a, b)
}