import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['font.family'] = 'MS Gothic'

x = np.array([100, 200, 300, 400, 500])
label = ['Apple', 'Banana', 'Orange', 'Grape', 'Strawberry']
plt.pie(x, labels=label, autopct='%1.1f%%')
plt.show()
