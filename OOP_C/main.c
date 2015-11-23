#include <stdio.h>
#include "weight_lifter.c"

int main() {
    struct WeightLifter* beefy = WeightLifterFactory(140, 475);
    printf("Beefy's weight is %g and his max out is %i\n", beefy->weight, beefy->max);
    beefy->max_out(beefy);
    printf("Beefy's weight is %g and his max out is %i\n", beefy->weight, beefy->max);
    return 0;
}