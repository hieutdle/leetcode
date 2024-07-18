package algorithms

import "strings"

func convert(s string, numRows int) string {

	// If numRows is 1, then the string is returned as is
	if numRows == 1 || len(s) <= numRows {
		return s
	}
	
	ans := make([]string, numRows)
	direction := 1
	index := 0

	// Iterate through the string
	for _, c := range s {
		// Append the character to the current row
		ans[index] += string(c)

		// Move to the next row
		index += direction

		// If the current row is the first or the last row, then change the direction
		if (index == 0) || (index == numRows-1) {
			direction = -direction
		}
	}
	return strings.Join(ans, "")
}
