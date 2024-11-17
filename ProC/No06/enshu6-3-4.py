import tkinter as tk

global count
count = 0

def cntUp():
    global count
    count += 1
    current_cnt.config(text=count)

def cntDown():
    global count
    if count == 0:
        count = 0
    else:
        count -= 1
    current_cnt.config(text=count)
    
    


root = tk.Tk()
root.title('カウントアップ・カウントダウン')
root.geometry('400x300')

current_cnt = tk.Label(root, text=count, font=("Helvetica", 30))
current_cnt.pack(pady=20)

btn_frame = tk.Frame(root)
btn_frame.pack(pady=20)

cntUpBtn = tk.Button(btn_frame, text='カウントアップ', command=cntUp)
cntUpBtn.pack(side=tk.LEFT, padx=10)

cntDownBtn = tk.Button(btn_frame, text='カウントダウン', command=cntDown)
cntDownBtn.pack(side=tk.LEFT, padx=10)

root.mainloop()
