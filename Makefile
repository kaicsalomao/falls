CC := g++
LFLAGS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image

main.exe: main.o sprite.o window.o
	$(CC) .obj/*.o $(LFLAGS) -o build/main.exe && cd .\build && main.exe && cd ..
	del .obj\*.o

window.o: src/window.cpp
	$(CC) -c src/window.cpp -o .obj/window.o

sprite.o: src/sprite.cpp
	$(CC) -c src/sprite.cpp -o .obj/sprite.o

main.o: src/main.cpp
	$(CC) -c src/main.cpp -o .obj/main.o