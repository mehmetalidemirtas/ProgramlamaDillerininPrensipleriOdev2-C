derle: hepsi calistir
hepsi:
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
	gcc -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.c
	gcc -I ./include/ -o ./lib/Oyun.o -c ./src/Oyun.c
	gcc -I ./include/ -o ./bin/Test ./lib/Kisi.o ./lib/Dosya.o ./lib/Oyun.o ./src/Test.c
calistir:
	./bin/Test