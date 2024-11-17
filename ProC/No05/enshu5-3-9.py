import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['font.family'] = "MS Gothic"

df = pd.read_csv("05products.csv")

x = df.groupby('カテゴリ')['売上数'].sum()
label = df['カテゴリ'].unique()
plt.pie(x, labels=label, autopct='%1.1f%%')
plt.title('カテゴリ別総売上数')
plt.show()
