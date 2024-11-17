fruits = ["apple", "banana", "orange", "grape", "melon"]
str = input("探したい果物の名前を入力：")
if str in fruits:
    print(f"{str}はリストに含まれています")
else:
    print(f"{str}はリストに含まれていません")
