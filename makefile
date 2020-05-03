compiler = gcc
versions = -std=c99
object = main.o code_cycle.o decodermatrix.o interfaceall.o matrix.o
execute_file = codemaker

$(execute_file): $(object)
	$(compiler) $(versions) $(object) -o $(execute_file) -lm
	-rm *.o

main.o: main.c main.h
	$(compiler) $(versions) -c main.c

code_cycle.o: code_cycle.c main.h
	$(compiler) $(versions) -c code_cycle.c

decodermatrix.o: decodermatrix.c main.h
	$(compiler) $(versions) -c decodermatrix.c

interfaceall.o: interfaceall.c main.h
	$(compiler) $(versions) -c interfaceall.c

matrix.o: matrix.c main.h
	$(compiler) $(versions) -c matrix.c

.PHONY : clean

run:
	./$(execute_file)
