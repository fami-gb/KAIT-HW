import tkinter as tk
from tkinter import filedialog, messagebox
import pandas as pd

root = tk.Tk()
root.title("CSVファイル読み込みサンプル")
root.geometry("500x500")

def load_csv():
    file_path = filedialog.askopenfilename(filetypes=[("CSV files", "*.csv")])
    
    if file_path:
        try:
            df = pd.read_csv(file_path)
            text.delete("1.0", tk.END)
            text.insert(tk.END, df.to_string(index=False))
        except Exception as e:
            messagebox.showerror("エラー", f"ファイルを読み込めませんでした。\n{e}")
        

def form_exit():
    isClose = messagebox.askyesno("終了", "アプリケーションを終了しますか？")
    if isClose:
        root.quit()

menubar = tk.Menu(root)

file_menu = tk.Menu(menubar, tearoff=0)
file_menu.add_command(label="開く", command=load_csv)
file_menu.add_separator()
file_menu.add_command(label="終了", command=form_exit)

menubar.add_cascade(label="ファイル", menu=file_menu)
root.config(menu=menubar)

text = tk.Text(root, wrap="none")
text.pack(pady=10, expand=True, fill="both")

tk.mainloop()
