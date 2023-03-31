#include <iostream>
#include <ctime>
#include <stdlib.h>

int main() {
    time_t t = time(nullptr);
    srand((size_t) t);
1
    size_t count = 0;
    printf("Please enter the amount of numbers:\n");
    scanf("%zu", &count);
    FILE *fp;
    fp = fopen("result.txt", "w");
    if (fp) {
        for (size_t i = 0; i < count; i++) {
            double volt = 4.5 + 1.0 * rand() / RAND_MAX;
            fprintf(fp, "%f\n", volt);
        }
        fclose(fp);
    }
    return 0;
}
