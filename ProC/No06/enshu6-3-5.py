import tkinter as tk

def plus():
    num1 = int(entry.get())
    num2 = int(entry2.get())
    result.config(text=num1 + num2)
    
def minus():
    num1 = int(entry.get())
    num2 = int(entry2.get())
    result.config(text=num1 - num2)

def mul():
    num1 = int(entry.get())
    num2 = int(entry2.get())
    result.config(text=num1 * num2)

def div():
    num1 = int(entry.get())
    num2 = int(entry2.get())
    result.config(text=num1 / num2)
    
root = tk.Tk()
root.title('簡易電卓')
root.geometry('400x300')

entry = tk.Entry(root, width=30)
entry.pack(pady=20)

entry2 = tk.Entry(root, width=30)
entry2.pack(pady=20)

result = tk.Label(root, text='')
result.pack(pady=20)

frame = tk.Frame(root)
frame.pack(pady=40)

plusBtn = tk.Button(frame, text='+', command=plus)
plusBtn.pack(side=tk.LEFT)

minusBtn = tk.Button(frame, text='-', command=minus)
minusBtn.pack(side=tk.LEFT)

mulBtn = tk.Button(frame, text='x', command=mul)
mulBtn.pack(side=tk.LEFT)

divBtn = tk.Button(frame, text='÷', command=div)
divBtn.pack(side=tk.LEFT)

tk.mainloop()
