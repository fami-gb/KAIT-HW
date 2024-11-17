num = int(input("nの値を入力："))
summary = 0
for i in range(1, num):
    summary += i
print(f"1~{num}までの合計は{summary}です")
