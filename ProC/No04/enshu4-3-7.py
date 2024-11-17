import matplotlib.pyplot as plt

plt.rcParams['font.family'] = "MS Gothic"

# データ
x = ["りんご", "ばなな", "もも", "シャインマスカット"]
y = [450, 230, 610, 2500]

# 折れ線グラフの描画
plt.bar(x, y)
plt.title("1から10の折れ線グラフ")
plt.xlabel("X軸")
plt.ylabel("Y軸")
plt.show()
