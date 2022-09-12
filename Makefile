SRC := src/main.c src/utility/LinkedList.c src/utility/RunnableList.c src/utility/Runnable.c
NAME := demo

CC ?= gcc
CFLAGS ?= -O2 -Wall -Wextra -pedantic -std=gnu99 
LDFLAGS ?=  

prefix ?= /usr
bindir ?= $(prefix)/bin
DESTDIR ?= build/

all: $(NAME)

$(NAME): $(SRC)
	mkdir -p $(DESTDIR)
	$(CC) $(CFLAGS) $(filter %.c,$^) $(LDFLAGS) -o $(DESTDIR)/$@

clean:
	rm -f $(DESTDIR)/$(NAME)
	rm -f $(patsubst %.c,%.o,$(filter %.c, $(SRC)))

install: $(NAME)
	mkdir -p $(DESTDIR)$(abspath $(bindir))
	cp $^ $(DESTDIR)$(abspath $(bindir))
	chmod 0755 $(DESTDIR)$(abspath $(bindir))/$^