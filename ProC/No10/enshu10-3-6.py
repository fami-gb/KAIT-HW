import tkinter as tk

root = tk.Tk()
root.title("テーマ選択アプリ")
root.geometry("300x200")

col = tk.StringVar()
col.set("white")

def menu_reset():
    root.config(bg="white")
    rb_light.config(bg="white", fg="black", activebackground="lightgray")
    rb_dark.config(bg="white", fg="black", activebackground="lightgray")
    lb.config(text="現在のテーマ: ライトテーマ", bg="white", fg="black")

def changeTheme():
    if col.get() == "white":
        root.config(bg="white")
        rb_light.config(bg="white", fg="black", activebackground="lightgray")
        rb_dark.config(bg="white", fg="black", activebackground="lightgray")
        lb.config(text="現在のテーマ: ライトテーマ", bg="white", fg="black")
    elif col.get() == "black":
        root.config(bg="black")
        rb_light.config(bg="black", fg="white")
        rb_dark.config(bg="black", fg="white")
        lb.config(text="現在のテーマ: ダークテーマ", bg="black", fg="white")

def exit_form():
    root.quit()

menubar = tk.Menu(root)

option_menu = tk.Menu(menubar, tearoff=0)
option_menu.add_command(label="リセット", command=menu_reset)
option_menu.add_command(label="終了", command=exit_form)

menubar.add_cascade(label="オプション", menu=option_menu)
root.config(menu=menubar)

rb_light = tk.Radiobutton(root, text="ライトモード", variable=col, value="white", command=changeTheme)
rb_light.pack(pady=10)

rb_dark = tk.Radiobutton(root, text="ダークモード", variable=col, value="black", command=changeTheme)
rb_dark.pack(pady=10)

lb = tk.Label(root, text="現在のテーマ: ライトモード")
lb.pack(pady=10)

tk.mainloop()
