a = int ( input() )
n = int ( input() )
m = int ( input() )

a %= m
res = 1
for i in range (n):
    res = res * a % m

print ( res )