import tkinter as tk

def plus():
    num1 = float(entry.get())
    num2 = float(entry2.get())
    result.config(text=num1 + num2)
    
def minus():
    num1 = float(entry.get())
    num2 = float(entry2.get())
    result.config(text=num1 - num2)

root = tk.Tk()
root.title('足し算引き算')
root.geometry('400x300')

entry = tk.Entry(root, width=20)
entry.pack(pady=20)

entry2 = tk.Entry(root, width=20)
entry2.pack(pady=10)

btn_frame = tk.Frame(root)
btn_frame.pack(pady=20)

plusBtn = tk.Button(btn_frame, text='+', command=plus)
plusBtn.pack(side=tk.LEFT, pady=10)

minusBtn = tk.Button(btn_frame, text='-', command=minus)
minusBtn.pack(side=tk.LEFT, pady=10)

result = tk.Label(root, text='結果', font=("Helvetica", 16))
result.pack(pady=10)

root.mainloop()
