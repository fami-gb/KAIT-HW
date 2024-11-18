import tkinter as tk

root = tk.Tk()
root.title("ラーメン注文システム")
root.geometry("300x400")

mainDish = tk.IntVar()
mainDish.set(1000)

# BooleanVar()で取得してもいいが、onvalueで値がウィジェットに紐付けされてる方が可読性が上がりそう
topping1 = tk.IntVar()
topping2 = tk.IntVar()
topping3 = tk.IntVar()

def calc():
    result = int(mainDish.get()) + int(topping1.get()) + int(topping2.get()) + int(topping3.get())
    lbSum.config(text=f"合計金額: {result}円")

lbRamen = tk.Label(root, text="ラーメンの種類を選択してください:")
lbRamen.pack(pady=10)

rd1 = tk.Radiobutton(root, text="塩ラーメン(1000円)", variable=mainDish, value=1000)
rd1.pack(anchor=tk.W, pady=5)

rd2 = tk.Radiobutton(root, text="醤油ラーメン(1300円)", variable=mainDish, value=1300)
rd2.pack(anchor=tk.W, pady=5)

rd2 = tk.Radiobutton(root, text="とんこつラーメン(1500円)", variable=mainDish, value=1500)
rd2.pack(anchor=tk.W, pady=5)

lbTopping = tk.Label(root, text="トッピングを選択してください:")
lbTopping.pack(pady=10)

ckb1 = tk.Checkbutton(root, text="チャーシュー(300円)", variable=topping1, onvalue=300, offvalue=0)
ckb1.pack(anchor=tk.W, pady=5)

ckb2 = tk.Checkbutton(root, text="煮卵(150円)", variable=topping2, onvalue=150, offvalue=0)
ckb2.pack(anchor=tk.W, pady=5)

ckb3 = tk.Checkbutton(root, text="もやし(50円)", variable=topping3, onvalue=50, offvalue=0)
ckb3.pack(anchor=tk.W, pady=5)

btn = tk.Button(root, text="計算", command=calc)
btn.pack(pady=10)

lbSum = tk.Label(root, text="ここに合計金額が表示されます。")
lbSum.pack(pady=10)

tk.mainloop()
