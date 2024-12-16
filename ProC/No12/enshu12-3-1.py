import tkinter as tk
from tkinter import messagebox

def dummy_action():
    messagebox.showinfo("info", "選択されました。")

root = tk.Tk()
root.title("複数メニュー")
root.geometry("300x200")

menubar = tk.Menu(root)
file_menu = tk.Menu(menubar, tearoff=0)
edit_menu = tk.Menu(menubar, tearoff=0)

file_menu.add_command(label="新規作成", command=dummy_action)
file_menu.add_command(label="終了", command=root.quit)

edit_menu.add_command(label="元に戻す", command=dummy_action)
edit_menu.add_command(label="やり直し", command=dummy_action)

menubar.add_cascade(label="ファイル", menu=file_menu)
menubar.add_cascade(label="編集", menu=edit_menu)

root.config(menu=menubar)

tk.mainloop()
