hepsi: derle calistir
Nesneler :=  ./lib/Telefon.o ./lib/KimlikNo.o ./lib/Kisi.o ./lib/RastgeleKisi.o ./lib/ImeiNo.o

derle:
	g++ -I ./include/ -o ./lib/Telefon.o -c ./src/Telefon.c
	g++ -I ./include/ -o ./lib/KimlikNo.o -c ./src/KimlikNo.c
	g++ -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
	g++ -I ./include/ -o ./lib/RastgeleKisi.o -c ./src/RastgeleKisi.c
	g++ -I ./include/ -o ./lib/ImeiNo.o -c ./src/ImeiNo.c
	g++ -I ./include/ -o ./bin/test $(Nesneler) ./src/test.c
	
calistir:
	./bin/test