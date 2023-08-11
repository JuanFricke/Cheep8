INCLUDES = -I ./include
FLAGS = -g

ifeq ($(OS),Windows_NT)
    # Comandos para compilar no Windows
    OBJECTS = ./build/chip8memory.o ./build/chip8stack.o ./build/chip8keyboard.o ./build/chip8.o ./build/chip8screen.o
    LIBS = -L ./lib -lmingw32 -lSDL2main -lSDL2
    EXE_EXT = .exe
else
    # Comandos para compilar no Linux (ou qualquer outro sistema não-Windows)
    OBJECTS = ./build/chip8memory.o ./build/chip8stack.o ./build/chip8keyboard.o ./build/chip8.o ./build/chip8screen.o
    LIBS = -lSDL2
    EXE_EXT =
endif

all: ${OBJECTS}
	gcc ${FLAGS} ${INCLUDES} ./src/main.c ${OBJECTS} ${LIBS} -o ./bin/main${EXE_EXT}

./build/chip8memory.o: src/chip8memory.c
	gcc ${FLAGS} ${INCLUDES} -c ./src/chip8memory.c -o ./build/chip8memory.o

./build/chip8stack.o: src/chip8stack.c
	gcc ${FLAGS} ${INCLUDES} -c ./src/chip8stack.c -o ./build/chip8stack.o

./build/chip8keyboard.o: src/chip8keyboard.c
	gcc ${FLAGS} ${INCLUDES} -c ./src/chip8keyboard.c -o ./build/chip8keyboard.o

./build/chip8.o: src/chip8.c
	gcc ${FLAGS} ${INCLUDES} -c ./src/chip8.c -o ./build/chip8.o

./build/chip8screen.o: src/chip8screen.c
	gcc ${FLAGS} ${INCLUDES} -c ./src/chip8screen.c -o ./build/chip8screen.o

clean:
	rm -f ./build/*.o ./bin/main${EXE_EXT}
