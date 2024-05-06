CC=gcc
CFLAGS=-I.
DEPS = queue.h stack.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


%.c:
main: main.o
	$(CC) -o main main.o