CC = cc
CFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = game
SRCS = $(wildcard *.c)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS)

clean:
	rm -f $(TARGET)

re: clean all

run: clean all
	./$(TARGET)

.PHONY: all clean re run