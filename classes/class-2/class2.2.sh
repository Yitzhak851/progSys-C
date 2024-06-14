tail phone_dir.txt > file1.txt #copy last 10 lines of phone_dir.txt into file1.txt
head -n-2 phone_dir.txt > file2.txt # copy all but the last two line of phone...txt into file2.txt
wc -lw phone_dir.txt # count lines and words in phone_dir.txt
head -n3 phone_dir.txt > file3.txt  #copy phone_dir.txt other than lines 4-6 into file3.txt (2 commands)
tail -n+7 phone_dir.txt >> file3.txt