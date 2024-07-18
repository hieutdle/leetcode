package algorithms

import "math/bits"

func hammingWeight(num uint32) int {
	return bits.OnesCount32(num)
}
