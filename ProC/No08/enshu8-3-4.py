import tkinter as tk
from tkinter import messagebox

root = tk.Tk()
root.title("栃木県の県庁所在地クイズ")
root.geometry("300x200")

quiz = tk.IntVar()
quiz.set(2)

def isValid():
    if quiz.get() == 1:
        messagebox.showinfo("結果", "正解です！！")
    else:
        messagebox.showinfo("結果", "不正解です。もう一度試してください。")

lb = tk.Label(root, text="栃木県の県庁所在地はどれですか？", font=("Helvetica",11))
lb.pack(pady=10)

rd1 = tk.Radiobutton(root, text="宇都宮市", variable=quiz, value=1)
rd1.pack(anchor=tk.W, pady=5)

rd2 = tk.Radiobutton(root, text="栃木市", variable=quiz, value=2)
rd2.pack(anchor=tk.W, pady=5)

rd3 = tk.Radiobutton(root, text="日光市", variable=quiz, value=3)
rd3.pack(anchor=tk.W, pady=5)

btn = tk.Button(root, text="回答", command=isValid)
btn.pack(pady=10)

tk.mainloop()
