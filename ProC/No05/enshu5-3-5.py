import numpy as np

data = np.random.randint(1, 101, size=100)
print('平均:', np.mean(data))
print('中央値:', np.median(data))
print('標準偏差:', np.std(data))
