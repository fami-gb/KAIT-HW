import tkinter as tk

root =  tk.Tk()
root.title("数値を二倍にして表示")
root.geometry("300x300")

def twice():
    entry2.insert(0,int(entry1.get())*2)

entry1 = tk.Entry(root, width=20)
entry1.pack(pady=10)

entry2 = tk.Entry(root, width=20)
entry2.pack(pady=10)

twiceBtn = tk.Button(root, text="二倍する", command=twice)
twiceBtn.pack(pady=20)

tk.mainloop()
