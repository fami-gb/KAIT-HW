import tkinter as tk
import matplotlib.pyplot as plt
import numpy as np

root = tk.Tk()
root.title("ランダムなグラフを描画するアプリ")
root.geometry("300x200")

plt.rcParams["font.family"] = "MS Gothic"

global cnt
cnt = 0

def showGraph():
    global cnt
    cnt += 1
    x = np.arange(1, 10+1)
    y = np.random.randint(1, 100, size=10)
    plt.clf()
    plt.plot(x, y, label=f"{cnt}回目", marker="o")
    plt.legend()
    plt.title("ランダムデータ")
    plt.show()


btn = tk.Button(root, text="グラフを描画", command=showGraph)
btn.pack()

tk.mainloop()
