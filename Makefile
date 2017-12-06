all:	MY_BANK

MY_BANK: main.o helpers.o bank.o member.o account.o
	g++ -g main.o helpers.o bank.o member.o account.o -o MY_BANK


main.o:	main.cpp
	g++ -c -g main.cpp

helpers.o:	helpers.cpp
	g++ -c -g helpers.cpp

bank.o:	bank.cpp
	g++ -c -g bank.cpp

member.o:	member.cpp
	g++ -c -g member.cpp

account.o:	account.cpp
	g++ -c -g account.cpp

run:	MY_BANK
	./MY_BANK


test_exit:	MY_BANK
	if [ ! -f ./tests/output/exit.txt ]; then touch ./tests/output/exit.txt; fi
	./MY_BANK < ./tests/test_cases/exit.txt > ./tests/output/exit.txt
	diff  ./tests/output/exit.txt ./tests/answers/exit.txt

test_accounts:	MY_BANK
	if [ ! -f ./tests/output/accounts.txt ]; then touch ./tests/output/accounts.txt; fi
	./MY_BANK < ./tests/test_cases/accounts.txt > ./tests/output/accounts.txt
	sed '/id\( is\)\?:/d' -i ./tests/output/accounts.txt
	diff  ./tests/output/accounts.txt ./tests/answers/accounts.txt

test_input:	MY_BANK
	if [ ! -f ./tests/output/input.txt ]; then touch ./tests/output/input.txt; fi
	./MY_BANK < ./tests/test_cases/input.txt > ./tests/output/input.txt
	sed '/id\( is\)\?:/d' -i ./tests/output/input.txt
	diff  ./tests/output/input.txt ./tests/answers/input.txt

test_units:	helpers.o bank.o account.o
	if [ ! -f ./tests/output/units.txt ]; then touch ./tests/output/units.txt; fi
	g++ -g tests/test_cases/unit_tests.cpp bank.o account.o -o cpp_test_units
	./cpp_test_units > ./tests/output/units.txt
	sed '/id\( is\)\?:/d' -i ./tests/output/units.txt
	diff  ./tests/output/units.txt ./tests/answers/units.txt

test:	test_exit test_accounts test_input test_units

debug: MY_BANK
	gdb MY_BANK


clean:	
	rm *.o cpp_test_units

nuke: clean
	rm MY_BANK
