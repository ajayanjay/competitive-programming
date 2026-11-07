#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {

	int start = 0;
	int end = numsSize - 1;

	int mid;

	while (start < end) {

		mid = (start + end) / 2;

		if (nums[mid] == target) return mid;

		else if (nums[mid] > target) end = mid - 1;

		else if (nums[mid] < target) start = mid + 1;

	}

	return (start + (target > nums[start]));

}

int main(int argc, char const *argv[]) {

	int arr[16], count = 0;
	for (int i = 0; i < 16; ++i) {
		
		scanf("%d", &arr[i]);
		++count;

		if (getchar() == '\n') break;
	}

	int target;
	scanf("%d", &target);

	printf("%d", searchInsert(arr, count, target));

	system("pause");

	return 0;
}