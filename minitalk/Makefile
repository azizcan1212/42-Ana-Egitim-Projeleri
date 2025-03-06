# Compiler ve compiler flag'leri
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Programlar ve dosyalar
SERVER = server
CLIENT = client
SERVER_SRC = server.c
CLIENT_SRC = client.c
OBJECTS = $(SERVER_SRC:.c=.o) $(CLIENT_SRC:.c=.o)

# Default hedef (ilk hedef)
all: $(SERVER) $(CLIENT)

# Server programının derlenmesi
$(SERVER): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_SRC)

# Client programının derlenmesi
$(CLIENT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_SRC)

# Temizlik işlemi
clean:
	rm -f $(SERVER) $(CLIENT) $(OBJECTS)

# `.PHONY` hedefi, Makefile'da gerçek dosya ismiyle çakışmasını engeller
.PHONY: all clean
