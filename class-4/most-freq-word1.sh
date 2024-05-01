mkdir -p ~/classes/class04
cp /share/classes/class04/* ~/classes/class04
cd ~/classes/class04
cat grep-examples.txt |\
    tr [:space:] "\n" |\
    tr -s "\n" |\
    tr "a-z" "A-Z" |\
    sort | uniq -c |\
    sort -k1,1nr | head -n1 |\
    tr -s " " | cut -d" " -f3
