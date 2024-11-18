import tkinter as tk
from tkinter import filedialog, messagebox

root = tk.Tk()
root.title("テキストファイルの文字数表示")
root.geometry("500x300")

def load_text():
    file_path = filedialog.askopenfilename(filetypes=[("Text files", "*.txt")])
    
    if file_path:
        try:
            file = open(file_path, "r", encoding="utf-8")
            content = file.read()
            file.close()
            lb.config(text=f"文字数:{len(content)}")
        except Exception as e:
            messagebox.showerror("エラー", f"エラーが発生しました。\n{e}")
        

btn = tk.Button(root, text="テキストファイルを開く", command=load_text)
btn.pack(pady=10)

lb = tk.Label(root, text="ここに文字数が表示されます")
lb.pack(pady=10)

tk.mainloop()
