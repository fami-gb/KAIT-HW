import tkinter as tk

root = tk.Tk()
root.title("選択した項目を表示")
root.geometry("300x400")

def dispPref():
    selected_pref = [listbox.get(i) for i in listbox.curselection()]
    lb.config(text="選択された道県:" + ",".join(selected_pref))

listbox = tk.Listbox(root, selectmode=tk.MULTIPLE)
listbox.pack(pady=10)

prefs = ["北海道", "青森県", "岩手県", "宮城県", "秋田県", "山形県", "福島県"]
for pref in prefs:
    listbox.insert(tk.END, pref)
    
lb = tk.Label(root, text="選択された項目がここに表示されます")
lb.pack(pady=10)

btn = tk.Button(root, text="表示", command=dispPref)
btn.pack(pady=10)

tk.mainloop()
