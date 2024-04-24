mkdir -p ~/classes/class03
cp /share/classes/class03/* ~/classes/class03
cd ~/classes/class03
cat grep-examples.txt |\
    tr [:space:] "\n" |\
    tr -s "\n" |\
    tr "a-z" "A-Z" |\
    sort | uniq -c |\
    sort -k1,1nr | head -n1 |\
    tr -s " " | cut -d" " -f3

