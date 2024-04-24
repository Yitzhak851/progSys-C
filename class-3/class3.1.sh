## ======== Assignment 3.1 ========  ##
# Create a directory classes/class03 in your home directory 
# and copy the files from the shared directory /share/classes/class03 to it, 
# and then enter it.
mkdir -p ~/classes/class03 # -p to creat parent dir if does'nt exist
cp /share/classes/class03/* ~/classes/class03
cd ~/classes/class03

## ======== Assignment 3.2 ========  ##
# Use a piped sequence of commands to print to the standard output 
# the word that appears most times in the filegrep-examples.txt.
# • Word is defined as characters that are separated by white spaces.
# • Ignore case (upper/lower); have all words be in upper-case.
# • Just print the word (don’t print its frequency in the file).
# • Hint: answer is NUMBER (which appears 5 times).
cat grep-example.txt | \    # print file
tr [:space:] "\n"    |\     # convert all space to newlines
tr -s "\n"           |\     # remove empty lines
tr "a-z" "A-Z"       |\     # convert lower case => uper
sort | uniq -c       |\     # sort and count words
sort -k1, 1nr        |\     # sort words in decreasing count
head -n1             |\     # print most frequand word+count
tr -s " "            |\     # remove extra space
cut -d" " -f3        |\     # print word
# note that 1st field is empty