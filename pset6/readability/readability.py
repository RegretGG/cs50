import cs50
import re
string = cs50.get_string("Text: ")
letters = 0
words = 1
sentences = 0
for i in string:
    if re.search('[A-Za-z]',i):
        letters+=1
    elif i == " ":
        words+=1
    elif re.search('[?!.]',i):
        sentences+=1
L = (letters/words)*100
S = (sentences/words)*100
index = 0.0588 * L - 0.296 * S - 15.8
if (index-index//1) >= 0.5:
    index = int(index)+1
else:
    index = int(index)
if index > 16:
    print("Grade 16+\n")
elif index <1:
    print("Before Grade 1\n")
else:
    print("Grade "+str(index))
