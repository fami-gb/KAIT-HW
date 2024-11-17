import pandas as pd

data = { "名前": ["Emily", "Frank", "Grace", "Hannah"], "年齢": [29, 34, 26, 38] }
df = pd.DataFrame(data)

print(df[df["年齢"] == df["年齢"].max()])

print(df.loc[df["年齢"].idxmax()])
