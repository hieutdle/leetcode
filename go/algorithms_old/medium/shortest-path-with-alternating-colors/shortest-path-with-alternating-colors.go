package algorithms

import "fmt"

const (
	Red = iota
	Blue
)

func shortestAlternatingPaths(n int, redEdges [][]int, blueEdges [][]int) []int {

	red := map[int][]int{}
	blue := map[int][]int{}

	for _, e := range redEdges {
		red[e[0]] = append(red[e[0]], e[1])
	}

	for _, e := range blueEdges {
		blue[e[0]] = append(blue[e[0]], e[1])
	}

	ans := make([]int, n)
	for i := range ans {
		ans[i] = -1
	}

	// TRICK: is node already found, with color combination, like 0_red, 0_blue are diff edge
	seen := map[string]bool{}

	q := [][]int{}

	q = append(q, []int{0, 0, 0}) // node, color, distance

	for len(q) > 0 {

		size := len(q)

		for i := 0; i < size; i++ {
			top := q[0]

			q = q[1:]

			key := fmt.Sprint("%d_%d", top[0], top[1])

			if _, ok := seen[key]; ok {
				continue
			}

			seen[key] = true

			if ans[top[0]] == -1 {
				ans[top[0]] = top[2]
			}

			if top[1] == 0 || top[1] == 1 {
				if _, ok := blue[top[0]]; ok {
					for _, v := range blue[top[0]] {
						q = append(q, []int{v, 2, top[2] + 1})
					}
				}

			}

			if top[1] == 0 || top[1] == 2 {
				if _, ok := red[top[0]]; ok {
					for _, v := range red[top[0]] {
						q = append(q, []int{v, 1, top[2] + 1})
					}
				}

			}

		}

	}

	return ans

}
