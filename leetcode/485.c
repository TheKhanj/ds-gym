int findMaxConsecutiveOnes(int *nums, int numsSize) {
	int maxN = 0;
	for (int i = 0; i < numsSize;) {
		int x = nums[i];
		int count = 0;
		while (i < numsSize && nums[i] == x) {
			count++;
			i++;
		}

		if (x == 1 && count > maxN) {
			maxN = count;
		}
	}

	return maxN;
}
