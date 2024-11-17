import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('05sales.csv')

plt.rcParams['font.family'] = "MS Gothic"
plt.bar(df['月'], df['売上'], color='skyblue')

plt.xlabel('月')
plt.ylabel('売上')
plt.title('月間売上')
plt.show()
