import numpy as np
import matplotlib.pyplot as plt

plt.rcParams["font.family"] = "MS Gothic"

data = np.random.normal(50, 10, 100)

plt.hist(data, bins=20, color="blue", alpha=0.7)
plt.title("正規分布のヒストグラム")
plt.show()
