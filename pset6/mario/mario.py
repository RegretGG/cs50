a = -1
while(a <= 0 or a>8):
    try:
        a = int(input("Height: "))
    except:
        continue
for i in range(1, a+1):
    print(" "*(a-i) + "#"*i +"  " +"#"*i)
    