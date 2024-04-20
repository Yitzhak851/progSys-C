cp /share/ex_data/ex2/story.txt ./
head -n 237 story.txt | tail -n 20 | tr 'aeiouAEIOU' 'eiouaEIOUA' >story-switched-vowels.txt
cat story.txt | tr -cd "\"'" | wc -c
cut -c3 story.txt | sort | uniq -c | sort -k1nr -k2 | head -n6 | tail -n4 | tr -s ' ' '-' >letter-stats.txt
cat story.txt | tr [:space:] '\n' | tr [:punct:] '\n' | tr 'A-Z' 'a-z' | sort | uniq | tail -n+2 >story-words.txt
