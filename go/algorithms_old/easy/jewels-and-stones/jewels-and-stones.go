package algorithms

func numJewelsInStones(jewels string, stones string) int {
	count := 0
	m := map[rune]bool{}

	for _, v := range jewels {
		m[v] = true
	}

	for _, v := range stones {
		if m[v] {
			count++
		}
	}
	return count
}
