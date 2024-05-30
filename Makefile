all: run

run: main
	./taller2

main:
	gcc main.c -o taller2

clean:
	rm taller1

r2-1:
	gcc pruebas/r2-1.c -o pruebas/r2-1

prueba-r2-1: r2-1
	bash pruebas/prueba-r2-1.sh

r2-2:
	gcc pruebas/r2-2.c -o pruebas/r2-2

prueba-r2-2: r2-2
	bash pruebas/prueba-r2-2.sh

r3:
	gcc pruebas/r3.c -o pruebas/r3

prueba-r3: r3
	bash pruebas/prueba-r3.sh

r4:
	gcc pruebas/r4.c -o pruebas/r4

prueba-r4: r4
	bash pruebas/prueba-r4.sh

.PHONY: all run clean prueba-r2-1

