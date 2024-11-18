import tkinter as tk
from tkinter import messagebox

def calculate():
    try:
        num1 = float(entry1.get())
        num2 = float(entry2.get())
        q = num1 / num2
        r = num1 % num2
        lb.config(text=f"商:{q}, 余り:{r}")
    except ValueError:
        messagebox.showerror("エラー", "有効な整数を入力してください。")
    except ZeroDivisionError:
        messagebox.showerror("エラー", "0で割ることはできません。")
    
root = tk.Tk()
root.title("商と余りの計算アプリ")
root.geometry("300x300")

entry1 = tk.Entry(root, width=20)
entry1.pack(pady=10)

entry2 = tk.Entry(root, width=20)
entry2.pack(pady=10)

btn = tk.Button(root, text="計算", command=calculate)
btn.pack(pady=10)

lb = tk.Label(root, text="ここに結果が表示されます")
lb.pack(pady=10)

tk.mainloop()
