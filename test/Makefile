OPT ?= -g3 -Og

# Required build variables
CFLAGS += $(OPT) -std=c99 -pedantic -Wall -Wextra
LDFLAGS += -I../inc/

all: test
test: test.c ../src/sim800c.c minctest.h
