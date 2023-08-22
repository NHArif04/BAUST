from numpy import *

a = zeros(100)
b = zeros(100)
r = zeros(100) 

b[1] = 1

a[1] = 13/12 
a[2] = -3/8
a[3] = 1/24

def get_b(j):
    for k in range (1,j+1):
        b[j+1] += b[j+1-k]*a[k]  
        #b(n) = b(n-1)*a(1) + b(n-2)*a(2)+..+b(1)+a(n-1)

for i in range(1,99):
    get_b(i)
    
for root in range(1,99):
    r[root] = b[root]/b[root+1]
    print(r[root])
    #root(n) = b(n)/b(n+1)