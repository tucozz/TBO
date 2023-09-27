#include "BST.h"

typedef struct
{
    void *key;
    void *val;
} KeyValPair;

typedef struct{
    KeyValPair *kvp;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

struct BinTree{
    Node *root;
    CmpFn cmp_fn;
    KeyDestroyFn key_destroy_fn;
    ValDestroyFn val_destroy_fn;
};

KeyValPair *key_val_pair_construct(void *key, void *val){
    KeyValPair *kvp = malloc(sizeof(KeyValPair));
    kvp->key = key;
    kvp->val = val;

    return kvp;
}

void key_val_pair_destroy(KeyValPair *kvp){
    free(kvp);
}

Node *node_construct(void *key, void *value, Node *left, Node *right, Node* parent){
    Node *node = malloc(sizeof(Node));
    node->kvp = key_val_pair_construct(key, value);
    node->right = left;
    node->left = right;
    node->parent = parent;

    return node;
}

void node_destroy(Node *node, KeyDestroyFn key_destroy_fn, ValDestroyFn val_destroy_fn){
    key_destroy_fn(node->kvp->key);
    val_destroy_fn(node->kvp->val);
    key_val_pair_destroy(node->kvp);
    free(node);
}

BinTree_construct(size_t size, CmpFn cmp_fn, KeyDestroyFn key_destroy_fn, ValDestroyFn val_destroy_fn){
    BinTree *bintree = malloc(sizeof(BinTree));
    bintree->cmp_fn = cmp_fn;
    bintree->key_destroy_fn = key_destroy_fn;
    bintree->val_destroy_fn = val_destroy_fn;
}

_add_recursive(Node *node, key_data_type key, val_data_type val, CmpFn cmp_fn, KeyDestroyFn key_destroy_fn, ValDestroyFn val_destroy_fn){

}

BinTree_add(BinTree *bt, void *key, void *value){
    bt->root = _add_recursive(bt->root, key, value, bt->cmp_fn, bt->key_destroy_fn, bt->val_destroy_fn);
}

BinTree_free(BinTree *bt){
    free(bt->cmp_fn);
    free(bt->key_destroy_fn);
    free(bt->val_destroy_fn);
    //codigo pra dar free node por node
    free(bt);
}
