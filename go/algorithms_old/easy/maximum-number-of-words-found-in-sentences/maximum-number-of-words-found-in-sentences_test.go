package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	sentences []string
	ans       int
}{
	{
		[]string{"alice and bob love leetcode", "i think so too", "this is great thanks very much"},
		6,
	},

	{
		[]string{"please wait", "continue to fight", "continue to win"},
		3,
	},
}

func Test_mostWordsFound(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 2114. Maximum Number of Words Found in Sentences------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: sentences = %v\n【Output】: %v\n", tc.sentences, mostWordsFound(tc.sentences))
		ast.Equal(tc.ans, mostWordsFound(tc.sentences), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_mostWordsFound(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			mostWordsFound(tc.sentences)
		}
	}
}
