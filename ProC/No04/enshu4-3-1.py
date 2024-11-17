import numpy as np

start = int(input("範囲の開始値を入力してください："))
end = int(input("範囲の終了値を入力してください："))

x = np.arange(start, end+1)
print(x[x % 2 == 0])
