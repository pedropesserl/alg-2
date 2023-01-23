parametrosCompilacao=-Wall #-Wshadow
nomePrograma=trab

all: $(nomePrograma)

$(nomePrograma): main.o ordenacao.o
	gcc -o $(nomePrograma) main.o ordenacao.o $(parametrosCompilacao)

teste: teste.o ordenacao.o
	gcc -o teste teste.o ordenacao.o $(parametrosCompilacao)

teste.o: teste.c
	gcc -c teste.c $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
