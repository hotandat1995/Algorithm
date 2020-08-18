#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node
{
    int data;
    tree_node *left;
    tree_node *right;
} tree_node;
