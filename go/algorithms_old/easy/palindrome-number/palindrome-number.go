package algorithms

import "strconv"

func isPalindrome(x int) bool {

	// When x < 0, x is not a palindrome
	if x < 0 {
		return false
	}

	// if the last digit of the number is 0 (x%10 == 0)
	// the first digit of the number also needs to be 0
	// Only 0 satisfy this property.
	if x == 0 {
		return true
	}
	if x%10 == 0 {
		return false
	}

	// Convert the number to string
	s := strconv.Itoa(x)

	// Loop to check if we can read the same forward and backward.
	// the middle digit doesn't matter in palindrome(it will always equal to itself)

	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		if s[i] != s[j] {
			return false
		}
	}

	return true
}

// Solve without converting the integer to a string
func isPalindrome2(x int) bool {

	// When x < 0, x is not a palindrome
	if x < 0 {
		return false
	}

	// if the last digit of the number is 0 (x%10 == 0)
	// the first digit of the number also needs to be 0
	// Only 0 satisfy this property.
	if x == 0 {
		return true
	}
	if x%10 == 0 {
		return false
	}

	revertedNumber := 0
	for x > revertedNumber {
		revertedNumber = revertedNumber*10 + x%10
		x /= 10
	}

	// When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
	// Input is 12321 => we get x = 12, revertedNumber = 123/10 = 12

	return x == revertedNumber || x == revertedNumber/10

}
