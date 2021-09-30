# HashGenerator  
  
## Versija 1  
Sukurtos įvesties funkcijos. Galima įvesti duomenis dvejais būdais: ranka per komandinę eilutę arba duomenis paimti iš .txt failo.
  
## Versija 2  
Pirmas bandymas hash funkcijos. Kolkas ji tik užkoduoja kiekvieną žodžio raidę ir išveda hexadecimal išraiška.   
Liko padaryti: kad visada būtų 64 bitų išraiška ir veiktų funkcija ir su didžiosimis raidėmis, bei jeigu įvestis yra tuščia.  
  
## Versija 3  
Hash funkcija sukurta.  
### Hash funkcijos idėja:  
1. Kiekvienam input simboliui (raidei) priskiriama tam tikra reikšmė.  
2. Atliekami matematiniai veiksmai su tomis reikšmėmis: daugyba, sudėtis.  
3. Tuomet po kiekvienos reikšmės pridedama tam tikra raidė. (Į output string eina int reikšmė + atrinkta raidė)  
Užtikrinimas, kad išeiga visada 64 simbolių:  
1. Jeigu žodis susidaro iš daugiau nei 6 simbolių - imama išviso 6 simboliai, kas treti iš input'o.  
2. Jeigu po formulių output yra mažiau nei 64 simboliai - pridedamos papildomos reikšmės pagal formulę, iki kol pasiekiamas 64 simbolių išvestis.  
3. Jeigu po formulių output yra daugiau nei 64 simbolių - atimami simboliai nuo galo po vieną, iki kol pasiekiamas 64 simbolių išvestis.  
Beje kadangi naudojamas long int kaip kintamasis, kuriame vis saugomos užkoduotų raidžių reikšmės, pagrindinėje formulėje yra įdėtas fail safe, kuris neigiamą reikšmę paverčia teigiama. Taip gali nutikti tada, kai gaunama per didelė reikšmė. Pvz.: simbolių input'e yra 999 ir dauginama iš tam tikrai raidei priskirtos reikšmės, gaunama per didelė reikšmė long int'ui, todėl long int grąžintų neigiamą reikšmę. Tuomet formulė dėl fail safe grąžina teigiamą reikšmę ir taip užtikrinama, kad išeiga būtų tik skaičiai ir raidės.
