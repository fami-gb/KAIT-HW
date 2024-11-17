count = 0
for i in range(5):
    num = int(input(f"{i}番目の整数を入力："))
    if num % 2 == 0:
        count += 1
print(f"偶数の数:{count}、奇数の数:{5-count}")
