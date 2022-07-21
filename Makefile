project: exec_1
all1: src/lexer.c tst/test1.c
	rm -rf bin
	mkdir -p bin
	gcc -I ./include $^ -o bin/rslt_one
exec_1:all1
	dd if=/dev/urandom of=rien bs=64M count=16 && ./bin/rslt_one rien
clear:
	rm -f rien
clean:
	rm -f Makefile~ *.h~ *.c~ src/*.c~ src/*.h~ tst/*.c~ tst/*.h~ include/*.c~ include/*.h~ a.out sample.txt *.o src/*.o bin/*.o tst/*.o
supress: bin/rslt_one
	rm $<
