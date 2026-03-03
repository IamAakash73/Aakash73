#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() 
{
    int n;
    scanf("%d", &n);
    int size = 2 * n - 1; 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int top_dist = i;
            int bottom_dist = size - 1 - i;
            int left_dist = j;
            int right_dist = size - 1 - j;
            int min_dist = top_dist;
            if (bottom_dist < min_dist) min_dist = bottom_dist;
            if (left_dist < min_dist) min_dist = left_dist;
            if (right_dist < min_dist) min_dist = right_dist;
            printf("%d ", n - min_dist);
        }
        printf("\n"); 
    }
    
    return 0;
}
