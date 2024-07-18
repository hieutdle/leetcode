package algorithms

func restoreString(s string, indices []int) string {

	ans := make([]byte, len(s))

	for i, v := range indices {
		ans[v] = s[i]
	}

	return string(ans)
}
