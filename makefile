CC = gcc
CFLAGS = -Wall -g
OBJS = passwordgen.o hashset.o
TARGET = passgenerator

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lpthread -lm

passwordgen.o: passwordgen.c hash.h
	$(CC) $(CFLAGS) -c passwordgen.c

hashset.o: hashset.c hash.h
	$(CC) $(CFLAGS) -c hashset.c

clean:
	rm -f $(OBJS) $(TARGET)
