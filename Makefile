fpjson: fpjson.c
fpjson.o: fpjson.c
	gcc -c fpjson.c
fpjson: fpjson.o
	gcc -o fpjson fpjson.o
clean:
	rm -f fpjson fpjson.o
