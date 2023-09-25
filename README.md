# Universiteto praktiniai darbai
---
## v0.1 - Hash generatoriaus kūrimas

**Hash funkcijos pseudo kodas.**

Read text

Create `default_hash`
- Read euler's number 256 digits
- Create vector for Bit values
- Repeat 256:
    - If digit is >= 5
        - Bit = 1
    - else
        - Bit = 0
- `Hash` = `default_hash`

Check `text size`

Create `unique_num` (0, 255) for every char
- `unique_num` = random number gen (seed - `text size`)

For each char:
- char -> `int value`
- `int value` -> 256 bits hash
    - `new_hash` = random number gen (seed - `int value`)
- shift_right `new_hash` by `unique_num`
- `Hash` = `Hash` + `new_hash`

Convert Hash (bits) to hex Hash

## Eksperimentinis tyrimas ir rezultatų analizė

**1 TESTAVIMO FAZĖ**

Naudojant išanksto sukurtus failus, tikrinama, kad:
- Maišos funkcijos įėjimas gali būti bet kokio dydžio simbolių eilutė
- Maišos funkcijos išėjimas visuomet yra to paties, fiksuoto dydžio rezultatas (64 hex)
- Maišos funkcija yra deterministinė


*1 FAZĖS TESTAVIMO REZULTATAI.*
| Input | Hex size | Hash |
| ----- | -------- | ---- |
| onlyA.txt | 64 |5032392abe7615bbe87a40d74b8f8f7352dea78d1281b0775c883bea2ca3c728 |
| onlyA.txt | 64 |5032392abe7615bbe87a40d74b8f8f7352dea78d1281b0775c883bea2ca3c728 |
| onlyB.txt | 64 |aed10aa29b99d95f2d027bb542bb449a184aa9307eadb4a6ae9c957ec986d769 |
| onlyB.txt | 64 |aed10aa29b99d95f2d027bb542bb449a184aa9307eadb4a6ae9c957ec986d769 |
| 2kRndA.txt | 64 |19cd7eb1e4f430d49dd60467262e032e68ba3a2b979224c57e05f43157ee3403 |
| 2kRndA.txt | 64 |19cd7eb1e4f430d49dd60467262e032e68ba3a2b979224c57e05f43157ee3403 |
| 2kRndB.txt | 64 |f9dbddf7629e8dacf4ceba00ea7c623e9e17296c218d1c170d725726572a3985 |
| 2kRndB.txt | 64 |f9dbddf7629e8dacf4ceba00ea7c623e9e17296c218d1c170d725726572a3985 |
| 1kS_diff1.txt | 64 |ee7520922cf79984ef27be2cfa2b6ae02fc8fcc527408a5ed77cb325421a535e |
| 1kS_diff1.txt | 64 |ee7520922cf79984ef27be2cfa2b6ae02fc8fcc527408a5ed77cb325421a535e |
| 1kS_diff2.txt | 64 |e691a0c31cef7cfbbe9547e209cc5f83c90fb2d23f5d29486b4bfeae41bb1cfa |
| 1kS_diff2.txt | 64 |e691a0c31cef7cfbbe9547e209cc5f83c90fb2d23f5d29486b4bfeae41bb1cfa |


*TESTINIŲ FAILŲ PAAIŠKINIMAS*
| Failas | Tekstas |
| ------ | ------- |
| onlyA.txt | vienas simbolis (a) |
| onlyB.txt | vienas simbolis (b) |
| 2kRndA.txt | 2 tūkst. atsitiktinai sugeneruotų simbolių |
| 2kRndB.txt | 2 tūkst. atsitiktinai sugeneruotų simbolių |
| 1kS_diff1.txt | 1 tūkst. atsitiktinai sugeneruotų simbolių |
| 1kS_diff2.txt | 1kS_diff1.txt kopija, kurioje pakeistas 500 - nis simbolis |

**2 TESTAVIMO FAZĖ**

Tikrinama ar maišos funkcijos reikšmė/kodas bet kokiai input'o reikšmei yra apskaičiuojamas greitai - efektyviai.

Hash'avimo tekstas buvo imamamas iš konstitucija.txt, su kiekviena iteracija dvigubinant nuskaitytų eilučių kiekį.

*2 FAZĖS TESTAVIMO REZULTATAI.*
| Input size | Hashing time | Increase in time |
| ---------- | ------------ | ---------------- |
| 1 | 0.000437 | Nan |
| 2 | 0.000650 | 48.63 % |
| 4 | 0.001048 | 61.23 % |
| 8 | 0.001855 | 77.08 % |
| 16 | 0.005265 | 183.83 % |
| 32 | 0.009234 | 75.39 % |
| 64 | 0.018678 | 102.27 % |
| 128 | 0.046393 | 148.38 % |
| 256 | 0.104427 | 125.09 % |
| 512 | 0.276475 | 164.75 % |

<img width="481" alt="image" src="https://github.com/JFour404/blockChainTech/assets/116594512/d069c78a-998d-44e3-880b-11b51e71148d">

Pagal gautus duomenis sunku tiksliai nustatyti, kokio sudėtingumo yra šis algoritmas, tačiau laikas nekyla eksponentiškai, taigi tinka didelės apimties failams.

**3 TESTAVIMO FAZĖ**

Tikrinama ar maišos funkcija yra atspari kolizijai. Patikrinus 200 tūkst. sugeneruotų hash'ų nebuvo rasta nei vieno pasikartojančio hash'o.

**4 TESTAVIMO FAZĖ**

Tikrinamas lavinos efektas, hash'uojant dvi labai panašias įvestis.

*4 FAZĖS TESTAVIMO REZULTATAI.*
| Matavimas | Bit hash | Hex hash |
| --------- | -------- | -------- |
| Min | 41.80 % | 0.00 % |
| Max | 58.98 % | 17.19 % |
| Avg | 49.80 % | 6.14 % |
