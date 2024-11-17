import matplotlib.pyplot as plt
import numpy as np

plt.rcParams['font.family'] = 'MS Gothic'

x = np.random.rand(100)

plt.hist(x, bins=10, edgecolor="black")
plt.title("ランダム数値のヒストグラム")
plt.xlabel("値")
plt.ylabel("度数")
plt.show()
