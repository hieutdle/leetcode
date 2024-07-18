package algorithms

import "strings"

func reverseWords(s string) string {
	ans := strings.Fields(s)
	for i := 0; i < len(ans); i++ {
		temp := []byte(ans[i])
		reverseString(temp)
		ans[i] = string(temp)
	}
	return strings.Join(ans, " ")
}

func reverseString(s []byte) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}
