cp /share/ex_data/ex3/planets.txt /share/ex_data/ex3/story.txt .
sed -r 's/^([A-Z][a-z]+), (-?[0-9]+).*$/In year \2, planet \1 was discovered/' planets.txt  > planet-discovery.txt
grep -E '^[A-Z][a-z]{4}, (-?[0-9]+) .+$' planets.txt > planet-status.txt
cut -f1-2 -d" " planets.txt | grep -E "1[0-8][0-9]{2}$" |cut -f1 -d',' | sort > planets-before-1900.txt
#num_lines=`cat story.txt | grep -E '\<[aeiou].*(cs)[[:punct:]]' | grep -E '^.{0,200}$' `
#grep -oE "Snowball's [[:lower:]]+" story.txt | sed 's/Snowball'\''s //' | tr -s ' ' '\n' | sed '/^[[:space:]]*$/d' | sort -u > snowballs_words.txt
