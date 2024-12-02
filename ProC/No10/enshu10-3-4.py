import tkinter as tk

root = tk.Tk()
root.title("文字列の逆順表示")
root.geometry("300x200")

def ToInverse():
    inversedText = tb1.get()[::-1]
    tb2.insert(0, inversedText)

lb1 = tk.Label(root, text="入力:")
lb1.pack(pady=5)

tb1 = tk.Entry(root, width=25)
tb1.pack(pady=10)

lb2 = tk.Label(root, text="結果:")
lb2.pack(pady=5)

tb2 = tk.Entry(root, width=25)
tb2.pack(pady=10)

btn = tk.Button(root, text="逆順にする", command=ToInverse)
btn.pack(pady=5)

tk.mainloop()
