# Memory Game 
#
#
![2021-01-10 12_17_21-Memory Game _ Tinkercad.png](https://www.dropbox.com/s/ngni5n5w163kfg4/2021-01-10%2012_17_21-Memory%20Game%20_%20Tinkercad.png?dl=0&raw=1)

Memory game este un joc simplu prin care se pot testa capacitatile de memorare. 
Scopul jocului este de a atinge nivelul maxim ( nivelul maxim setat este 8) prin memorarea cifrelor date si tastarea acestora folosind keypadul. 
#
#
 ![2021-01-10 14_46_04-Circuit design Copy of Print 4x4 Keypad Input to LCD _ Tinkercad.png](https://www.dropbox.com/s/2m3i6bljbvxxtwf/2021-01-10%2014_46_04-Circuit%20design%20Copy%20of%20Print%204x4%20Keypad%20Input%20to%20LCD%20_%20Tinkercad.png?dl=0&raw=1)
#### Reguli ale jocului:    
  - Cifrele se tasteaza pe rand in ordinea in care au fost afisate pe LCD
  - Se va afisa cate o noua cifra dupa fiecare tastare corecta
  - Fiecare nivel are un anumit numar de cifre, care trebuie retinute si tastate
  - Daca s-au retinut si tastat corect toate cifrele corespunzatoare nivelului, se trece la nivelul urmator
  - Numarul de cifre care trebuie retinute creste odata cu inaintarea nivelul

Rezolvarea ultimului nivel va duce la castigarea jocului, cu posibilitatea de a incepe iar jocul:

![WIN.png](https://www.dropbox.com/s/bjz0aygthmruu3n/WIN.png?dl=0&raw=1)

#### Componente folosite pentru implementare:   

![2021-01-10 21_36_47-Circuit design Terrific Waasa _ Tinkercad.png](https://www.dropbox.com/s/aq2lwvbert9hr2o/2021-01-10%2021_36_47-Circuit%20design%20Terrific%20Waasa%20_%20Tinkercad.png?dl=0&raw=1)
#
##### Arduino UNO R3
#
Placuta folosita este Arduino UNO R3 gasita in programul Tinkercad pentru circuite.
Arduino Uno este o placă de microcontroler open-source bazată pe microcontroller-ul Microchip ATmega328P și dezvoltată de Arduino cc.


![2021-01-10 21_52_10-Circuit design Terrific Waasa _ Tinkercad.png](https://www.dropbox.com/s/46p0b2tdbu2fqns/2021-01-10%2021_52_10-Circuit%20design%20Terrific%20Waasa%20_%20Tinkercad.png?dl=0&raw=1)
#
##### Small breadboard
#
Placă de prototipizare disponibila in mai multe variante in programul Tinkercad.


![2021-01-10 22_11_11-Circuit design Terrific Waasa _ Tinkercad.png](https://www.dropbox.com/s/zcdr4k86sxosn2j/2021-01-10%2022_11_11-Circuit%20design%20Terrific%20Waasa%20_%20Tinkercad.png?dl=0&raw=1)
##### LCD 16 x 2
#
Shield-ul LCD care conține un afișor cu cristale lichide și un potențiometru pentru reglarea intensității luminii.
Initializarea lcd-ul la valorile stabilite ale pinilor.
![2021-01-10 22_41_51-Circuit design MemoryGame _ Tinkercad.png](https://www.dropbox.com/s/da2h7yw3iousu7a/2021-01-10%2022_41_51-Circuit%20design%20MemoryGame%20_%20Tinkercad.png?dl=0&raw=1)
#
Afisarea de mesaje pe LCD
![2021-01-10 22_42_20-Circuit design MemoryGame _ Tinkercad.png](https://www.dropbox.com/s/njxnl126cu8olet/2021-01-10%2022_42_20-Circuit%20design%20MemoryGame%20_%20Tinkercad.png?dl=0&raw=1)
#
![2021-01-10 22_20_06-Circuit design Terrific Waasa _ Tinkercad.png](https://www.dropbox.com/s/fzbj4pz1o2zfbmi/2021-01-10%2022_20_06-Circuit%20design%20Terrific%20Waasa%20_%20Tinkercad.png?dl=0&raw=1)
#
##### Keypad 4 x 4
#
Acest keypad matrice 4x4 are 16 butoane conectate la randuri si coloane. Cu ajutorul placutei Arduino, se pot scana starea acestor butoane, daca sunt apasate sau nu.
Keypadul se poate folosi dupa declararea acestuia:![2021-01-10 22_31_34-Circuit design MemoryGame _ Tinkercad.png](https://www.dropbox.com/s/6srq4eq5jwlmg5t/2021-01-10%2022_31_34-Circuit%20design%20MemoryGame%20_%20Tinkercad.png?dl=0&raw=1)
#
Se seteaza caractere folosite pentru keypad, pinii la care sunt conectate randurile si coloanele si numarul de coloane/randuri.  

##### Montaj

![2021-01-10 22_51_49-Circuit design MemoryGame _ Tinkercad.png](https://www.dropbox.com/s/ac7is7wnsnxi61q/2021-01-10%2022_51_49-Circuit%20design%20MemoryGame%20_%20Tinkercad.png?dl=0&raw=1)


