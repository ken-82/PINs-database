import matplotlib.pyplot as plt
import os
import pandas as pd
import numpy as np
import seaborn as sns

DIG = 8

curpath = os.getcwd()
path = os.path.join(curpath,f'PairbyPair/HIBP_{DIG}_PairCount.txt')

tb = np.zeros((10,10))

with open(path) as file:
    for line in file:
        tb[int(line[0])][int(line[1])] = int(line[2:])

sns.heatmap(tb,cbar_kws={'format':'%.0f'})
plt.ylabel('First digit')
plt.xlabel('Second digit')
plt.show()