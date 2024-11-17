import pandas as pd

data = { "名前": ["吉井", "石堂", "戸田", "樫木"],
         "年齢":[24, 45, 35, 29],
         "職業": ["技術者", "医者", "技術者", "先生"] }
df = pd.DataFrame(data)
print(df.groupby("職業")["年齢"].mean())
