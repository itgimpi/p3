def ucitaj_datum():
    (d, m, g) = (int(input()), int(input()), int(input()))
    return (g, m, d)

def ispis(datum):
    (g, m, d) = datum
    print(d, m, g)

n = int(input())
max_datum = ucitaj_datum()

for i in range(1, n):
    datum = ucitaj_datum()
    if datum > max_datum:
        max_datum = datum
ispis(max_datum)
