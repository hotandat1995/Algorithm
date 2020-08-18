#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cir_buf_t
{
    int32_t *data;      ///< The head of buffer
    int32_t buf_sz;     ///< Size of buffer
    int32_t start_idx;  ///< Start index
    int32_t end_idx;    ///< End index
} cir_buf_t;



