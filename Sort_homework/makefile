OBJ = main.o bubble.o insert.o select.o quick.o merge.o radix.o heap.o
CFLAGS = -std=c99 -lm

%.o : %.c sort.h
	gcc -c -lm -o $@ $< $(CFLAGS)

sort: $(OBJ)
	gcc -lm -o $@ $^ $(CFLAGS)
