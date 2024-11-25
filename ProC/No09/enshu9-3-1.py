import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['font.family'] = "MS Gothic"

df = pd.read_csv('09sales_data.csv')
x = df['Month']
y = df['Sales']

plt.plot(x, y, marker="o")
plt.xlabel("月")
plt.ylabel("売上")
plt.title("月別売上")
plt.legend()
plt.show()
