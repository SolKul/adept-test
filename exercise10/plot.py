import numpy as np
import matplotlib.pyplot as plt

filename='/data/adept-test/TimeTransition.csv'
savename='/data/adept-test/build/TimeTransition.png'
time_trans = np.loadtxt(filename, delimiter=',')
times=time_trans[:,0]
x=time_trans[:,1:]

fig,ax=plt.subplots()
ax.plot(times,x[:,0],'o--',label='x')
ax.plot(times,x[:,1],'v:',label='y')
ax.legend()
fig.savefig(savename)