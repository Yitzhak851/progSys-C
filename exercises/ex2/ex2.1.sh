# my-solution
cp /share/ex_data/ex2/planets.txt ./
sort -t',' -k2n -k1r planets.txt > planets2.txt
head -n7 planets.txt | tail -n4 | cut -f1,2 -d' ' | tr "a-z" "A-Z" | tr -d ' ' | tr ',' ':' > planets3.txt
cut -f2 -d' ' planets.txt | sort -n | uniq -c | head -n1 | tr -d [:space:] | cut -c1 >>planets2.txt
cat planets.txt | cut -f1 -d',' | cut -c1-2 | tr "A-Z" "a-z" | paste - -d " " planets.txt | cut -f1,4- -d" " > planets5.txt

# class-solution
cp /share/ex_data/ex2/planets.txt .
sort -k2,2n -k1,1r planets.txt > planets2.txt
head -n7 planets.txt | tail -n4 | cut -f1-2 -d " " | tr "a-z," "A-Z:" | tr -d " " > planets3.txt
sort -k2,2n planets.txt | cut -f2 -d" " | uniq -c | head -n1 | tr -s " " | cut -f2 -d" " >> planets2.txt
cut planets.txt -c1-2 | tr "A-Z" "a-z" | paste - planets.txt -d" " | cut -d" " -f1,4- > planets5.txt 