import tkinter as tk

root = tk.Tk()
root.title("数値の2乗計算")
root.geometry("300x200")

def calc_square():
    result = ""
    try:
        num = float(tb.get())
        result = f"結果: {num**2}"
    except ValueError:
        result = "エラー: 数値を入力してください"
    result_label.config(text=result)

tb = tk.Entry(root, width=15)
tb.pack(pady=10)

btn = tk.Button(root, text="計算", command=calc_square)
btn.pack(pady=5)

result_label = tk.Label(root, text="結果: ")
result_label.pack(pady=5)

tk.mainloop()
