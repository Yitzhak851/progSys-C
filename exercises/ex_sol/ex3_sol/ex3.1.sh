cp /share/ex_data/ex3/{planets,story}.txt .
sed -r 's/(.*), ([[:digit:]-]+).*/In year \2, planet \1 was discovered/' planets.txt > planet-discovery.txt
grep -E "^[[:alpha:]]{5}, [[:digit:]-]+ .*[^[:space:]]" planets.txt > planet-status.txt
grep ", 1[0-8][0-9][0-9]"  planets.txt | cut -d"," -f1 | sort > planets-before-1900.txt
num_lines=`grep -E "[aeiou](cc|ss)[[:alpha:]]*[[:punct:]]" story.txt | tr -dc "[:alpha:]\n" | grep -E "^.{,200}$" -c`
cat story.txt | tr -s "[:space:]" " " | sed -r "s/(Snowball's [[:lower:]]+)[[:space:][:punct:]]/\n\1\n/g" | grep -E "^Snowball's [[:lower:]]+$" | cut -d" " -f2 | sort | uniq > snowballs_words.txt
