import os
import pandas as pd

DIG = 3

curpath = os.getcwd()
path = os.path.join(curpath,f'HIBP {DIG} digit.txt')

count = {}

with open(path) as file:
    for line in file: count[line[:DIG]] = int(line[DIG+1:-1])

df = pd.DataFrame(count.items(),columns = ['Password','Count'])
df.set_index('Password',inplace = True)

df = df.sort_values(by='Count',ascending=False)

print(df.head(20))