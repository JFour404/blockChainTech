# Universiteto praktiniai darbai
---
## v0.1 - Hash generatoriaus kūrimas

**Hash funkcijos pseodo kodas.**

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
