import tkinter as tk

root = tk.Tk()
root.title("数値入力アプリ")
root.geometry("300x200")

def multiply():
    try:
        val1 = float(tb1.get())
        val2 = float(tb2.get())
        lb3.config(text=f"結果:{val1 * val2}")
    except ValueError:
        lb3.config(text="エラー:数字を入力してください！")
        
    
lb1 = tk.Label(root, text="数値1:")
lb1.pack(pady=5)

tb1 = tk.Entry(root)
tb1.pack(pady=5)

lb2 = tk.Label(root, text="数値2:")
lb2.pack(pady=10)

tb2 = tk.Entry(root)
tb2.pack(pady=5)

btn = tk.Button(root, text="計算", command=multiply)
btn.pack(pady=5)

lb3 = tk.Label(root, text="ここに計算結果が表示されます")
lb3.pack(pady=5)

tk.mainloop()
