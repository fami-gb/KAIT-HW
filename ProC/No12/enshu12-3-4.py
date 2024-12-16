import tkinter as tk
from tkinter import messagebox

root = tk.Tk()
root.title("四則演算アプリ")
root.geometry("300x300")

val_op = tk.IntVar()
val_op.set(0)

def calc():
    try:
        result = "結果:"
        op = val_op.get()
        val1 = float(tb1.get())
        val2 = float(tb2.get())
        if op == 0:
            result += f"{val1 + val2}"
        elif op == 1:
            result += f"{val1 - val2}"
        elif op == 2:
            result += f"{val1 * val2}"
        elif op == 3:
            result += f"{val1 / val2}"
        lb.config(text=result)
    except ValueError:
        messagebox.showerror("エラー", "不正な入力です")
    except ZeroDivisionError:
        messagebox.showerror("エラー", "0で割ることは出来ません")
tb1 = tk.Entry(root)
tb1.pack()

tb2 = tk.Entry(root)
tb2.pack()

rb_add = tk.Radiobutton(root, text="加算", variable=val_op, value=0)
rb_add.pack(pady=5)

rb_sub = tk.Radiobutton(root, text="減算", variable=val_op, value=1)
rb_sub.pack(pady=5)

rb_mul = tk.Radiobutton(root, text="乗算", variable=val_op, value=2)
rb_mul.pack(pady=5)

rb_div = tk.Radiobutton(root, text="除算", variable=val_op, value=3)
rb_div.pack(pady=5)

btn = tk.Button(root, text="計算", command=calc)
btn.pack(pady=5)

lb = tk.Label(root, text="結果がここに表示されます")
lb.pack(pady=5)

tk.mainloop()
