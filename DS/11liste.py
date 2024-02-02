import sys
# ucitava elemente u listu
a = []
for linija in sys.stdin:
    a.append(int(linija))
prosek = sum(a) / len(a)
imin = 0
for i in range(1, len(a)):
    if abs(a[i] - prosek) < abs(a[imin] - prosek):
        imin = i
print(a[imin])
