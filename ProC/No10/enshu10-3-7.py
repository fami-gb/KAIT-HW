import tkinter as tk
from tkinter import filedialog
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

root = tk.Tk()
root.title("CSVのヒストグラム表示")
root.geometry("800x600")

plt.rcParams["font.family"] = "MS Gothic"
plt.rcParams["font.size"] = 16

fig = plt.figure(figsize=(10, 10), dpi=100)
ax = fig.add_subplot(111)

def load_csv():
    file_path = filedialog.askopenfilename(filetypes=[("CSV files", "*.csv")])
    
    if file_path:
        df = pd.read_csv("./10EnshuData.csv")
        ax.clear()
        ax.hist(df["Score"])
        ax.set_xlabel("値の範囲")
        ax.set_ylabel("頻度")
        ax.set_title("ヒストグラム")
        canvas.draw()
        
def exit_form():
    root.quit()

menubar = tk.Menu(root)
file_menu = tk.Menu(menubar, tearoff=0)
file_menu.add_command(label="開く", command=load_csv)
file_menu.add_command(label="終了", command=exit_form)
menubar.add_cascade(label="ファイル", menu=file_menu)
root.config(menu=menubar)

canvas = FigureCanvasTkAgg(fig, root)
canvas.draw()
canvas.get_tk_widget().pack()

tk.mainloop()
