import tkinter as tk
from tkinter import messagebox

users = { "admin":"1234", "user":"abcd", "amano":"usume" }

root = tk.Tk()
root.title("ログイン画面")
root.geometry("300x200")

def handleLogin():
    username = tb_username.get()
    password = tb_pswd.get()
    if (username in users) and (users[username] == password):
        messagebox.showinfo("ログイン", "ログイン成功！")
    else:
        messagebox.showwarning("警告", "ログイン失敗...")

lb_username = tk.Label(root, text="ユーザー名:")
lb_username.pack()

tb_username = tk.Entry(root)
tb_username.pack()

lb_pswd = tk.Label(root, text="パスワード:")
lb_pswd.pack()

tb_pswd = tk.Entry(root, show="*")
tb_pswd.pack()

btn_login = tk.Button(root, text="ログイン", command=handleLogin)
btn_login.pack()

tk.mainloop()
