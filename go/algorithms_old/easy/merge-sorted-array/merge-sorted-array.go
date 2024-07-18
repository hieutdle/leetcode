package algorithms

func merge(nums1 []int, m int, nums2 []int, n int)  {
	temp := make([]int,m+n)

	i1,i2 := 0,0

	for j:=0; j < m+n; j ++ {
		// if we have already added all elements in nums2
		// Or nums1[i1] is smaller than nums2[i2]
		// and we have not added all elements in nums1 (to avoid 0s values in nums1)
		if i2 == n || (nums1[i1] <= nums2[i2] && i1 < m){

			// add nums1[i1] to temp
			temp[j] = nums1[i1]

			// move to next element in nums1
			i1++
		} else {
			// add nums2[i2] to temp
			temp[j] = nums2[i2]
			// move to next element in nums2
			i2++
		}
	}

	copy(nums1,temp)
}

