math = int(input('数学の点数を入力してください'))
eng = int(input('英語の点数を入力してください'))
sci = int(input('社会の点数を入力してください'))

total = math + eng + sci
ave = total / 3
print(f'点数の合計は{total}です')
print(f'点数の平均は{ave}です')