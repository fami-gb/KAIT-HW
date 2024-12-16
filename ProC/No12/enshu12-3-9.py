import tkinter as tk
import pandas as pd
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
from tkinter import filedialog

plt.rcParams["font.family"] = "MS Gothic"

fig = plt.figure(figsize=(7, 7), dpi=100)
ax = fig.add_subplot(111)


root = tk.Tk()
root.title("グラフ作成アプリ")
root.geometry("800x500")

var_type = tk.IntVar()
var_type.set(0)

def loadCSV():
    filepath = filedialog.askopenfilename(filetypes=[("CSV files", "*.csv")])
    if filepath:
        global df
        df = pd.read_csv(filepath)
        showGraph()
    

def showGraph():
    GraphType = var_type.get()
    ax.clear()
    if GraphType == 0:
        ax.plot(df["X"], df["Y"], label="折れ線グラフ")
    elif GraphType == 1:
        ax.bar(df["X"], df["Y"], label="棒グラフ")
    ax.legend()
    canvas.draw()

rb_plot = tk.Radiobutton(root, text="折れ線グラフ", variable=var_type, value=0, command=showGraph)
rb_plot.pack()

rb_bar = tk.Radiobutton(root, text="棒グラフ", variable=var_type, value=1, command=showGraph)
rb_bar.pack()

btn_load = tk.Button(root, text="CSVからデータを読み込む", command=loadCSV)
btn_load.pack()

canvas = FigureCanvasTkAgg(fig, root)
canvas.draw()
canvas.get_tk_widget().pack()

tk.mainloop()
