import tkinter as tk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

plt.rcParams['font.family'] = "MS Gothic"
plt.rcParams['font.size'] = 16

fig = plt.figure(figsize=(7.0, 5.0), dpi=100)
ax = fig.add_subplot(111)

root = tk.Tk()
root.title("ラジオボタンでグラフ種類選択")
root.geometry("900x910")

GraphType = tk.IntVar()
GraphType.set(1)

def showGraph():
    CheckedType = GraphType.get()
    x = ['A', 'B', 'C', 'D']
    y = [10, 20, 15, 25]
    ax.clear()
    ax.set_xlabel("カテゴリ")
    ax.set_ylabel("値")
    if (CheckedType == 1):
        ax.set_title("line グラフ")
        ax.plot(x, y, label="折れ線グラフ", color="blue", marker="o")
    elif (CheckedType == 2):
        ax.set_title("bar グラフ")
        ax.bar(x, y, label="棒グラフ", color="orange")
    elif (CheckedType == 3):
        ax.set_title("scatter グラフ")
        ax.scatter(x, y, label="散布図", color="skyblue")
    ax.legend()
    canvas.draw()
    
canvas = FigureCanvasTkAgg(fig, master=root)
canvas.draw()
canvas.get_tk_widget().pack(pady=10)

rb1 = tk.Radiobutton(root, text="折れ線グラフ", variable=GraphType, value=1)
rb1.pack()

rb2 = tk.Radiobutton(root, text="棒グラフ", variable=GraphType, value=2)
rb2.pack()

rb3 = tk.Radiobutton(root, text="散布図", variable=GraphType, value=3)
rb3.pack()

btn = tk.Button(root, text="グラフ表示", command=showGraph)
btn.pack()

tk.mainloop()
