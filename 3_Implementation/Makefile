main.exe : main.c src/txn.c
	gcc -Iinc ./main.c ./src/txn.c -o main.exe

TEST.exe: unity/unity.c tests/test.c src/txn.c
	gcc -Iinc -Iunity ./src/txn.c ./tests/test.c ./unity/unity.c -o TEST.exe

runtest: TEST.exe
	./TEST.exe

run: main.exe
	./main.exe

clean: 
	rm *.exe