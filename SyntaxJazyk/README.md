# SyntaxJazyk

## Pokiaľ 🤔
Zisti, či je niečo pravda alebo lož. Pravdivosť musí byť vo forme premennej!
```
pokial [pravidvost]
[...prikazy]
koniec
```
> **Tip:** Nepomýľ si tento príkaz s "ak".

## Vytlač 📃
Zobraz svoj text v terminále! Môžeš špecifikovať jednu alebo viac premenných rôzneho typu.
```
vytlac [...premenna]
```

## Premenné 📦

### Prečítaj 📥
Získaj vstup od používateľa na základe nejakej správy. Vždy vráti reťazec.
```
precitaj [nazov premennej] = [informacia pre pouzivatela]
```
alebo
```
precitaj
```

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
