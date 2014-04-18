HEADERS = headers
LIB = ./libraries

OBJECTS = main.o automat_komorkowy.o obrazek.o przechowywanie.o wczytywanie.o wypisywanie.o zasada_martwa.o zasada_zywa.o

main.o automat_komorkowy.o wczytywanie.o wypisywanie.o : $(HEADERS)/automat_komorkowy.h
automat_komorkowy.o zasada_zywa.o : $(HEADERS)/zasada_zywa.h
automat_komorkowy.o zasada_martwa.o : $(HEADERS)/zasada_martwa.h
main.o automat_komorkowy.o obrazek.o przechowywanie.o wczytywanie.o : $(HEADERS)/przechowywanie.h
main.o : $(HEADERS)/wczytywanie.h
main.o : $(HEADERS)/wypisywanie.h
main.o obrazek.o : $(HEADERS)/obrazek.h

all: $(OBJECTS)
	@echo "Łącze moduły *.o"
	@gcc -g -ograwzycie $^

main.o : $(LIB)/main.c
	@echo "Kompiluję moduł $@"
	@gcc -g -c -I$(HEADERS) $^

automat_komorkowy.o: $(LIB)/automat_komorkowy.c
	@echo "Kompiluję moduł $@"
	@gcc -g -c -I$(HEADERS) $^

obrazek.o: $(LIB)/obrazek.c
	@echo "Kompiluję moduł $@"
	@gcc -g -c -I$(HEADERS) $^

przechowywanie.o: $(LIB)/przechowywanie.c
	@echo "Kompiluję moduł $@"
	@gcc -g -c -I$(HEADERS) $^

wczytywanie.o: $(LIB)/wczytywanie.c
	@echo "Kompiluję moduł $@"
	@gcc -g -c -I$(HEADERS) $^

wypisywanie.o: $(LIB)/wypisywanie.c
	@echo "Kompiluję moduł $@"
	@gcc -g -c -I$(HEADERS) $^

zasada_martwa.o: $(LIB)/zasada_martwa.c
	@echo "Kompiluję moduł $@"
	@gcc -g -c -I$(HEADERS) $^

zasada_zywa.o: $(LIB)/zasada_zywa.c
	@echo "Kompiluję moduł $@"
	@gcc -g -c -I$(HEADERS) $^

.PHONY: clean

test1:
	./grawzycie -p data/a -N 100 -f tak

test2:
	./grawzycie -p data/a -N 100 -f tak -i 5

test3:
	./grawzycie -p data/b -N 4 -z wynik
clean:
	rm *.o
cleanp:
	@echo "Usunalem wszystkie stworzone zdjecia z generacjami"
	rm ./image/*.ppm
cleanf:
	@echo "Usunalem wszyskie stworzone pliki z generacjami"
	rm ./file/*.txt
