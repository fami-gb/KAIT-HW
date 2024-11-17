import pandas as pd

df = pd.read_csv('./05students.csv')

math_avg = df['数学'].mean()
english_avg = df['英語'].mean()
science_avg = df['科学'].mean()

print('数学の平均点', math_avg)
print('英語の平均点', english_avg)
print('科学の平均点', science_avg)
