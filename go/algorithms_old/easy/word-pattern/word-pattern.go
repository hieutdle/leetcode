package algorithms

import "strings"

func wordPattern(pattern string, s string) bool {

	// Split the string into a slice of words
	words := strings.Fields(s)

	// Check that the pattern and the slice of words have the same length
	if len(pattern) != len(words) {
		return false
	}

	// Create a map to map characters in the pattern to words
	cMap := make(map[byte]string)

	// Create a map to map words to characters in pattern
	wMap := make(map[string]byte)

	// We should check if each character map to exactly one word, and if each word map to exactly one character
	// Loop over the characters in the pattern
	for i, char := range []byte(pattern) {

		// Check if the character is already on the map or not
		_, ok := cMap[char]

		// If the character is not in the mapping, add it
		if !ok {
			cMap[char] = words[i]
		} else if cMap[char] != words[i] {
			// If the character is in the mapping, but the word it is being mapped to is different
			// than the previously mapped word, return false
			return false
		}
	}

	// Doing the same thing, but with the words in the string this time.
	for i, word := range words {
		_, ok := wMap[word]
		if !ok {
			wMap[word] = pattern[i]
		} else if wMap[word] != pattern[i] {
			return false
		}
	}
	return true
}
