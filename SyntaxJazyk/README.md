# Nauč sa programovať v SynJaze! ⚡

## Ak 🤔
Zisti, či je niečo pravda alebo lož. Pravdivosť musí byť vo forme premennej!
```
ak [pravidvost]
[...prikazy]
koniec
```
> **Poznámka:** Pravdivosť musí byť vo forme premennej!

## Výstup 📃

### Vytlač 🖨️
Zobraz ľubovoľný text v terminále.
```
vytlac [...text]
```
alebo iba
```
vytlac
```

### Prečítaj 🔍
Zobraz obsah premennej v terminále. Môžeš špecifikovať jednu alebo viac premenných rôzneho typu.
```
precitaj [...nazov premennej]
```

### Vyčisti 🧼
Zmaž všetok text zobrazený v okne terminálu.
```
vycisti
```

### Farba 🎨
Zmeň farbu textu.
```
farba [nazov farby]
```
Dostupné farby:
`cierna`, `cervena`, `zelena`, `zlta`, `modra`, `ruzova`, `tyrkysova`, `biela`

## Vstup ⌨️

### Získaj 📥
Získaj vstup od používateľa a ulož ho do premennej. Vždy vráti reťazec.
```
ziskaj [nazov premennej] = [...informacia pre pouzivatela ako text]
```
alebo iba
```
ziskaj
```
na pozastavenie exekúcie.
> **Poznámka:** Informácia pre používateľa sa zobrazí pred vstupom.

## Premenné 📦

### Reťazec 💬
Akýkoľvek súbor znakov. Nepodporuje matematické operácie. Kus textu.
```
retazec [nazov premennej] = [...hodnota vo forme textu]
```

### Číslo 🔢
Číselná hodnota (zatiaľ) bez desatinnej čiarky. Podporuje matematické operácie.
```
cislo [nazov premennej] = [hodnota vo forme cisla]
```

### Pravdivosť 🎺
Môže mať iba dve hodnoty: pravda a lož.
```
pravdivost [nazov premennej] = [pravda | loz]
```
dokáže porovnať dve premenné rovnakého typu:
```
pravdivost [nazov premennej] = [premenna 1] [operator] [premenna 2]
```
> **Poznámka:** Operátor je napríklad `==` alebo `!=`.

## Navigácia 🚀

### Označ 🏷️
Označí miesto, na ktoré sa neskôr môže vrátiť.
```
oznac [nazov oznacenia]
```

### Preskoč 🏃
Preskočí na predom označené miesto.
```
preskoc [nazov oznacenia]
```
> **Poznámka:** Spravidla musí označenie byť *pred* preskočením.
