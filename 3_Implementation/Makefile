main.exe : main.c src/txn.c
	gcc -Iinc ./main.c ./src/txn.c -o main.exe

run: main.exe
	./main.exe

clean: 
	rm *.exe