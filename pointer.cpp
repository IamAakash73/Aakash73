#include <stdio.h>

void update(int *a, int *b) {
    // Store original values to avoid using the updated 'a' for 'b'
    int temp_a = *a;
    int temp_b = *b;
    
    // Set 'a' to the sum
    *a = temp_a + temp_b;
    
    // Set 'b' to the absolute difference
    if (temp_a > temp_b) {
        *b = temp_a - temp_b;
    } else {
        *b = temp_b - temp_a;
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    // Read input (e.g., 4 5)
    if (scanf("%d %d", &a, &b) != 2) return 0;
    
    update(pa, pb);
    
    // Print the sum and absolute difference
    printf("%d\n%d", a, b);

    return 0;
}
