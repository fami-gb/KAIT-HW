import random

num1 = random.randint(1, 100)
num2 = random.randint(1, 100)
ans = int(input(f"{num1} + {num2} = ?："))
if (ans == num1 + num2):
    print("正解です!")
else:
    print(f"残念!正解は{num1 + num2}です。")
