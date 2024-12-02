import tkinter as tk

root = tk.Tk()
root.title("数値の加算")
root.geometry("300x200")

def calc():
    tb3.delete(0, tk.END)
    try:
        num1 = float(tb1.get())
        num2 = float(tb2.get())
        tb3.insert(0, num1+num2)
    except ValueError:
        tb3.insert(0, "エラー: 数値を入力してください")
    

lb1 = tk.Label(root, text="数値1:")
lb1.pack(pady=5)

tb1 = tk.Entry(root, width=15)
tb1.pack()

lb2 = tk.Label(root, text="数値2:")
lb2.pack(pady=5)

tb2 = tk.Entry(root, width=15)
tb2.pack()

lb3 = tk.Label(root, text="結果:")
lb3.pack(pady=5)

tb3 = tk.Entry(root, width=15)
tb3.pack()

btn = tk.Button(root, text="加算", command=calc)
btn.pack(pady=5)

tk.mainloop()
