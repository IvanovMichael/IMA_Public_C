#include <stdio.h>
#include "tree.h"

int print(KEY key, VALUE *value) {
    printf("%d: %.5f\n", key, *value);
    return 1;
}

int plus(KEY key, VALUE *value) {
    (*value) += 12;
    return 1;
}

int main() {
    struct VNV_tree TREE;
    VNV_NEW_TREE(&TREE);

    int N = 0;
    printf("Enter the size of tree: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        KEY K = 0;
        VALUE V = 0;
        printf("Enter the key of %d leaf: ", i+1);
        scanf("%d", &K);
        printf("Enter the value of %d leaf: ", i+1);
        scanf("%lf", &V);
        VNV_INSERT(&TREE, K, V);
    }

//    VNV_INSERT(&TREE, 1, 3.14);
//    VNV_INSERT(&TREE, -1, 11.5);
//    VNV_INSERT(&TREE, 1, 11.5);
//    VNV_INSERT(&TREE, 18, .01);
//
//    VNV_TRAVERSE(&TREE, plus);
    int n = VNV_TRAVERSE(&TREE, print);

    KEY k = 6;
    VALUE *v = VNV_FIND(&TREE, k);
    if(v == 0) printf("THE KEY WAS NOT FOUND\n");
    else printf("%f\n", *v);


    printf("Hello, World!\n");
    return N;
}