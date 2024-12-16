import tkinter as tk

root = tk.Tk()
root.title("シンプルなToDoリスト")
root.geometry("300x250")

def add2List():
    task = tb.get()
    Lb.insert(tk.END, task)
    tb.delete(0, tk.END)

tb = tk.Entry(root)
tb.pack()

btn = tk.Button(root, text="追加", command=add2List)
btn.pack()

Lb = tk.Listbox(root)
Lb.pack()

tk.mainloop()
