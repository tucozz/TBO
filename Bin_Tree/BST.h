#include <stdlib.h>

typedef struct BinTree BinTree;
typedef int key_data_type;
typedef void * val_data_type;

typedef int (*CmpFn)(void *k1, void *k2);
typedef void (*KeyDestroyFn)(void *key);
typedef void (*ValDestroyFn)(void *val);