import tkinter as tk

root = tk.Tk()
root.title("文字列を逆にして表示")
root.geometry("400x200")

def inverse():
    lb.config(text=entry.get()[::-1])

entry = tk.Entry(root, width=20)
entry.pack(pady=10)

lb = tk.Label(root, text="逆順の文字列がここに表示されます")
lb.pack(pady=10)

btn = tk.Button(root, text="逆順にする", command=inverse)
btn.pack(pady=10)

tk.mainloop()
