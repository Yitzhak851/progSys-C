cat rsvps.txt | grep -v "yes$" | grep "no"
sort rsvps.txt -k2,2 | paste - rsvps.txt | tail -n1
sed -r `s/(^[:alpha:][:space:])([0-9][0-9]+)(.*)/\1 99 \3 /` > rsvps_99.txt
