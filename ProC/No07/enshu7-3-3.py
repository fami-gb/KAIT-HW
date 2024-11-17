import tkinter as tk

root = tk.Tk()
root.title("テキストの長さ表示")
root.geometry("400x200")

def calcLen():
    lb.config(text=f"文字数：{len(entry.get())}")

entry = tk.Entry(root, width=20)
entry.pack(pady=10)

lb = tk.Label(root, text="テキストの長さがここに表示されます")
lb.pack(pady=10)

btn = tk.Button(root, text="長さ計算", command=calcLen)
btn.pack(pady=10)

tk.mainloop()
