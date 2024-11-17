total = 0
ave = 0
length = 5

for i in range(length):
    num = int(input(f"{i+1}番目の整数を入力："))
    if num >= 0:
        total += num    
    else:
        length -= 1

print(total/length)
