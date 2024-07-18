package algorithms

func isSubsequence(s string, t string) bool {
	i := 0
	l := len(s)

	for _, v := range t {
		if i < l && s[i] == byte(v) {
			i++
		}
	}

	return len(s) == i
}
