# ObjektinisProgramavimas v1.0

Programa skirta skaičiuoti galutinį balą pagal įvestus duomenis.

Programa pakeista pagal programavimo standartus. Sudarytas daugiafailis projektas, patobulintas algoritmas randantis klaidas.

Programa naudoja kelis konteinerių tipus apskaičiuoti veikimo spartą su skirtingais duomenų tipais.

## Testavimo sistemos parametrai

- **CPU**: Intel(R) Celeron(R) P4500 1.87GHz 
- **RAM**: DDR3 3GB 667MHz
- **HDD**: HDD (Magnetinis) 120GB

## Programos testavimo laikai (5 kartų vidurkis)

#### Vector
|  |Failo skaitymo greitis| Studentu rūšiavimo laikas | Studentų paskirstymo laikas | Visas veikimo laikas |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 20 ms | 0 ms | 0 ms | 50 ms |
| studentai10000 | 110 ms | 30 ms | 0 ms | 190 ms |
| studentai100000 | 1064 ms | 432 ms | 40 ms | 2236 ms |
| studentai1000000 | 10889 ms | 5516 ms | 432 ms | 21202 ms |
| studentai10000000 | 162431 ms | 72118 ms | 13353 ms | 320132 ms |

#### List
|  |Failo skaitymo greitis| Studentu rūšiavimo laikas | Studentų paskirstymo laikas | Visas veikimo laikas |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 10 ms | 0 ms | 0 ms | 40 ms |
| studentai10000 | 100 ms | 20 ms | 0 ms | 170 ms |
| studentai100000 | 1074 ms | 182 ms | 42 ms | 1769 ms |
| studentai1000000 | 10553 ms | 2468 ms | 375 ms | 18227 ms |
| studentai10000000 | 130665 ms | 35536 ms | 3900 ms | 224437 ms |

#### Deque
|  |Failo skaitymo greitis| Studentu rūšiavimo laikas | Studentų paskirstymo laikas | Visas veikimo laikas |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 18 ms | 3 ms | 1 ms | 32 ms |
| studentai10000 | 100 ms | 40 ms | 2 ms | 190 ms |
| studentai100000 | 1046 ms | 530 ms | 45 ms | 2062 ms |
| studentai1000000 | 10344 ms | 6709 ms | 496 ms | 22012 ms |
| studentai10000000 | 118809 ms | 83116 ms | 8002 ms | 293108 ms |

## Skirstymo strategijų testavimo laikai (5 kartų vidurkis)

#### Vector
|  | Strategija 1 | Strategija 2 | Strategija 3 | Originali strategija |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 0 ms | 0 ms | 0 ms | 0 ms |
| studentai10000 | 10 ms | 0 ms | 0 ms | 190 ms |
| studentai100000 | 60 ms | 50 ms | 40 ms | 0 ms |
| studentai1000000 | 674 ms | 456 ms | 432 ms | 34 ms |

#### List
|  | Strategija 1 | Strategija 2 | Strategija 3 | Originali strategija |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 0 ms | 0 ms | 0 ms | 0 ms |
| studentai10000 | 10 ms | 0 ms | 0 ms | 0 ms |
| studentai100000 | 142 ms | 110 ms | 42 ms | 10 ms |
| studentai1000000 | 1498 ms | 1188 ms | 375 ms | 142 ms |

#### Deque
|  | Strategija 1 | Strategija 2 | Strategija 3 | Originali strategija |
| :--- | ---- | ---- | ---- | ---- |
| studentai1000 | 0 ms | 0 ms | 0 ms | 0 ms |
| studentai10000 | 10 ms | 0 ms | 0 ms | 10 ms |
| studentai100000 | 70 ms | 50 ms | 45 ms | 10 ms |
| studentai1000000 | 663 ms | 493 ms | 496 ms | 68 ms |

## Funkcionalumas

- Įvedimo langas, kuriame vartotojas įveda studento vardą, pavardę, namų darbų pažymius ir egzamino rezultatą.
- Galutinio balo skaičiavimas pagal vidurkį ar medianą.
- Išvedimo langas, kuriame pateikiami studentų galutiniai balai.

## Kaip naudotis

1. Paleisti programą.
2. Sekti ekrane esamus nurodymus.
3. Gauti studentų galutinius balus.
