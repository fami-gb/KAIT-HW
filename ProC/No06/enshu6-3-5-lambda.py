import tkinter as tk

def calc(op):
    num1 = float(entry.get())
    num2 = float(entry2.get())
    if op == 'plus':
        result = num1 + num2
    elif op == 'sub':
        result = num1 - num2
    elif op == 'mul':
        result = num1 * num2
    elif op == 'div':
        result = num1 / num2
    label.config(text=f'{op}の結果: {result}')
    
root = tk.Tk()
root.title('簡易電卓')
root.geometry('400x300')

entry = tk.Entry(root, width=30)
entry.pack(pady=20)

entry2 = tk.Entry(root, width=30)
entry2.pack(pady=20)

frame = tk.Frame(root)
frame.pack(pady=20)

plusBtn = tk.Button(frame, text='+', width=5, command=lambda: calc('plus'))
plusBtn.pack(side=tk.LEFT, padx=10)

subBtn = tk.Button(frame, text='-', width=5, command=lambda: calc('sub'))
subBtn.pack(side=tk.LEFT, padx=10)

mulBtn = tk.Button(frame, text='x', width=5, command=lambda: calc('mul'))
mulBtn.pack(side=tk.LEFT, padx=10)

divBtn = tk.Button(frame, text='÷', width=5, command=lambda: calc('div'))
divBtn.pack(side=tk.LEFT, padx=10)

label = tk.Label(root, text='', font=("Helvetica", 16))
label.pack(pady=20)

tk.mainloop()
