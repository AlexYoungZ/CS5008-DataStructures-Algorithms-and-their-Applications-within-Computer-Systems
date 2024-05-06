CC=gcc
CFLAGS=-I.
DEPS=list.h ternarySearchTree.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


%.c:
autocomplete: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
