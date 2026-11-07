#include <stdio.h>
#include <stdbool.h>

void selectionsort(int num[], int N);
void binarysearchcount(int num[], int N, int target);

int main() {

    int a, target;
    
    scanf("%d %d", &a, &target);
    int num[a];
    
    for (int i = 0; i < a ; ++i) scanf("%d", &num[i]);
    
    selectionsort(num, a);
    binarysearchcount(num, a, target);
    
    return 0;
}

void selectionsort(int num[], int N) {

    int smallsub, temp;
    for (int i = 0; i < N - 1; ++i) {
        smallsub = i;

        for (int j = i; j < N; j++) 
            if(num[smallsub] > num[j]) 
                smallsub = j; 
        
        temp = num[smallsub];
        num[smallsub] = num[i];
        num[i] = temp;
    }
}

void binarysearchcount(int num[], int N, int target) {

    int start, mid, end, count;

    start = 0; end = N - 1; count = 0;

    while (start <= end) {
        ++count;
        mid = (start + end) / 2;

        if (num[mid] == target) break; 
        else if (num[mid] < target) start = mid + 1;
        else end = mid - 1;
    }

	printf("%d\n", count);

    if (num[mid] == target) printf("found\n");
    else printf("not found\n");
}
