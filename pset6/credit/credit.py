from cs50 import get_string
import re
def main():
    cardno = get_string("Number: ")
    if luhns_algo(cardno) != True:
        print("INVALID\n")
        return
    else:
        if len(cardno)== 15:
            if re.search('^3[47].',cardno):
                print("AMEX\n")
        elif len(cardno) == 16:
            if re.search('^5[1-5].',cardno):
                print("MASTERCARD\n")
            elif re.search('^4.', cardno):
                print("VISA\n")
        elif len(cardno) == 13:
            if re.search('^4.', cardno):
                print("VISA\n")
        else:
            print("INVALID\n")
        

    
    
def luhns_algo(a):
    summ = []
    dumsum = 0
    for i in range(len(a)-1, -1 ,-1):
        if i%2 == 0:
            temp = int(a[i])
            temp *=2
            summ += str(temp)
        else:
            dumsum+= int(a[i])
    for i in summ:
        for j in i:
            dumsum+= int(j)

        return True
    else:
        return False
if __name__ == "__main__":
    main()