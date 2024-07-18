package algorithms

func moveZeroes(nums []int)  {

	// If the length of the array is 0 or 1, just return the array
	if len(nums) == 0 || len(nums) == 1 {
		return
	}

	j := 0


	for i := 0; i < len(nums); i ++{
		// If the value is 0, we don't do anything
		// If not (the value is not 0)
		// Swap the non-zero value (pointer i) with the zero number (pointer j)
		if nums[i] != 0 {
			if i != j {
				nums[i], nums[j] = nums[j], nums[i]
			}
			j++
		}
	}
}