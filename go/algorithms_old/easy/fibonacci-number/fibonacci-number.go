package algorithms

var cache = make([]int, 31)

func fib(n int) int {
	if n == 0 || n == 1 {
		return n
	}

	// Because we have 0 <= n <= 30 constraints, we can use cache
	ans := cache[n]

	// if the value is not cached, calculate it
	if ans == 0 {
		ans = fib(n-1) + fib(n-2)
		cache[n] = ans
	}
	return ans
}
