cp /share/ex_data/ex2/story.txt .
head -n237 story.txt | tail -n20 | tr "AEIOUaeiou" "EIOUAeioua" > story-switched-vowels.txt
cat story.txt | tr -d [:space:] | tr "'\"" "\n" | wc -l
cat story.txt | cut -c3 | tr -s [:space:] "\n" | sort | uniq -c | sort -k1,1nr -k2,2 | tr -s " " "-" | head -n4 > letter-stats.txt
cat story.txt | tr "[:space:][:punct:]" "\n" | tr -s "\n" | tr "A-Z" "a-z" | sort | uniq > story-words.txt
