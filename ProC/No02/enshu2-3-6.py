score = []
result = ""
for i in range(5):
    score.append(int(input(f"{i}番目の学生の点数を入力:")))
    ave = sum(score)/len(score)
    if ave >= 80:
        result = "優"
    elif ave >= 60:
        result = "良"
    else:
        result = "可"
print(f"平均点:{ave}、成績評価:{result}")
