#include "tree.h"
#include <stdlib.h>

int VNV_NEW_TREE(struct VNV_tree *this){
    this -> NUMBER = 0;
    this -> ERROR = 0;
    this -> ROOT = 0;

    return 0;
}

/**
 *
 *
 * @param this - iterator
 * @param key - tree key
 * @param value - tree value
 * @return error code
 */
int VNV_ITER_INSERT(struct VNV_tree_iter **this, KEY *key, VALUE *value){
    if((*this) == 0){
        (*this) = malloc(sizeof(struct VNV_tree_iter));
        (*this)->key = *key;
        (*this)->value = *value;
        (*this)->right = 0;
        (*this)->left = 0;
        return 1;
    }
    else if((*this) -> key < *key){
        return VNV_ITER_INSERT(&(*this) -> right, key, value);
    }
    else if((*this) -> key > *key){
        return VNV_ITER_INSERT(&(*this) -> left, key, value);
    }
    else{
        (*this) -> value = *value;
        return 0;
    }
}

int VNV_INSERT(struct VNV_tree *this, KEY key, VALUE value){
    this -> NUMBER += VNV_ITER_INSERT(&this -> ROOT, &key, &value);
    return 0;
}

int VNV_ITER_TRAVERSE(struct VNV_tree_iter *this, int (*func)(KEY, VALUE*)){
    if(this == 0) return 0;
    return
            VNV_ITER_TRAVERSE(this->left, func) +
            func(this -> key, &this->value) +
            VNV_ITER_TRAVERSE(this->right, func);
}

int VNV_TRAVERSE(struct VNV_tree *this, int (*func)(KEY, VALUE*)){
    return (this -> NUMBER != VNV_ITER_TRAVERSE(this -> ROOT, func));
}

struct VNV_tree_iter* VNV_ITER_FIND(struct VNV_tree_iter *this, KEY *key){
    if(this == 0) return 0;
    if(this -> key < *key) return VNV_ITER_FIND(this -> right, key);
    if(this -> key > *key) return VNV_ITER_FIND(this -> left, key);
    return this;
}

VALUE* VNV_FIND(struct VNV_tree *this, KEY key){
    struct VNV_tree_iter *found = VNV_ITER_FIND(this -> ROOT, &key);
    if (found == 0) return 0;
    return &found -> value;
}
