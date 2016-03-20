<h1>Mintafeladat</h1>
Rádióban dolgozunk és a főnök kitalálta, hogy csinál egy válogatásversenyt, amire rengeteg jelentkezés érkezett, így megszívtuk, 
tehát megkért minket, hogy írjunk egy programot ami megmondja nekünk, hogy...

<h3>Feladat minták:</h3>

1.  melyik válogatás a leghosszabb ami még a műsoridőbe belefér (10 perces műsoridő).
2.  melyik a leghosszabb válogatás azok közül amikben nincs 5 percnél hosszabb szám.
3.  mennyi a számok átlagos hossza a pályázók számainál.

Erre kéne írnunk egy programot.

<h2>Bemenet</h2>

Az input tartalmazza a pályázatokat, ahol minden egyes sor 1-1 pályázatnak felel meg.
Az input ezen rekordok számával kezdődik, majd minden sor megadja, hogy mennyi számból áll a válogatás amit a pályázó beküldött, 
majd sorba egymás után a számok hosszait másodpercben megadva.

<pre><code>3 
3 90 180 184
4 90 170 150 130
2 200 200
</code></pre>

<h2>Output:</h2>

1.  [index]|Nincs
2.  [Index]|Nincs
3.  [Átlag érték]

<h2>Előfeltételek</h2>

  - Számosság nem lehet negatív
  - Egy zeneszám hossza pozitív kell legyen
  - Egy zeneszám hossza kevesebb mindig mint 10 óra :)
