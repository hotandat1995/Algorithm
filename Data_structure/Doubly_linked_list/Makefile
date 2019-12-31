dllist_driver:	dllist.o	main.c
	gcc	main.c	dllist.o	-o	dllist_driver

dllist.o:	dllist.h	dllist.o
	gcc	dllist.h	-c	dllist.c

clean:
	rm -rf *.o *.gch dllist_driver