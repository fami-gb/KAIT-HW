import tkinter as tk
import pandas as pd
from tkinter import filedialog

def loadCSV():
    filepath = filedialog.askopenfilename(filetypes=[("CSV files", "*.csv")])
    
    if filepath:
        df = pd.read_csv(filepath)
        lb.config(text=df.head().to_string())
        
root = tk.Tk()
root.title("CSVファイル表示アプリ")
root.geometry("300x200")

menubar = tk.Menu(root)
filemenu = tk.Menu(menubar, tearoff=0)

filemenu.add_command(label="開く", command=loadCSV)
filemenu.add_command(label="終了", command=root.quit)

menubar.add_cascade(label="ファイル", menu=filemenu)
root.config(menu=menubar)

lb = tk.Label(root)
lb.pack(pady=10)

tk.mainloop()
