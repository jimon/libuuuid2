CC = cc
#CC = gcc48
CFLAGS  = -g  -O0 -Wall 
INCLUDES=-I/usr/include -I/usr/local/include -I./include
LDFLAGS=-L/usr/lib -L/usr/local/lib  

LOCAL_LIB_SRC=
DEFS=
LIBS=

BIN_SRC=$(wildcard bin/*.c)
BIN_OBJ=$(BIN_SRC:.c=.o)
BIN_EXEC=$(BIN_SRC:.c=)

LIB_SRC=$(wildcard src/*.c)
LIB_OBJ=$(LIB_SRC:.c=.o)

all:  $(LIB_SRC) $(LIB_OBJ) $(BIN_SRC) $(BIN_OBJ) $(BIN_EXEC) 

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDES) $(DEFS)

%: %.o $(LOCAL_LIB_OBJ) 
	$(CC) $(LDFLAGS) $(LIBS) $(LIB_OBJ) $(DEFS) -o $@ $^

clean:
	rm -f  $(LIB_OBJ) $(BIN_OBJ) $(BIN_EXEC) 

