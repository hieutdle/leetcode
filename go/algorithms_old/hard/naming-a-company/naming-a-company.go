package algorithms

func distinctNames(ideas []string) (ans int64) {
	var m [26]map[string]bool
	for i := range m {
		m[i] = make(map[string]bool)
	}
	for _, idea := range ideas {
		m[idea[0]-'a'][idea[1:]] = true
	}
	for i := 0; i < 25; i++ {
		for j := i + 1; j < 26; j++ {
			numOfMutual := 0
			for ideaA := range m[i] {
				if m[j][ideaA] {
					numOfMutual++
				}
			}
			ans += int64(2 * (len(m[i]) - numOfMutual) * (len(m[j]) - numOfMutual))
		}
	}
	return
}
