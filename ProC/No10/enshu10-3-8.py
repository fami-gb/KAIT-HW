import tkinter as tk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

root = tk.Tk()
root.title("チェックボックスでグラフ表示")
root.geometry("800x600")

var_bar = tk.BooleanVar()
var_scatter = tk.BooleanVar()
var_plot = tk.BooleanVar()

plt.rcParams["font.family"] = "MS Gothic"
plt.rcParams["font.size"] = 16

fig = plt.figure(figsize=(10, 10), dpi=100)
ax = fig.add_subplot(111)

def showGraph():
    isBarChecked = var_bar.get()
    isScatterChecked = var_scatter.get()
    isPlotChecked = var_plot.get()
    x = [ 1, 2, 3, 4, 5 ]
    y = [ 10, 20, 15, 25, 30 ]
    ax.clear()
    if isBarChecked:
        ax.bar(x, y, label="棒グラフ")
    if isScatterChecked:
        ax.scatter(x, y, label="散布図", marker="o", color="green")
    if isPlotChecked:
        ax.plot(x, y, label="折れ線グラフ", color="orange")
    ax.legend()
    ax.set_title("グラフの表示")
    ax.set_xlabel("X軸")
    ax.set_ylabel("y軸")
    canvas.draw()

ckb_bar = tk.Checkbutton(root, text="棒グラフ", variable=var_bar, font=20)
ckb_bar.pack(anchor=tk.W)

ckb_scatter = tk.Checkbutton(root, text="散布図", variable=var_scatter, font=20)
ckb_scatter.pack(anchor=tk.W)

ckb_bar = tk.Checkbutton(root, text="折れ線グラフ", variable=var_plot, font=20)
ckb_bar.pack(anchor=tk.W)

btn = tk.Button(root, text="表示", command=showGraph, font=20)
btn.pack(pady=15)

canvas = FigureCanvasTkAgg(fig, root)
canvas.draw()
canvas.get_tk_widget().pack()

tk.mainloop()
