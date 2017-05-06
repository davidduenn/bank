echo "Running 'exit' test"
./MY_BANK < ./tests/input/exit.txt > ./tests/output/exit.txt
diff --side-by-side ./tests/output/exit.txt ./tests/answers/exit.txt

echo "Running 'accounts' test"
./MY_BANK < ./tests/input/accounts.txt > ./tests/output/accounts.txt
diff --side-by-side ./tests/output/accounts.txt ./tests/answers/accounts.txt
