telDic = {}

while True:
    name = input("名前を入力（終了なら'終了'と入力）:")
    if name == '終了':
        break
    tel  = input(name + 'の電話番号を入力：')
    telDic[name] = tel

print('電話帳:')
for name in telDic.keys():
    print(f"{name}: {telDic[name]}")
