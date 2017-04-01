all:	MY_BANK

MY_BANK: main.o bank.o account.o
	g++ -g main.o bank.o account.o -o MY_BANK


main.o:	main.cpp
	g++ -c -g main.cpp

bank.o:	bank.cpp
	g++ -c -g bank.cpp

account.o:	account.cpp
	g++ -c -g account.cpp

run:	MY_BANK
	./MY_BANK

clean:	
	rm *.o

nuke: clean
	rm MY_BANK
