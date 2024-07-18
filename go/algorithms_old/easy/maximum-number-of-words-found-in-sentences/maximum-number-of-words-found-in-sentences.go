package algorithms

import "strings"

func mostWordsFound(sentences []string) int {

	result := 0

	// Count the number of spaces => number of words
	for i := range sentences {
		count := strings.Count(sentences[i], " ") + 1

		if count > result {
			result = count
		}
	}

	return result
}