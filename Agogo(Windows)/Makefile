RAYLIB_PATH = /home/fefinho/Documentos/Raylib

main : main.o
	@echo "Criando arquivo executável"
	x86_64-w64-mingw32-gcc main.o -L$(RAYLIB_PATH)/lib -lraylib -lopengl32 -lgdi32 -lwinmm -o main.exe

main.o : main.c
	@echo "Criando arquivo main"
	x86_64-w64-mingw32-gcc -I$(RAYLIB_PATH)/include -c main.c -o main.o

clean : 
	@echo "Limpando arquivos"
	rm -f main.o main.exe

run :
	@echo "Abrindo jogo"
	./main.exe
