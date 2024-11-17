import pandas as pd
import numpy as np

data = { "名前": ["Anna", "Ben", "Cathy", "Dave"], "年齢": [23, 35, 45, 28] }
df = pd.DataFrame(data)
print(df[df["年齢"] >= 30])
