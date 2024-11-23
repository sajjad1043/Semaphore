CC = gcc
CFLAGS = -pthread
TARGET = main

OBJS = main.c sender.c receiver.c

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(TARGET)
