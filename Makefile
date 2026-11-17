CC = gcc
CFLAGS = -Werror -Wall -std=c17
TARGET = bomber-sub

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $< -o $(TARGET)

.PHONY: all clean

clean:
	rm -f $(TARGET)
