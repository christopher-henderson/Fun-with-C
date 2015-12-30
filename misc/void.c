#include <stdio.h>

typedef struct Parent {
    int a;
    char* string;
    float third;
} Parent;

typedef struct Child {
    int a;
    int b;
} Child;

typedef struct Unrelated {
    char c;
    float d;
} Unrelated;

int castable_return(void* obj) {
    return ((Parent*) obj)->a;
}

char* uncastable_return(void* obj) {
    return ((Parent*) obj)->string;
}

float out_of_bounds(void* obj) {
    return ((Parent*) obj)->third;
}

int main() {
    struct Child child;
    child.a = child.b = 5;
    struct Unrelated unrelated;
    unrelated.c = 'a';
    unrelated.d = 49.99;
    printf("Object's 'a' field evaluated to %i\n", castable_return((void*) &child));
    printf("Object's 'a' field evaluated to %i\n", castable_return((void*) &unrelated));

    printf("Object's 'third' field evaluated to %i\n", out_of_bounds((void*) &child));
    printf("Object's 'third' field evaluated to %i\n", out_of_bounds((void*) &unrelated));
    
    printf("Object's 'string' field evaluated to %i\n", uncastable_return((void*) &child));
    printf("Object's 'string' field evaluated to %i\n", uncastable_return((void*) &unrelated));
    /**
        Object's 'a' field evaluated to 5
        Object's 'a' field evaluated to 97
        Object's 'third' field evaluated to 73832
        Object's 'third' field evaluated to 73832
        Object's 'string' field evaluated to 1732542518
        Object's 'string' field evaluated to 5

        Lesson learned:
            Casting from a void pointer to some other pointer appears to always
            work. Accessing members of incorrect casts "work" in that there isn't a
            trap as long as the resulting types can be implicitly cast, but the
            results are surprising. Accessing 'a' in this case appears to simply access
            the first defined member of the structure.

            Accessing a field outside of memory produced the same integer
            for the two different objects. Interesting.

            Of course, mixing a return of a char* with an int and float just
            results in nonsense.
    */
    return 0;
}
