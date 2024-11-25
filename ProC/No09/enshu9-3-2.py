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
    df = pd.read_csv('09sales_data.csv')
    ax.clear()
    ax.plot(df["Month"], df["Sales"], marker="o")
    ax.set_xlabel("月")
    ax.set_ylabel("売上")
    ax.set_title("月別売上")
    canvas.draw()

canvas = FigureCanvasTkAgg(fig, master=root)
canvas.draw()
canvas.get_tk_widget().pack(pady=10)

btn = tk.Button(root, text="グラフの表示", command=showGraph)
btn.pack(pady=10)

tk.mainloop()
