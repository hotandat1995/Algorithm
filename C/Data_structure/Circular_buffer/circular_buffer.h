#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY_BUF 0
typedef struct cir_buf_t
{
    int32_t *data;      ///< The head of buffer
    int32_t buf_sz;     ///< Size of buffer
    int32_t start_idx;  ///< Start index
    int32_t end_idx;    ///< End index
    int32_t curr_sz;    ///< Current size
} cir_buf_t;

typedef struct cir_buf_handler_t
{
    cir_buf_t *buffer;
    cir_buf_t* (*init_cir_buf)(int32_t);
    bool (*push_data)(cir_buf_t *, int32_t);
    bool (*remove_last)(cir_buf_t *);
    bool (*pop_data)(cir_buf_t *, int32_t *);
    void (*deinit_cir_buf)(cir_buf_t *buff);
} cir_buf_handler_t;

void config_cir_buf_handler(cir_buf_handler_t *handler, int32_t size);