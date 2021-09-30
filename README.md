# HashGenerator  
  
## Versija 1  
Sukurtos įvesties funkcijos. Galima įvesti duomenis dvejais būdais: ranka per komandinę eilutę arba duomenis paimti iš .txt failo.
  
## Versija 2  
Pirmas bandymas hash funkcijos. Kolkas ji tik užkoduoja kiekvieną žodžio raidę ir išveda hexadecimal išraiška.   
Liko padaryti: kad visada būtų 64 bitų išraiška ir veiktų funkcija ir su didžiosimis raidėmis, bei jeigu įvestis yra tuščia.  
  
## Versija 3  
Hash funkcija sukurta.  
### Hash funkcijos idėja:  
1. Kiekvienam įeigos simboliui (raidei) priskiriama tam tikra reikšmė.  
2. Atliekami matematiniai veiksmai su tomis reikšmėmis: daugyba, sudėtis.  
3. Tuomet po kiekvienos reikšmės pridedama tam tikra raidė. (Į išeigos string'ą eina integer reikšmė + atrinkta raidė)  
#### Užtikrinimas, kad išeiga visada 64 simbolių:  
1. Jeigu žodis susidaro iš daugiau nei 6 simbolių - imama išviso 6 simboliai, kas treti iš įeigos.  
2. Jeigu po formulių išeiga yra mažiau nei 64 simbolių - pridedamos papildomos reikšmės pagal formulę, iki kol pasiekiama 64 simbolių išvestis.  
3. Jeigu po formulių išeiga yra daugiau nei 64 simbolių - atimami simboliai nuo galo po vieną, iki kol pasiekiama 64 simbolių išvestis.  
  
Beje kadangi naudojamas long int kaip kintamasis, kuriame vis saugomos užkoduotų raidžių reikšmės, pagrindinėje formulėje yra įdėtas fail safe, kuris neigiamą reikšmę paverčia teigiama (per didelę reikšmę gavęs integer grąžins "undefined value"). Taip gali nutikti tada, kai gaunama per didelė reikšmė. Pvz.: simbolių įeigoje yra 999  ir dauginama iš tam tikrai raidei priskirtos reikšmės, gaunama per didelė reikšmė long int'ui, todėl long int grąžintų neigiamą reikšmę (undefined value). Tuomet formulė dėl fail safe grąžina teigiamą reikšmę ir taip yra užtikrinama, kad išeiga būtų tik skaičiai ir raidės (be simbolių kaip "-").  
## Eksperimentinis tyrimas/ analizė  
  
#### 2 failai sudaryti tik iš vieno simbolio  
![image](https://user-images.githubusercontent.com/79039786/135499373-55c6bcd0-879b-4ab6-bad2-cb8c935f5165.png)    
#### 2 failai sudaryti iš daugiau nei tūkstančio simbolių:
![image](https://user-images.githubusercontent.com/79039786/135495564-d4b465b7-f2c6-4112-9403-4140f549fd0a.png)   
#### 2 failai sudaryti iš daugiau nei tūkstančio simbolių, bei skiriasi tik vienu simboliu:  
![image](https://user-images.githubusercontent.com/79039786/135495778-b1db23dc-ce46-4b05-9b6b-5b0a1a39a4ac.png)  
#### Tuščias failas:  
Naudotas failas - empty.txt  
output: 0262002628040880404606446588040886200941026200262901026200262804  
#### Įrodymas, kad tai pačiai įeigai gaunama ta pati išeiga:  
![image](https://user-images.githubusercontent.com/79039786/135496827-59a24594-8f53-49e3-99f6-33b704782fb5.png)  
#### Tikrinamas atsparumas kolizijai  
Sugeneruota 10000 failų su 10, 100, 500, 1000 simbolių.  
Kai simbolių 10 pasikartojo 5 kartus. (poros1.txt)    
Kai simbolių 100 pasikartojo 9814 kartų. (poros100.txt)    
Kai simbolių 500 pasikartojo 9414 kartų. (poros500.txt)    
Kai simbolių 1000 pasikartojo 9325 kartus. (poros1000.txt)    
#### Efektyvumo tyrimas   
konstitucija.txt užkoduoti užtruko 664 ms.    
#### Hash'ų procentinio skirtingumo tyrimas   
Atliekamas tyrimas buvo su failu panasu.txt. Jame yra 26 stringai, kurie skiriasi vienu simboliu. Visi hash'ai skiriasi tik 10 simbolių iš 64.  
Skirtingumo procentas: 15%.





