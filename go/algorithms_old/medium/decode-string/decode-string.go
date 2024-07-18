package algorithms

import (
	"github.com/goldennovember/leetcode-go/gods"
	"strconv"
	"strings"
)

type Stack = gods.Stack

func decodeString(s string) string {

	stack := Stack{}

	// Create a string to store the result
	ans := ""

	// Iterate through the string
	for _, c := range s {

		// If the character is a closing bracket
		if c == ']' {

			// Create a temp string to store the string in the brackets
			str := ""

			// Pop the stack until we see a opening bracket
			for stack.Peek() != "[" {
				str = stack.Pop().(string) + str
			}

			// Pop the opening bracket
			stack.Pop()

			// Create a string to store the number
			// We can just not pop one more element for the number
			// Because we can have a number with more than one digit like 100
			num := ""

			// Pop the stack until we see a non-number
			for stack.Size() > 0 && stack.Peek().(string) >= "0" && stack.Peek().(string) <= "9" {
				num = stack.Pop().(string) + num
			}

			// Convert the number to an integer
			n, _ := strconv.Atoi(num)

			// Repeat the string n times
			repeat := strings.Repeat(str, n)

			// Push the string back to the stack
			stack.Push(repeat)

		} else {
			stack.Push(string(c))
		}
	}

	for stack.Size() > 0 {
		ans = stack.Pop().(string) + ans
	}

	return ans
}
