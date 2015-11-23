#include <stdlib.h>

struct WeightLifter {
    float weight;
    unsigned int max;
    void (*max_out)(struct WeightLifter*);
    void (*eat)(struct WeightLifter*);
};

void max_out(struct WeightLifter*);
void eat(struct WeightLifter*);
struct WeightLifter* WeightLifterFactory(float, unsigned int);

struct WeightLifter* WeightLifterFactory(float weight, unsigned int max) {
        struct WeightLifter* beefy = (struct WeightLifter*) malloc(sizeof(struct WeightLifter));
        beefy->weight = weight;
        beefy->max = max;
        beefy->eat = eat;
        beefy->max_out = max_out;
        return beefy;
}

void max_out(struct WeightLifter* beefy) {
    beefy->max += 5;
    beefy->eat(beefy);
}

void eat(struct WeightLifter* beefy) {
    beefy->weight += 0.5;
}
