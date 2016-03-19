<h1>Mintafeladat</h1>
Bulit szerveztünk a hétvégén a haverokkal, de kicsit túl nagyra sikeredett a buli, így a költségvetés kiszámolása elég nehézkes. 
Azt látjuk, hogy mennyi pénzünk maradt a végére, de megbeszéltük, hogy írunk egy programot ami kiszámolja nekünk, hogy...

<h3>Feladat minták:</h3>

1.  melyik vásárlás volt a legkisebb, mire költöttünk a legkevesebbet.
2.  volt-e olyan amikor nem mindenki fizetett be a közösbe.
3.  mennyit költöttünk összesen.

Erre kéne írnunk egy programot.

<h2>Bemenet</h2>

Az input tartalmazza a vásárlásokat és a közös kasszába való befizetéseket is vegyesen. 
Az input ezen rekordok számával kezdődik, majd minden sor megadja egy vásárlás 1-1 tételét, 
vagy ha közösbe fizetésről volt szó, akkor 1-1 ember által beadott pénzösszeget.

5 
5 -3000 -3000 -3000 -3000 -3000
4 1000 2000 3500 4000
5 -500 -500 -500 -500 -500
2 1000 2500
3 500 1000 1500

<h2>Output</h2>

A fent megadott feladatok minta outputjai a következők, zárójelben a lehetsgées outputokat adom meg.

1.  2 ([index]|Nincs)
2.  Nincs (Nincs|Van)
3.  16000 ([Érték])

<h2>Előfeltételek</h2>

  - Számosság nem lehet negatív
  - Egy befizetés nem lehet nagyobb mint 5000Ft
  - Egy termék ára nem lehet több 10000Ft-nál
