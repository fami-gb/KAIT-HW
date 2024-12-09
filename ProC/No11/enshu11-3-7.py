import tkinter as tk
from tkinter import font
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

x = [1, 2, 3, 4]
y = [10, 20, 15, 25]


root = tk.Tk()
root.title("グラフ選択")
root.geometry("800x800")
formFont = font.nametofont("TkDefaultFont")
formFont.configure(size=20)

var_type = tk.IntVar()
var_type.set(1)

fig = plt.figure(figsize=(7, 7), dpi=100)
ax = fig.add_subplot(111)

plt.rcParams["font.family"] = "MS Gothic"
plt.rcParams["font.size"] = 16

def changeGraph():
    GraphType = var_type.get()
    ax.clear()
    if GraphType == 1:
        ax.plot(x, y, label="折れ線グラフ")
    elif GraphType == 2:
        ax.plot(x, y, label="棒グラフ")
    ax.legend()
    canvas.draw()
    
rb_plot = tk.Radiobutton(root, text="折れ線グラフ", variable=var_type, value=1, command=changeGraph)
rb_plot.pack()

rb_bar = tk.Radiobutton(root, text="棒グラフ", variable=var_type, value=2, command=changeGraph)
rb_bar.pack()

canvas = FigureCanvasTkAgg(fig, root)
canvas.draw()
canvas.get_tk_widget().pack(pady=10)

tk.mainloop()
