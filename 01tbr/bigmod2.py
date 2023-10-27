#                BigMod


osnova = int ( input() )
stepen = int ( input() )
ost = int ( input() )

osnova = osnova % ost

res = 1
for i in range (stepen):
    res = res * osnova % ost

print ( res )