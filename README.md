# HashGenerator  
  
### Versija 1  
Sukurtos įvesties funkcijos. Galima įvesti duomenis dvejais būdais: ranka per komandinę eilutę arba duomenis paimti iš .txt failo.
  
### Versija 2  
Pirmas bandymas hash funkcijos. Kolkas ji tik užkoduoja kiekvieną žodžio raidę ir išveda hexadecimal išraiška.   
Liko padaryti: kad visada būtų 64 bitų išraiška ir veiktų funkcija ir su didžiosimis raidėmis, bei jeigu įvestis yra tuščia.  
  
### Versija 3  
Hash funkcija pabaigta.  
Hash funkcijos idėja:  
Mano hash funkcija pirmiausiai priskiria kiekvienam simboliui (raidei) tam tikrą reikšmę, tuomet atlieka matematinius veiksmus su tomis reikšmėmis.  
Tuomet, pridedama atitinkama raidė. Tuomet yra tikrinimai, kad išvestis visada būtų 64 simbolių:  
Jeigu mažiau nei 64 simboliai, tuomet pridedami dar simboliai, kurie taip pat apskaičiuojami.  
Jeigu daugiau nei 64 simboliai, tuomet atimati nuo galo po vieną. Taip nutikti turėtų itin retai, nes hash funkcijos pradžioje, jeigu žodis susidaro iš daugiau nei 6 raidžių, bus koduojamos tik kas trečia žodžio raidė.
