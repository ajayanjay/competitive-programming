#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize) {
 	int n = numsSize;
    for(int i=0;i<n;i++){
        while(nums[i]>0 && nums[i]<=n && nums[i]!=(i+1)){
            
            if(nums[nums[i]-1]==nums[i]) break;

            int temp = nums[i];
            nums[i] = nums[nums[i] - 1];
            nums[nums[i] - 1] = temp;
        }
    }

    for (int i = 0; i < n; ++i)
    	printf("%d ", nums[i]);

    for(int i=0;i<n;i++){
        if(nums[i]!=(i+1)) return i+1;
    }
    return n+1;   
}

int main(void) {
	int arr[] = {5, 4, 3, 2, 1};

	int numsSize = 5;

	printf("\n%d\n", firstMissingPositive(arr, numsSize));
}