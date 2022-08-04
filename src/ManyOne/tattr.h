

#include <stdlib.h>

/**
 * @brief Structure to define thread scheduling parameters
 * 
 */
typedef struct schedParams
{
    unsigned int sc;
    unsigned int ms;
} schedParams;

/**
 * @brief Structure representing thread attributes
 * 
 */
typedef struct thread_attr
{
    void *stack;
    size_t stackSize;
    schedParams schedInterval;
    size_t guardSize;
} thread_attr;

// Attribute modification APIs
int thread_attr_init(thread_attr *);
int thread_attr_destroy(thread_attr *);

size_t thread_attr_getStack(thread_attr *);
int thread_attr_setStack(thread_attr *, size_t);

int thread_attr_setStackAddr(thread_attr *, void *, size_t);

int thread_attr_setSchedInterval(thread_attr *, schedParams);
schedParams *thread_attr_getSchedInterval(thread_attr *);
