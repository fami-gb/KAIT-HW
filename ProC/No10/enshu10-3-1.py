import tkinter as tk
from tkinter import messagebox

def showMsg():
    messagebox.showinfo("情報", "ボタンがクリックされました！")

root = tk.Tk()
root.title("基本構造")
root.geometry("300x200")

lb = tk.Label(root, text="Hello, Tkinter!")
lb.pack(pady=20)

btn = tk.Button(root, text="クリック", command=showMsg)
btn.pack(pady=20)

tk.mainloop()

