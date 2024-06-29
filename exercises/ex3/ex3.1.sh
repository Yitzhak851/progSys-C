# my-solution
cp /share/ex_data/ex3/planets.txt /share/ex_data/ex3/story.txt .
sed -r 's/^([A-Z][a-z]+), (-?[0-9]+).*$/In year \2, planet \1 was discovered/' planets.txt  > planet-discovery.txt
grep -E '^[A-Z][a-z]{4}, (-?[0-9]+) .+$' planets.txt > planet-status.txt
cut -f1-2 -d" " planets.txt | grep -E "1[0-8][0-9]{2}$" |cut -f1 -d',' | sort > planets-before-1900.txt
num_lines=`cat story.txt | grep -Ev '^[^a-zA-Z]*([a-zA-Z)][^a-zA-Z]*){201,}$' | grep -E '[aeiou](cc|ss)[[:alpha:]]*[[:punct:]]'|wc -l`
cat story.txt| tr '\n' ' ' | sed -r "s/(Snowball's[[:space:]]+[a-z]+)[[:punct:][:space:]]/\n\1\n/g" | grep -E "^Snowball's[[:space:]]" | sed -r "s/^Snowball's[[:space:]]+//" | sort | uniq > snowballs_words.txt

# class-solution
cp /share/ex_data/ex3/{planets,story}.txt .
sed -r 's/(.*), ([[:digit:]-]+).*/In year \2, planet \1 was discovered/' planets.txt > planet-discovery.txt
grep -E "^[[:alpha:]]{5}, [[:digit:]-]+ .*[^[:space:]]" planets.txt > planet-status.txt
grep ", 1[0-8][0-9][0-9]"  planets.txt | cut -d"," -f1 | sort > planets-before-1900.txt
num_lines=`grep -E "[aeiou](cc|ss)[[:alpha:]]*[[:punct:]]" story.txt | tr -dc "[:alpha:]\n" | grep -E "^.{,200}$" -c`
cat story.txt | tr -s "[:space:]" " " | sed -r "s/(Snowball's [[:lower:]]+)[[:space:][:punct:]]/\n\1\n/g" | grep -E "^Snowball's [[:lower:]]+$" | cut -d" " -f2 | sort | uniq > snowballs_words.txt