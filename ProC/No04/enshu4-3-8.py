import matplotlib.pyplot as plt
import numpy as np

x = np.arange(0, 50, 5)

plt.bar(x, x)
plt.title("1から10の折れ線グラフ")
plt.xlabel("X軸")
plt.ylabel("Y軸")
plt.show()
