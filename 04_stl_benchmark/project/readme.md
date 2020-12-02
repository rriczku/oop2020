# STL Benchmarks - Report


Run on (2 X 2700 MHz CPU s)

1) Operatory i funkcje haszujace

W strukturze Small tablica sklada sie z jednego elementu. Dlatego implementacja operatorow jest prosta.
Wystarczy porownywac tylko jeden element. Dla struktur Medium i Large implementacja operatorow nie rozni
sie. Operatory sa definiowane w zaleznosci od struktur. W tym konkretnym przypadku iterujemy po wszystkich
elementach tablic struktur. Gdy napotkamy dwie rozne wartosci pod tymi samymi indeksami, to dokonujemy
porownania wartosci i zwracamy wynik. Operator rownosci najlepiej implementowac przez "==".
Funkcja hashujaca jest stosowana do rozmieszczania elementow w kontenerach. Powinna tym samym wartosciom 
przypisywac takiego samego hasha. Hash dla dwoch podobnych wartosci powinien sie znaczaco roznic.
Dla struktury Small zwracam pojedynczy element. Dla dwoch pozostalych struktur jest to suma elementow z
elementem na pozycji i%6 podzielona przez rozmiar struktury.

2)
W testach wypelniam struktury wartosciami wczesniej znanymi. Przez to wiem jakiego wyniku nalezy 
sie spodziewac. Np dla funkcji hashujacej obie struktury wypelniam dwoma takimi samymi wartosciami
poniewaz spodziewam sie ze wyniki beda rowne - ASSERT_EQ zwroci wartosc true. Dla operatorow
sprawdzam rozne mozliwe warianty, rowniez ze znanymi wczesniej wartosciami. Jezeli wyniki testow
pokrywaja sie z moimi wczesniejszymi zalozeniami, uznaje ze funkcje zostaly napisane poprawnie.
Przy wypelnianiu struktur losowymi wartosciami, nie wiemy jakich wynikow mamy sie spodziewac.

3)
W benchmarkach testujacych operatory tworze dwa obiekty struktury i wypelniam je losowymi wartosciami.
W petli wywoluje metode ktora chce przetestowac. Uzyskany czas jest niezwykle istotny. Od szybkosci 
operatorow zalezy jak szybko tworzone beda uporzadkowane kontenery sekwencyjne, funkcje sortujace. 
Wyniki uzyskane dla operatorow sa satysfakcjonujace.

Od tego jak wydajna jest nasza funkcja hashujaca zalezy czas tworzenia nieuporzadkowanych kontenerow
sekwencyjnych. Dlatego jesli chcemy by nasza praca byla wydajna, musimy dobrze zaimplementowac funkcje 
hashujaca.
Wyniki benchmarkow dla Small i Medium sa satysfakcjonujace. Dla Large wynik jest dlugi, 
przez co kontenery nieuporzadkowane dzialaja gorzej.
W przypadku benchmarkow powinnismy wypelniac struktury losowymi wartosciami poniewaz daje 
to wiarygodne wyniki.

4)
Zlozonosc jest mierzona przy pomocy funkcji biblioteki benchmark. W kazdej funkcji okreslamy 
rozmiar dla danego kroku. Jest on zmieniany za pomoca funkcji wbudowanych. Przy pomocy metody
Range ustalamy zakres. RangeMultiplier okresla jak zwiekszac liczbe N w kolejnym kroku. Na koncu poprzez
funkcje Complexity wyliczana jest zlozonosc algorytmiczna. Dla moich kontenerow ( list, multimap, unordered multimap)
wyniki w wiekszosci pokrywaja sie z tymi umieszczonymi na cppreference.com. Wyniki, ktore sie roznily byly 
lepsze niz te na cppreference. Moze to wynikac z faktu, ze dane byly dobrze rozrzucone, a funkcje hasujace oraz 
operatory dobrze zaimplementowane.  
Dla funkcji modyfikujacych kontener benchmarki musza byc pisane z wieksza ostroznoscia. By wyniki byly miarodajne, 
nalezy wziac pod uwage czas i zlozonosc operacji, ktore sa niezbedne do wykonania benchmarku. Jedna z metod jest 
otoczenie operacji, ktore nie sa istotne przez PauseTiming oraz ResumeTiming. Sprawia operacje w srodku nie beda 
brane pod uwage przy wyliczaniu zlozonosci. Trzeba jednak pamietac by od czasu odjac czas, ktory "zatrzymanie czasu"
pochlania. Moze byc on rozny w zaleznosci od maszyny na ktorej benchmarki sa wykonywane. 
W moim wykonaniu, korzystam z PauseTiming oraz ResumeTiming raczej tylko dla struktury Small. Jest to spowodowane 
tym, ze metoda ta znaczaco wplywa na czas wykonywania benchmarkow. W niektorych przypadkach zdazylo mi sie, ze 
srodowisko clion "odmowilo posluszenstwa". W wiekszosci benchmarkow korzystam z metody baseline. Najpiew wykonuje 
benchmark dla operacji tworzenia i wypelnienia kontenera, a nastepnie benchmark wlasciwy. Koryguje wynik porownujac
rezultat z "pomocniczym" benchmarkiem.

5) W trybie release wlaczona jest optymalizacja kodu. Optymalizator wykrywa fragmenty kodu, z ktorych nie korzystam
i je wyrzuca. Aby sie przed tym uchornic korzystam z funckji DoNotOptimize oraz ClobberMemory, ktore nie pozwalaja
na usuniecie kodu, ktory jest powiazany z przekazanymi argumentami. Funkcja ClobberMemory wymusza aktualizacje i zapis 
zmian do pamieci.