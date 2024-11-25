import tkinter as tk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import pandas as pd
import numpy as np

plt.rcParams['font.family'] = "MS Gothic"
plt.rcParams['font.size'] = 16

root = tk.Tk()
root.title("乱数の折れ線グラフ")
root.geometry("800x700")

fig = plt.figure(figsize=(7.0, 5.0), dpi=100)
ax = fig.add_subplot(111)

def showGraph():
    num = int(entry.get())
    val = np.random.randint(1, 100, num)
    index = np.arange(num)
    ax.clear()
    ax.plot(index, val, color="purple", marker="o")
    ax.set_xlabel("インデックス")
    ax.set_ylabel("値")
    ax.set_title(f"乱数データ({num}点)")
    canvas.draw()
    
canvas = FigureCanvasTkAgg(fig, master=root)
canvas.draw()
canvas.get_tk_widget().pack(pady=10)

lb = tk.Label(root, text="データ数を入力")
lb.pack(pady=10)

entry = tk.Entry(root, width=20)
entry.pack(pady=10)

btn = tk.Button(root, text="グラフ表示", command=showGraph)
btn.pack(pady=10)

tk.mainloop()
