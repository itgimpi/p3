import sys
# ucitava elemente u listu
a = []
for linija in sys.stdin:
    a.append(int(linija))
prosek = sum(a) / len(a)
min = 0;
for i in range(1, len(a)):
    if abs(a[i] - prosek) < abs(a[min] - prosek):
        min = i
print(a[min])
