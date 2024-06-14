## ================ example 3.1 ================  ##
grep "Peter" phone_dir.txt    # Find 'Peter'
# result's: Peter....
## ================ example 3.2 ================  ##
grep "b.g" grep-example.txt   # Find string b[something]g
# result's: bag, brag, debugging, bg
## ================ example 3.3 ================  ##
grep [Bb]ill grep-example.txt  # Find string [B/b]'ill'
# result's: kill bill, got billed ill
## ================ example 3.4 ================  ##
grep "t[aeiou].k" grep-example.txt  # Find string 
# result's: talk, stink
## ================ example 3.5 ================  ##
grep "number [^0-5]" grep-example.txt  # Find string with number without ^...(like not)
# result's: number xx_x, number 8:
## ================ example 3.6 ================  ##
grep "number [0-5]" grep-example.txt  # 
# result's: number 5, number 1, number 235...
## ================ example 3.7 ================  ##
grep "^num.*[5-8]&" grep-example.txt  
# result's: 
# num5
# num 235
# num605 num60605....
## ================ example 3.8 ================  ##
