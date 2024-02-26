import numpy as np
import matplotlib.pyplot as plt
with open('data.txt', 'r') as w:
    t = w.readlines()
c = ''
g = ''
l = []
s = []
a = []
b = []
d = 0.06
e = 0.01
for i in range(499):
    a.append(int(t[i][:-1]))
for i in range(499, 998):
    b.append(float(t[i][:-1]))

x = np.array(a)
y = np.array(b)

plt.errorbar(x, y,  xerr = 0, yerr = 0, fmt='.k')
plt.grid()
plt.ylabel('$T, c$')
plt.xlabel('$N, эл$')
plt.title("Зависимость времени работы программы от размера массива")
plt.legend(fontsize=10)
plt.tight_layout()
plt.show()
