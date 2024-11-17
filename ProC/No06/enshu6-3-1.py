import tkinter as tk

def show_message():
    message = entry.get()
    label.config(text=message)
    
root = tk.Tk()
root.title('メッセージアプリ')
root.geometry('400x300')

entry = tk.Entry(root, width=50)
entry.pack(pady=20)

button = tk.Button(root, text='表示', command=show_message)
button.pack(pady=10)

label = tk.Label(root, text='', font=('Helvetica', 14))
label.pack(pady=20)

tk.mainloop()
