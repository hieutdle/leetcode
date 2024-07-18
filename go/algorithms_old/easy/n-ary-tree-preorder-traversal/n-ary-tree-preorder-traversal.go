package algorithms

import "github.com/goldennovember/leetcode-go/gods"

type Node = gods.NaryNode

func preorder(root *Node) []int {
	ans := []int{}

	// pass the address of answer slice
	travel(root,&ans)
	return ans
}

func travel(root *Node, ans *[]int){
	if root != nil {
		// *[]int is a type, it means the type is pointer to []int slice
		// which means ans is now a address
		// *ans to dereferencing or take the value the pointer pointing to
		*ans = append(*ans, root.Val)
		for i := 0; i < len(root.Children); i++ {
			// ans is address of original ans slice
			travel(root.Children[i], ans)
		}
	}
}
