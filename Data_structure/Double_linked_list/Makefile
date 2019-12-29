dllist_driver: Doubly_llist.o main.c
	gcc -Wall -Wextra Doubly_llist.o main.c -o dllist_driver

llist.o: llist.h llist.c
	gcc -Wall -Wextra -fPIC Doubly_llist.h -c Doubly_llist.c

clean:
	rm -rf *.o *.gch dllist_driver