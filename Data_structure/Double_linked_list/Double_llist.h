struct node
{
    void *value;
    struct node *next;
    struct node *prev;
};

typedef struct node *dllist;

dllist *dllist_create(void *data);

void dllist_free(dllist *dllist);

void dllist_push(dllist *dlist, void *data);

void *dllist_pop(dllist *dlist);

void dllist_print(dllist *list, void (*print)(void *data));

void dllist_reverse(dllist *head);


