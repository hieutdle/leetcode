package gods

var Null = -1 << 63

type NaryNode struct {
	Val      int
	Children []*NaryNode
}

// Source: halfrost

func Ints2NaryNode(nodes []int) *NaryNode {
	root := &NaryNode{}
	if len(nodes) > 1 {
		root.Val = nodes[0]
	}
	queue := []*NaryNode{}
	queue = append(queue, root)
	i := 1
	count := 0
	for i < len(nodes) {
		node := queue[0]

		childrens := []*NaryNode{}
		for ; i < len(nodes) && nodes[i] != Null; i++ {
			tmp := &NaryNode{Val: nodes[i]}
			childrens = append(childrens, tmp)
			queue = append(queue, tmp)
		}
		count++
		if count%2 == 0 {
			queue = queue[1:]
			count = 1
		}
		if node != nil {
			node.Children = childrens
		}
		i++
	}
	return root
}
