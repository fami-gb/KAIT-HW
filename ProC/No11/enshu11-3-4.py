import tkinter as tk
from tkinter import messagebox

root = tk.Tk()
root.title("足し算計算機")
root.geometry("300x200")

def calc():
    try:
        element1 = int(entry1.get())
        element2 = int(entry2.get())
    except ValueError:
        messagebox.showwarning("警告", "整数を入力してください")
        
    lb.config(text=f"結果: {element1+element2}")

entry1 = tk.Entry(root, width=15)
entry1.pack(pady=10)

entry2 = tk.Entry(root, width=15)
entry2.pack()

btnCalc = tk.Button(root, text="計算", command=calc)
btnCalc.pack()

lb = tk.Label(root, text="結果:")
lb.pack(pady=10)

tk.mainloop()
