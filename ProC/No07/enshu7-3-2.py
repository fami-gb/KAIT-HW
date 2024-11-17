import tkinter as tk

root = tk.Tk()
root.title("チェック済み項目の表示")
root.geometry("300x300")

var_a = tk.IntVar()
var_b = tk.IntVar()
var_c = tk.IntVar()

def check():
    result = "選択された項目："
    if var_a.get() == 1:
        result += " 項目A"
    if var_b.get() == 1:
        result += " 項目B"
    if var_c.get() == 1:
        result += " 項目C"
    ckblb.config(text=result)

ckbA = tk.Checkbutton(root, text="項目A", variable=var_a)
ckbA.pack(pady=10)

ckbB = tk.Checkbutton(root, text="項目B", variable=var_b)
ckbB.pack(pady=10)

ckbC = tk.Checkbutton(root, text="項目C", variable=var_c)
ckbC.pack(pady=10)

ckblb = tk.Label(root, text="三択された項目がここに表示されます")
ckblb.pack(pady=10)

btn = tk.Button(root, text="選択を表示", command=check)
btn.pack(pady=10)

tk.mainloop()
