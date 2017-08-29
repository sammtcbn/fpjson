MYEXEC=fpjson
CC=gcc
CFLAGS=
INC=
LIB=

fpjson: fpjson.o
	${CC} $< ${CFLAGS} ${INC} ${LIB} -o $@
fpjson.o: fpjson.c
	${CC} $< ${CFLAGS} ${INC} ${LIB} -c
clean:
	rm -f ${MYEXEC} *.o
