all:	MY_BANK

MY_BANK: main.o helpers.o bank.o account.o
	g++ -g main.o helpers.o bank.o account.o -o MY_BANK


main.o:	main.cpp
	g++ -c -g main.cpp

helpers.o:	helpers.cpp
	g++ -c -g helpers.cpp

bank.o:	bank.cpp
	g++ -c -g bank.cpp

account.o:	account.cpp
	g++ -c -g account.cpp

run:	MY_BANK
	./MY_BANK


test_exit:	MY_BANK
	./MY_BANK < ./tests/test_cases/exit.txt > ./tests/output/exit.txt
	diff --side-by-side ./tests/output/exit.txt ./tests/answers/exit.txt | grep -v "id\( is\)\?:"

test_accounts:	MY_BANK
	./MY_BANK < ./tests/test_cases/accounts.txt > ./tests/output/accounts.txt
	diff --side-by-side ./tests/output/accounts.txt ./tests/answers/accounts.txt | grep -v "id\( is\)\?:"

test: test_exit test_accounts

debug: MY_BANK
	gdb MY_BANK


clean:	
	rm *.o

nuke: clean
	rm MY_BANK
