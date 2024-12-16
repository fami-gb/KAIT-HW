import tkinter as tk

def convert_inch():
    inch = float(tb.get())
    cm = inch * 2.54
    result_lb.config(text=f"{cm:.2f}cm")

root = tk.Tk()
root.title("長さ単位変換アプリ")
root.geometry("300x200")

lb = tk.Label(root, text="インチを入力")
lb.pack()

tb = tk.Entry(root)
tb.pack()

btn = tk.Button(root, text="変換", command=convert_inch)
btn.pack()

result_lb = tk.Label(root, text="ｃｍ: ")
result_lb.pack()

tk.mainloop()
