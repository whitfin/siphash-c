B = build
BT = $(B)/test
CFLAGS = -g -O3 -ansi -pedantic -Wall -Wextra
PREFIX ?= /usr/local
SRC = main.c src/siphash.c
TEST = test/test.c src/siphash.c

all:            siphash
siphash:        $(SRC)
				mkdir -p $(B)
				$(CC) $(CFLAGS) $^ -o $(B)/$@
clean:
				$(RM) -r $(B)
install:        siphash
				cp -f $(B)/siphash $(PREFIX)/bin/siphash
siphash_test:   $(TEST)
				mkdir -p $(BT)
				$(CC) $^ $(CFLAGS) -o $(BT)/siphash_test