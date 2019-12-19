dllist_driver: Double_llist.o main.c
	gcc -Wall -Wextra Double_llist.o main.c -o dllist_driver

llist.o: llist.h llist.c
	gcc -Wall -Wextra -fPIC Double_llist.h -c Double_llist.c

clean:
	rm -rf *.o *.gch dllist_driver