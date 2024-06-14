sourceDir=/share/classes/class04
targetDir=~/classes/class04
file=grep-examples.txt

mkdir -p $targetDir
cp $sourceDir/* $targetDir
cd $targetDir
freq_word=`cat $file |\
    tr [:space:] "\n" |\
    tr -s "\n" |\
    tr "a-z" "A-Z" |\
    sort | uniq -c |\
    sort -k1,1nr | head -n1 |\
    tr -s " " | cut -d" " -f3`

echo "The most frequent word in $file is $freq_word"
