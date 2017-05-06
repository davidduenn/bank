./MY_BANK < ./tests/input/exit.txt > ./tests/output/exit.txt
diff ./tests/output/exit.txt ./tests/answers/exit.txt

./MY_BANK < ./tests/input/accounts.txt > ./tests/output/accounts.txt
diff ./tests/output/accounts.txt ./tests/answers/accounts.txt
