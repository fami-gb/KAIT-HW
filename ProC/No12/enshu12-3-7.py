import tkinter as tk

root = tk.Tk()
root.title("シンプル計算機")
root.geometry("300x200")

def calc():
    lb.config(text=f"{eval(tb.get())}")

tb = tk.Entry(root)
tb.pack()

btn = tk.Button(root, text="計算", command=calc)
btn.pack()

lb = tk.Label(root, text="結果がここに表示されます")
lb.pack()

tk.mainloop()
