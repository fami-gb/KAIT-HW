import tkinter as tk
from tkinter import filedialog

root = tk.Tk()
root.title("ファイルを読み込む")
root.geometry("800x600")

def load_txt():
    file_path = filedialog.askopenfilename(filetypes=[("Text files", "*.txt")])
    
    if file_path:
        file = open(file_path, "r", encoding="utf-8")
        content = file.read()
        file.close()
        t1.delete("1.0", tk.END)
        t1.insert(tk.END, content)
        lb.config(text=f"文字数: {len(content)}")

def exit_form():
    root.quit()

menubar = tk.Menu(root)

file_menu = tk.Menu(menubar, tearoff=0)
file_menu.add_command(label="開く", command=load_txt)
file_menu.add_command(label="終了", command=exit_form)

menubar.add_cascade(label="ファイル", menu=file_menu)
root.config(menu=menubar)

t1 = tk.Text(root)
t1.pack(pady=10, expand=True, fill="both")

lb = tk.Label(root, text="文字数: ")
lb.pack(pady=10, anchor=tk.W)

tk.mainloop()
