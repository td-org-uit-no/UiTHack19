CC = gcc
CFLAGS = -Wall -Wextra -std=gnu11 -O0# -DDEBUG
CLIBS =

.PHONY: all clean
all: encrypter cracker

encrypter: encrypter.o
	$(CC) -o $@ $(CFLAGS) $^ $(CLIBS)

cracker: crack.o
	$(CC) -o $@ $(CFLAGS) $^ $(CLIBS)

%.o: %.c *.h Makefile
	$(CC) -c -o $@ $(CFLAGS) $<

clean:
	@rm -fv *.o encrypter cracker

