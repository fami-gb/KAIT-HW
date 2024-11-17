import random
num = int(input("サイコロを振る回数を入力："))
dice = []
for i in range(num):
    dice.append(random.randint(1, 6))

print(f"サイコロを{num}回振った合計は", sum(dice))
print("出た目は", dice)
