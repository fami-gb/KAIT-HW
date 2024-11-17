import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('./05temperature.csv')

plt.rcParams['font.family'] = 'MS Gothic'

plt.plot(df['月'], df['気温'], color='blue', marker='o')

plt.xlabel('月')
plt.ylabel('気温')
plt.title('月別の気温の推移')
plt.show()
