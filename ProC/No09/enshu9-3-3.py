import tkinter as tk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import pandas as pd

plt.rcParams['font.family'] = "MS Gothic"
plt.rcParams['font.size'] = 16

root = tk.Tk()
root.title("グラフの切り替え")
root.geometry("800x600")

fig = plt.figure(figsize=(7.0, 5.0), dpi=100)
ax = fig.add_subplot(111)

def showGraph():
    df = pd.read_csv("09age_freq.csv")
    ax.clear()
    ax.bar(df['Age'], df['Freq'], color="green", width=5)
    ax.set_xlabel("年齢")
    ax.set_ylabel("人数")
    ax.set_title("年齢の頻度分布")
    canvas.draw()
    
canvas = FigureCanvasTkAgg(fig, master=root)
canvas.draw()
canvas.get_tk_widget().pack(pady=10)

btn = tk.Button(root, text="棒グラフ", command=showGraph)
btn.pack(pady=10)

tk.mainloop()
