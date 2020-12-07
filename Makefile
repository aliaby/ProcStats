CC=g++
CFLAGS=-I.
DEPS = ProcStats.h ProcStatsCalculator.h
OBJ = main.o ProcStats.o ProcStatsCalculator.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o