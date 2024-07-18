package algorithms

func nearestValidPoint(x int, y int, points [][]int) int {
	minDist := 100000
	minIndex := -1
	for i, point := range points {
		if point[0] == x || point[1] == y {
			dist := abs(x-point[0]) + abs(y-point[1])
			if dist < minDist {
				minDist = dist
				minIndex = i
			}
		}
	}
	return minIndex
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
