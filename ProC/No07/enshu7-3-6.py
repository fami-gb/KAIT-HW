import tkinter as tk

root = tk.Tk()
root.title("数値の合計を表示")
root.geometry("400x200")

def calcSum():
    result = 0
    text = txt.get("1.0", tk.END).strip().splitlines()
    for num in text:
        result += int(num)
    lb.config(text=f"合計:{result}")

txt = tk.Text(root, width=20, height=5)
txt.pack(pady=10)

lb = tk.Label(root, text="合計がここに表示されます")
lb.pack(pady=10)

btn = tk.Button(root, text="合計を表示", command=calcSum)
btn.pack(pady=10)

tk.mainloop()
