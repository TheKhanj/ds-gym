int removeElement(int *nums, int numsSize, int val) {
	int eq = 0;
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] == val) {
			eq++;
			continue;
		}

		nums[i - eq] = nums[i];
	}

	return numsSize - eq;
}
