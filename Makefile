HEADERS = headers
LIB = ./libraries

OBJECTS = main.o automat_komorkowy.o obrazek.o przechowywanie.o read.o wypisywanie.o zasada_martwa.o zasada_zywa.o

main.o automat_komorkowy.o read.o wypisywanie.o : $(HEADERS)/automat_komorkowy.h
automat_komorkowy.o zasada_zywa.o : $(HEADERS)/zasada_zywa.h
automat_komorkowy.o zasada_martwa.o : $(HEADERS)/zasada_martwa.h
main.o automat_komorkowy.o obrazek.o przechowywanie.o read.o : $(HEADERS)/przechowywanie.h
main.o : $(HEADERS)/read.h
main.o : $(HEADERS)/wypisywanie.h
main.o obrazek.o : $(HEADERS)/obrazek.h

all: $(OBJECTS)
	@echo "Łącze moduły *.o"
	@gcc -oProgram $^

main.o : $(LIB)/main.c
	@echo "Kompiluję moduł $@"
	@gcc -c -I$(HEADERS) $^

automat_komorkowy.o: $(LIB)/automat_komorkowy.c
	@echo "Kompiluję moduł $@"
	@gcc -c -I$(HEADERS) $^

obrazek.o: $(LIB)/obrazek.c
	@echo "Kompiluję moduł $@"
	@gcc -c -I$(HEADERS) $^

przechowywanie.o: $(LIB)/przechowywanie.c
	@echo "Kompiluję moduł $@"
	@gcc -c -I$(HEADERS) $^

read.o: $(LIB)/read.c
	@echo "Kompiluję moduł $@"
	@gcc -c -I$(HEADERS) $^

wypisywanie.o: $(LIB)/wypisywanie.c
	@echo "Kompiluję moduł $@"
	@gcc -c -I$(HEADERS) $^

zasada_martwa.o: $(LIB)/zasada_martwa.c
	@echo "Kompiluję moduł $@"
	@gcc -c -I$(HEADERS) $^

zasada_zywa.o: $(LIB)/zasada_zywa.c
	@echo "Kompiluję moduł $@"
	@gcc -c -I$(HEADERS) $^

.PHONY: clean

clean:
	rm *.o
