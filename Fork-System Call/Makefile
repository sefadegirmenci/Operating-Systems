TARGETS=fork

CC_C=gcc

CFLAGS= -Wall -g -Werror

all: clean $(TARGETS)

$(TARGETS):
	$(CC_C) $(CFLAGS) $@.c -o $@

clean:
	rm -f $(TARGETS)

test: all
	./$(TARGETS)