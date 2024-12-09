import pandas as pd
import tkinter as tk
from tkinter import messagebox, filedialog

root = tk.Tk()
root.title("CSVデータをフィルタリング")
root.geometry("300x200")

def loadCSV():
    filepath = filedialog.askopenfilename(filetypes=[("CSV files", "*.csv")])
    if filepath:
        try:
            df = pd.read_csv(filepath)
            filtered_df = df[df["点数"] >= 90]
            print(filtered_df)
        except Exception as e:
            messagebox.showerror("エラー", f"エラー'{e}'")
        except FileNotFoundError:
            messagebox.showerror("エラー", f"ファイルが選択されませんでした。")

btn = tk.Button(root, text="CSVを読み込む", command=loadCSV)
btn.pack(pady=10)

tk.mainloop()
