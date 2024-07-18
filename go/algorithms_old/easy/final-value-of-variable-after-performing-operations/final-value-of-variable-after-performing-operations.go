package algorithms

func finalValueAfterOperations(operations []string) int {
	value := 0

	// You just need to check the middle character
	for _, v := range operations {
		if v[1] == '+' {
			value++
		} else {
			value--
		}
	}

	return value
}
