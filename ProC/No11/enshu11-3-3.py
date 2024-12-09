import matplotlib.pyplot as plt

plt.rcParams["font.family"] = "MS Gothic"

x = [1, 2, 3, 4, 5]
y = [2, 4, 1, 8, 7]

plt.scatter(x, y, color="red", marker="o")
plt.title("散布図")
plt.show()
