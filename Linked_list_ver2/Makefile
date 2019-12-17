llist_driver: llist.o main.c
	gcc -Wall -Wextra llist.o main.c -o llist_driver

llist.o: llist.h llist.c
	gcc -Wall -Wextra -fPIC llist.h -c llist.c

clean:
	rm -rf *.o *.gch llist_driver