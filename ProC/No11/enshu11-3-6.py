import tkinter as tk
from tkinter import font

root = tk.Tk()
root.title("複数行テキスト")
root.geometry("400x200")
font.nametofont("TkDefaultFont").configure(size=15)

def showContext():
    lb.config(text=tb.get("1.0", tk.END))

tb = tk.Text(root, width=30, height=5)
tb.pack()

btn = tk.Button(root, text="表示", command=showContext)
btn.pack()

lb = tk.Label(root)
lb.pack(pady=10)

tk.mainloop()
