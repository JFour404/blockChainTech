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


>*1 FAZĖS TESTAVIMO REZULTATAI.*
| Input | Hexabits | Hash |
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


>*TESTINIŲ FAILŲ PAAIŠKINIMAS*
| Failas | Tekstas |
| ------ | ------- |
| onlyA.txt | vienas simbolis (a) |
| onlyB.txt | vienas simbolis (b) |
| 2kRndA.txt | 2 tūkst. atsitiktinai sugeneruotų simbolių |
| 2kRndB.txt | 2 tūkst. atsitiktinai sugeneruotų simbolių |
| 1kS_diff1.txt | 1 tūkst. atsitiktinai sugeneruotų simbolių |
| 1kS_diff2.txt | 1kS_diff1.txt kopija, kurioje pakeistas 500 - nis simbolis |

**2 TESTAVIMO FAZĖ**
