import matplotlib.pyplot as plt
import os
import pandas as pd

DIG = 8

curpath = os.getcwd()
path = os.path.join(curpath,f'Visualization/HIBP_{DIG}_Percent.txt')

count = {}

with open(path) as file:
    for line in file:
        spi = line.split(':')
        count[int(spi[0])] = float(spi[1].rstrip())

count[0] = 0.0
df = pd.DataFrame(count.items(),columns = ['Passwords','Cumulative Percent'])
df.set_index('Passwords',inplace = True)

plt.figure(num=f'CumulativeChart_{DIG}_digits')
plt.plot(df)
plt.title(f'Cumulative percentage of {DIG} digits passwords')
plt.xlabel('Passwords')
plt.ylabel('Cumulative Percent')
plt.ticklabel_format(style='plain',axis='x')
plt.show()