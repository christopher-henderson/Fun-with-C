#include <stdlib.h>
#include <stdio.h>

struct str_node {
    char value;
    struct str_node* next;
} Node;

struct str_builder {
    struct str_node* front;
    struct str_node* back;
    unsigned int size;
} Builder;

struct str_builder make_builder() {
    struct str_builder builder;
    builder.front = NULL;
    builder.back = NULL;
    builder.size = 0;
    return builder;
}

struct str_node* make_node(char c) {
    struct str_node* node = (struct str_node*) malloc(sizeof(struct str_node));
    node->value = c;
    node->next = NULL;
    return node;
}

void delete(struct str_builder builder) {
    struct str_node* node = builder.front;
    struct str_node* next_node;
    while (node) {
        next_node = node->next;
        free(node);
        node = next_node;
    }
}

void append(struct str_builder* builder, char* string) {
    char c;
    for (int i = 0; (c = *(string + i)); i++) {
        struct str_node* new_node = make_node(c);
        if (builder->front == NULL) {
            builder->front = new_node;
        }
        else if (builder->back == NULL) {
            builder->back = new_node;
            builder->front->next = new_node;
        } else {
            builder->back->next = new_node;
            builder->back = new_node;
        }
        builder->size++;
    }
}

char* build(struct str_builder* builder) {
    char* string = (char*) malloc(sizeof(char)*builder->size);
    struct str_node* node = builder->front;
    for (int i=0; node ; i++) {
        *(string + i) = node->value;
        node = node->next;
    }
    *(string + builder->size) = '\0';
    return string;
}

int main() {
    struct str_builder builder = make_builder();
    append(&builder, "hello, ");
    append(&builder, "world!");
    printf("%s\n", build(&builder));
    delete(builder);
    return 0;
}