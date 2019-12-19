/* llist.h
 * Generic Linked List
 */

typedef enum result_type
{
    SUCCESS = 0,
    FAIL = 1
} result_t;

struct node
{
    void *data;
    struct node *next;
};

typedef struct node *llist;

/* llist_create: Create a linked list */
llist *llist_create(void *data);

/* llist_free: Free a linked list */
void llist_free(llist *list);

/* llist_add_inorder: Add to sorted linked list */
int llist_add_inorder(void *data, llist *list,
                      int (*comp)(void *, void *));

/* llist_push: Add to head of list */
void llist_push(llist *list, void *data);

/* llist_pop: remove and return head of linked list */
void *llist_pop(llist *list);

/* llist_print: print linked list */
void llist_print(llist *list, void (*print)(void *data));

/* llist_reverse: reverse all member in list*/
void llist_reverse(llist *head);

/* llist_travel: travel to the position you need
    return:
        address of that position: if it can
        NULL: if that position is not available
*/
result_t llist_rotate_from(llist *head, int position);

struct node *llist_travel_to(llist *head, int position);

