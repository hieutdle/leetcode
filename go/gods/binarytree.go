package gods

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func (t *TreeNode) Insert(val int) {
	if t.Val < val {

		// move right
		if t.Right == nil {
			t.Right = &TreeNode{Val: val}
		} else {
			t.Right.Insert(val)
		}
	} else {
		// move left
		if t.Left == nil {
			t.Left = &TreeNode{Val: val}
		} else {
			t.Left.Insert(val)
		}
	}
}

func (t *TreeNode) Search(val int) bool {
	if t == nil {
		return false
	}

	if t.Val < val {
		return t.Right.Search(val)
	} else {
		return t.Left.Search(val)
	}

	return true
}

func (t *TreeNode) Delete(val int) {
	if t == nil {
		return
	}

	if t.Val < val {
		t.Right.Delete(val)
	} else {
		t.Left.Delete(val)
	}

	if t.Left == nil && t.Right == nil {
		t = nil
	}
}

// Source: halfrost
func Ints2TreeNode(ints []int) *TreeNode {
	n := len(ints)
	if n == 0 {
		return nil
	}

	root := &TreeNode{
		Val: ints[0],
	}

	queue := make([]*TreeNode, 1, n*2)
	queue[0] = root

	i := 1
	for i < n {
		node := queue[0]
		queue = queue[1:]

		if i < n && ints[i] != Null {
			node.Left = &TreeNode{Val: ints[i]}
			queue = append(queue, node.Left)
		}
		i++

		if i < n && ints[i] != Null {
			node.Right = &TreeNode{Val: ints[i]}
			queue = append(queue, node.Right)
		}
		i++
	}

	return root
}
