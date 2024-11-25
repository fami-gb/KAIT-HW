import tkinter as tk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import pandas as pd

plt.rcParams['font.family'] = "MS Gothic"
plt.rcParams['font.size'] = 16

fig = plt.figure(figsize=(7.0, 5.0), dpi=100)
ax = fig.add_subplot(111)

root = tk.Tk()
root.title("グラフの切り替え")
root.geometry("900x900")

def showGraph():
    df = pd.read_csv('09area_data.csv')
    averages = df.mean()
    ax.clear()
    ax.bar(averages.index, averages.values, color="skyblue")
    ax.set_xlabel("列名")
    ax.set_ylabel("平均値")
    ax.set_title("列の平均値")
    canvas.draw()

canvas = FigureCanvasTkAgg(fig, master=root)
canvas.draw()
canvas.get_tk_widget().pack(pady=10)

btn = tk.Button(root, text="平均値を表示", command=showGraph)
btn.pack(pady=10)

tk.mainloop()
