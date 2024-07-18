package algorithms

func gcdOfStrings(str1 string, str2 string) string {

	// We use euclidean algorithm to find the greatest common divisor of two strings
	// Let a and b be two integers with a > b, then gcd(a,b) = gcd(a%b, b).

	// Example of euclidean algorithm

	// gcd(1701,3768)
	// 3768 = 1701 * 2 + 366
	// 1701 = 366 * 4 + 237
	// 366 = 237 * 1 + 129
	// 237 = 129 * 1 + 108
	// 129 = 108 * 1 + 21
	// 108 = 21 * 5 + 3
	// 21 = 3 * 7 + 0

	// gcd(1701,3768) = 3

	// Find the length of two strings
	l1, l2 := len(str1), len(str2)

	// If the length of str1 is greater than str2, swap them
	if l1 < l2 {
		str1, str2 = str2, str1
		l1, l2 = l2, l1
	}

	// If l2 is 0, means str1 is the remainder of the previous division
	// Or str1 is the gcd
	if l2 == 0 {
		return str1
	}

	// If part of str1 (larger string) is not equal to str2, return ""
	if str1[:l2] != str2 {
		return ""
	}

	// Find the gcd of str2 and the remainder of str1
	return gcdOfStrings(str1[l2:], str2)
}
