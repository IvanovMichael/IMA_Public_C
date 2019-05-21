#ifndef BINARY_TREE_TREE_H
#define BINARY_TREE_TREE_H

typedef double VALUE;
typedef int KEY;

struct VNV_tree_iter{
    KEY key;
    VALUE value;
    struct VNV_tree_iter *left, *right;
};

struct VNV_tree{
    struct VNV_tree_iter *ROOT;
    int NUMBER;
    int ERROR;
};

int VNV_NEW_TREE(struct VNV_tree*);
int VNV_INSERT(struct VNV_tree*, KEY, VALUE);
int VNV_TRAVERSE(struct VNV_tree*, int (*)(KEY, VALUE*));
VALUE* VNV_FIND(struct VNV_tree*, KEY);

#endif //BINARY_TREE_TREE_H
