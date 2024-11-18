import tkinter as tk
import numpy as np

data = np.array([10, 20, 30, 40, 50])

root = tk.Tk()
root.title("数値配列の統計情報")
root.geometry("300x200")

def calc(op):
    result = ""
    if op == "平均":
        result = np.mean(data)
    elif op == "合計":
        result = np.sum(data)
    elif op == "標準偏差":
        result = np.std(data)
    lbStats.config(text=f"{op}: {result}")
        

menubar = tk.Menu(root)

file_name = tk.Menu(menubar, tearoff=0)
file_name.add_command(label="平均", command=lambda:calc("平均"))
file_name.add_command(label="合計", command=lambda:calc("合計"))
file_name.add_command(label="標準偏差", command=lambda:calc("標準偏差"))

menubar.add_cascade(label="統計", menu=file_name)
root.config(menu=menubar)

lb = tk.Label(root, text=f"データ:{data}")
lb.pack(pady=10)

lbStats = tk.Label(root, text="統計情報がここに表示されます。")
lbStats.pack(pady=10)

tk.mainloop()
