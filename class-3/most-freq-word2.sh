sourceDir=/share/classes/class03
targetDir=~/classes/class03
file=grep-examples.txt

mkdir -p $targetDir
cp $sourceDir/* $targetDir
cd $targetDir
cat $file |\
    tr [:space:] "\n" |\
    tr -s "\n" |\
    tr "a-z" "A-Z" |\
    sort | uniq -c |\
    sort -k1,1nr | head -n1 |\
    tr -s " " | cut -d" " -f3