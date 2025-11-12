with open("Dane/1.2024_moj_input.txt") as h:
    dane = h.readlines()
    leftList = []
    rightList = []
    for line in dane:
        leftList.append(int(line.split(" ")[0]))
        rightList.append(int(line.split(" ")[-1].strip("\n")))
    sortLeft = sorted(leftList)
    sortRight = sorted(rightList)
    suma = 0
    for i in range(len(sortLeft)):
        suma += abs(sortLeft[i] - sortRight[i])
    print("Rozwiazanie czesci pierwszej:")
    print(suma)
    ile = 0
    for liczba in leftList:
        ile += rightList.count(liczba) * liczba
    print("Rozwiazanie czesci drugiej:")
    print(ile)
