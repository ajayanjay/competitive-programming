#include <stdio.h>
#define sizea 2
#define sizeb 1

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

	int k = 0, i = 0, j = 0;

	int lenMerged = nums1Size + nums2Size;

	int mergedSize = (lenMerged) / 2 + 1;
	int mergedArr[mergedSize];

	while (k < mergedSize) {

		if (i == nums1Size) {
			while (k < mergedSize) mergedArr[k++] = nums2[j++];
			break;
		}

		if (j == nums2Size) {
			while (k < mergedSize) mergedArr[k++] = nums1[i++];
			break;
		}

		if (nums1[i] < nums2[j]) {
			mergedArr[k++] = nums1[i++];
		} else {
			mergedArr[k++] = nums2[j++];
		} 

	}	

	if (lenMerged % 2 == 0)
		return (mergedArr[k - 1] + mergedArr[k - 2]) * 0.5;
	else
		return mergedArr[k - 1];

}

int main() {

	int a[sizea], b[sizeb];

	for (int i = 0; i < sizea; ++i)
		scanf("%d", &a[i]);

	for (int i = 0; i < sizeb; ++i)
		scanf("%d", &b[i]);

	printf("%f", findMedianSortedArrays(a, sizea, b, sizeb));

}