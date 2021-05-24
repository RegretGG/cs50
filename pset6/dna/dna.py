import re
import csv
from sys import argv
import cs50
def main():
    b = argv[1]
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return
    with open (b) as file:
        a = []
        reader = csv.DictReader(file)
        for row in reader:
            a += [row]
    file1 = open(argv[2],"r+") 
    read = file1.readline()
    file1.close()
    D = {}
    for k in a[0]:
        if k != "name":
            c = greatestchecker(k, read)
            D[k] = c
    for i in a:
        counter = 0
        for j in i:
            if j != "name":
                a = int(i[j])
                b = int(D[j])
                if a == b:
                    counter+=1
        if counter == len(D):
            print(i["name"])
            return
    print("No match\n")
    

            
                    
def greatestchecker(pattern, data):
    no = 0
    for i in range(1,51):
        z = pattern*i
        if re.search(z,data):
            no = i
    return no
        
if __name__ == "__main__":
    main()