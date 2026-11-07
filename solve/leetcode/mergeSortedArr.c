#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    
    int len = m + n;

    int numstemp[len]; 

    int i = 0, j = 0, k = 0;

    while (i < len) {

        if (j >= m) {while (i < len) numstemp[i++] = nums2[k++]; break;}
        if (k >= n) {while (i < len) numstemp[i++] = nums1[j++]; break;}

        if (nums1[j] <= nums2[k])
          numstemp[i++] = nums1[j++];
        else 
          numstemp[i++] = nums2[k++];

    }

    for (int i = 0; i < len; ++i) {
        nums1[i] = numstemp[i];
	}

}

#define nums1S 16
#define nums2S 4

int main(int argc, char const *argv[])
{
    int nums1[nums1S];
    int nums2[nums2S];

    int count1 = 0, count2 = 0;

    for (int i = 0; i < nums1S; ++i) {
        scanf("%d", &nums1[i]);

        if (nums1[i] != 0) ++count1;

        if (getchar() == '\n') break;
    }

    for (int i = 0; i < nums2S; ++i) {
        scanf("%d", &nums2[i]);
        ++count2;

        if (getchar() == '\n') break;
    }

    merge(nums1, nums1S, count1, nums2, nums2S, count2);

    for (int i = 0; i < count1 + count2; ++i)
        printf("%d ", nums1[i]);

    return 0;
}
