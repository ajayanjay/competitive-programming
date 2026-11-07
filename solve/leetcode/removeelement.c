#include <stdlib.h>
#include <stdio.h>

int removeElements(int* nums, int numsSize, int val) {
	int count = 0;
	int j = numsSize - 1;

	//bruteforce
	for (int i = 0; i < numsSize; ++i)
		if (nums[i] == val) ++count;

	for (int i = 0; i < numsSize - count; ++i) {
		if (nums[i] != val) continue;

		while (j >= 0) {
			if (nums[j] == val) {
				--j;
				continue;
			}
			int temp = nums[j];
			nums[j] = nums[i];
			nums[i] = temp;
			--j;
			break;
		}
	}

	return (numsSize - count);
}

int removeElement (int *nums, int numsSize, int val) {
	int j = numsSize - 1;
	int i = 0;
	while (i <= j) {
		if (nums[i] != val) {++i; continue;}

		// found val
		while (j >= i) {
			if (nums[j] == val) {--j; continue;}

			// found non-val
			nums[i++] = nums[j--];
			break;
		}
	}
	return i;
}

int main(int argc, char const *argv[])
{
	int arr[64], val;
	int size = 0;

	for (int i = 0; i < 64; ++i) {
		scanf("%d", &arr[size++]);

		if (getchar() == '\n') break;
	}

	scanf("%d", &val);

	printf("%d\n", removeElement(arr, size, val ));

	for (int i = 0; i < size; ++i)
		printf("%d", arr[i]);

	system("pause");
	return 0;
}