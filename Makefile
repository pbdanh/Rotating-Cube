All:
	g++ source/*.cpp main.cpp -I./SDL2/include/SDL2 -L./SDL2/lib -I./include -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o Rotating\ Cube