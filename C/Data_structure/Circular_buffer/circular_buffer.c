#include "circular_buffer.h"

cir_buf_t *init_cir_buf(int32_t new_buf_size)
{
    cir_buf_t *new_buf = (cir_buf_t *)malloc(sizeof(cir_buf_t));

    if (NULL == new_buf)
    {
        printf("Can't allocate new cirular buffer!\n");
        return new_buf;
    }

    new_buf->data = (int *)malloc(sizeof(int) * new_buf_size);
    if (NULL == new_buf->data)
    {
        printf("Can't allocate new data buffer!\n");
        free(new_buf);
        return NULL;
    }
    new_buf->buf_sz = new_buf_size;
    new_buf->start_idx = 0;
    new_buf->end_idx = 0;

    return new_buf;
}

bool is_full(cir_buf_t *self)
{
  if ((self->start_idx - self->end_idx) == 1)
  {
    return true;
  }
  else
  {
    printf("The buffer is full!\n");
    return false;
  }
}

bool is_empty(cir_buf_t *self)
{
  if ((self->start_idx == self->end_idx))
  {
    return true;
  }
  else
  {
    printf("The buffer is empty!\n");
    return false;
  }
}

bool push_data(cir_buf_t *self, int32_t input)
{
  if (is_full(self))
  {
    return false;
  }
  else
  {
    /* Add data */
    self->data[self->end_idx] = input;
    /* Increase address */
    self->end_idx = (self->end_idx + 1) % self->buf_sz;

    return true;
  }
}

bool remove_last(cir_buf_t *self)
{
  if (is_empty(self))
  {
    return false;
  }
  else
  {
    /* Decrease address */
    self->end_idx = (self->end_idx + self->buf_sz -1) % self->buf_sz;

    return true;
  }
}

bool pop_data(cir_buf_t *self, int32_t *output)
{
  int32_t *data = output;
  if (is_empty(self))
  {
    return false;
  }
  else
  {
    /* Get start data */
    *data = self->data[self->start_idx];
    /* Increase the start address */
    self->start_idx = (self->start_idx + 1) % self->buf_sz;
    return true;
  }
}

void deinit_cir_buf(cir_buf_t *buff)
{
  free(buff->data);
  free(buff);
  printf("The buffer is destroy!\n");
}