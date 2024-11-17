words = []
count = 0
for i in range(5):
    words.append(input(f"{i+1}番目の単語を入力:"))
    if "a" in words[i]:
        count += 1
print(f"'a'を含む単語は{count}です")
