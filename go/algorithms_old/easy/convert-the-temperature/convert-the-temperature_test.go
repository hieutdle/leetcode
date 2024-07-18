package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	celsius float64
	ans     []float64
}{

	{
		36.50,
		[]float64{309.65, 97.70},
	},

	{122.11,
		[]float64{395.26, 251.798},
	},
}

func Test_convertTemperature(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 2469. Convert the Temperature------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: celcius = %v\n【Output】: %v\n", tc.celsius, convertTemperature(tc.celsius))
		ast.Equal(tc.ans, convertTemperature(tc.celsius), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_convertTemperature(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			convertTemperature(tc.celsius)
		}
	}
}
