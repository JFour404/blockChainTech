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
| empty.txt | 64 |555929a59f2bfdfb1c5764eb2d40e51e8d035e506c585ecd11a3913333a32e94 |
| empty.txt | 64 |555929a59f2bfdfb1c5764eb2d40e51e8d035e506c585ecd11a3913333a32e94 |


*TESTINIŲ FAILŲ PAAIŠKINIMAS*
| Failas | Tekstas |
| ------ | ------- |
| onlyA.txt | vienas simbolis (a) |
| onlyB.txt | vienas simbolis (b) |
| 2kRndA.txt | 2 tūkst. atsitiktinai sugeneruotų simbolių |
| 2kRndB.txt | 2 tūkst. atsitiktinai sugeneruotų simbolių |
| 1kS_diff1.txt | 1 tūkst. atsitiktinai sugeneruotų simbolių |
| 1kS_diff2.txt | 1kS_diff1.txt kopija, kurioje pakeistas 500 - nis simbolis |

_______________

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

______________________

**3 TESTAVIMO FAZĖ**

Tikrinama ar maišos funkcija yra atspari kolizijai. Patikrinus 200 tūkst. sugeneruotų hash'ų nebuvo rasta nei vieno pasikartojančio hash'o.

_______________________

**4 TESTAVIMO FAZĖ**

Tikrinamas lavinos efektas, hash'uojant dvi labai panašias įvestis.

*4 FAZĖS TESTAVIMO REZULTATAI.*
| Matavimas | Bit hash | Hex hash |
| --------- | -------- | -------- |
| Min | 41.80 % | 0.00 % |
| Max | 58.98 % | 17.19 % |
| Avg | 49.80 % | 6.14 % |

__________________

**TESTAVIMŲ IŠVADOS**

Atlikus testavimus buvo pastebėta, kad algoritmas puikiai įgyvendina lavinos efektą, geba sugeneruoti labai skirtingus ir nepasikartojančius hash'us. Veikimo laikas su didesniais input'ais išsitęsia, reikėtų padirbėti ties optimizavimu.

___________________

**hashF palyginimas su SHA256**

Testavimams buvo naudojama Lietuvos Respublikos Konstitucija, kiekvieną kartą vis didinant įvesties dydį. Pradedant nuo mažesnės apimties įvesties, greitaveikos skirtumas jau buvo didžiulis ir siekė 1:230. Didinant įvestį skirtumas didėjo eksponentiškai ir pasiekus 512 eilučių apimtį, hashF buvo lėtesnis 11 tūkst. kartų.

*SHA256 ir hashF vykdymo laiko palyginimas.*
| Input size | Hashing time (SHA256) | Hashing time (hashF) | hashF performace (kiek kartu leciau)|
| ---------- | --------------------- | -------------------- | ----------------------------------- |
| 1 | 0.00000216 | 0.00050388 | 233.28 |
| 2 | 0.00000064 | 0.00066918 | 1045.59 |
| 4 | 0.00000064 | 0.00108578 | 1696.53 |
| 8 | 0.00000106 | 0.00230482 | 2174.36 |
| 16 | 0.00000132 | 0.00636616 | 4822.85 |
| 32 | 0.00000142 | 0.01024344 | 7213.69 |
| 64 | 0.00000242 | 0.01866218 | 7711.64 |
| 128 | 0.00000568 | 0.04628452 | 8148.68 |
| 256 | 0.00001036 | 0.11308824 | 10915.85 |
| 512 | 0.00002334 | 0.26221422 | 11234.54 |

__________________________

Dar vienas testas buvo atliktas norint patikrinti kaip algoritmai sugeba parinkti atsitiktinius bit'us, t.y. ar algoritmas nenaudoja kažkurių bit'ų dažniau nei kitų. Buvo naudojama 200 tūkst. hash'ų.

*SHA256 ir hashF simboliu pasiskirstymas (ideal 6.25 %)*
 | Hex | SHA256 | hashF | Best result | 
 | -------- | ------ | ----- | ----------- | 
 | 0 | 6.257 % | 6.239 % |  hashF | 
 | 1 | 6.264 % | 6.268 % |  SHA256 | 
 | 2 | 6.261 % | 6.246 % |  hashF | 
 | 3 | 6.239 % | 6.262 % |  SHA256 | 
 | 4 | 6.273 % | 6.228 % |  hashF | 
 | 5 | 6.247 % | 6.248 % |  SHA256 | 
 | 6 | 6.217 % | 6.242 % |  SHA256 | 
 | 7 | 6.243 % | 6.256 % |  SHA256 | 
 | 8 | 6.260 % | 6.252 % |  hashF | 
 | 9 | 6.243 % | 6.255 % |  SHA256 | 
 | a | 6.261 % | 6.250 % |  hashF | 
 | b | 6.242 % | 6.231 % |  hashF | 
 | c | 6.248 % | 6.282 % |  SHA256 | 
 | d | 6.242 % | 6.242 % |  hashF | 
 | e | 6.259 % | 6.257 % |  hashF | 
 | f | 6.244 % | 6.242 % |  hashF | 

Pagal atliktą testą galime teigti, kad hashF nenusileidžia atsitiktinių bit'ų parinkimui.

_______________________

**hiding ir puzzle-friendliness**

hashF algoritmas puikiai veikia, jei išorė nežino įvesties dydžio, nes tuomet kiekvienas simbolis turi 256 skirtingas variacijas po 256 bit'us, taigi yra apie 16 tūkst. ((26 raidės + 26 didžiosios raidės + 10 skaitmenų) * 256 galimų variacijų) galimų variantų vienam simboliui. Taigi tiesiog būtų paprasčiau naudoti brute force metodą ir tikrinti skirtingas įvestis.

Taip pat, kai yra pakeičiamas tik vienas simbolis, keičiasi kiekvieno simbolio sukurti 256 bit'ai, todėl yra itin sunku pasakyti, koks simbolis į kurį buvo pakeistas.
________________________



