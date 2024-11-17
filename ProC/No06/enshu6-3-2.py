import tkinter as tk
from tkinter import messagebox

def show_info():
    messagebox.showinfo('情報', 'これは情報メッセージです。')

def show_warning():
    messagebox.showwarning('警告', 'これは警告メッセージです。')

def show_error():
    messagebox.showerror('エラー', 'これはエラーメッセージです。')
    
root = tk.Tk()
root.title('メッセージボックス')
root.geometry('300x200')

info_button = tk.Button(root, text='情報表示', command=show_info)
info_button.pack(pady=10)

warning_button = tk.Button(root, text='警告表示', command=show_warning)
warning_button.pack(pady=10)

error_button = tk.Button(root, text='エラー表示', command=show_error)
error_button.pack(pady=10)

root.mainloop()
