package algorithms

import "sort"

/**
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
	ans := sort.Search(n, func(i int) bool { return isBadVersion(i) })
	return ans
}

func isBadVersion(version int) bool {
	return true
}
