#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(5, 4, 3, 2, A4, A5);


const byte ROWS = 4; //patru randuri
const byte COLS = 4; //patru coloane
char keys[ROWS][COLS] = {		// matricea de caractere pentru caracterele keypadului
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0, A1, 11, 10}; //conectam randurile keypadului la pini
byte colPins[COLS] = {9, 8, 7, 6}; //conectam coloanele keypadului la pini

// declararea keypadului 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int minDigits = 3;		// numarul de cifre cu care se incepe
int score = 0;			// scorul care se va afisa jucatorului
int cifre[8]={};		// vectorul folosit pentru retinerea cifrelor
int wrong = 0, wrong2 = 0;			
int i=0,j=0,k=0;
int level = 1;			// nivelul de inceput

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);   // afiserea mesajelor de inceput pe lcd
  lcd.print("Memory Game");
  lcd.setCursor(0, 1);
  lcd.print("Press * to start");
}
  
void loop(){
  
  char key = keypad.getKey();   
  if (key == '*'){   // start game daca se apasa tasta corespunzatoare caracterului *
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Digit:");   // se afiseaza cifra, scorul si nivelul
    lcd.setCursor(0, 1);
    lcd.print("Score:");
    lcd.print(score);
    lcd.setCursor(9, 1);
    lcd.print("Level:");
    lcd.print(level);
	level = 1;
    wrong2 = 0;
	
    while(level<5){		
		i=0;
    	while(i<minDigits+level){		// la fiecare nivel se incrementeaza numarul de cifre necesare
        	cifre[i]=random(0,10); // se adauga cifre random de la 0 la 10 
        	lcd.setCursor(6, 0);    // se seteaza cursorul la lcd pentru a putea afisa fiecare cifra noua
        	lcd.print(cifre[i]);   // afisarea cifrei
        	j=0;
        	while(j<=i){  // cu j se vor parcurge cifrele din vectorul de cifre
            	char keyNum = keypad.getKey();
            	while(!keyNum){   // se asteapta citirea caracterului din keypad
                	keyNum = keypad.getKey(); 
            	}
            	if(toCifra(keyNum) == cifre[j]){ 
              	// daca caracterul citit din keypad corespunde cu elementul curent din vectorul de cifre
              	// atunci se trece la urmatorul element din vectorul de cifre
                //Serial.println(cifre[j]);
                //Serial.println(keyNum);
                //Serial.println("**");
                	j++;
            	}
            	else{   //daca se greseste, atunci jocul e pierdut
                	wrong = 1;
                	break;
            	}
        	}
        	if (wrong == 0){  // daca nu s-a gresit cifra se continua cu un numar nou
            	score++;
            	lcd.setCursor(6, 1);
            	lcd.print(score);
            	i++;
        	}
        	else if (wrong == 1){ // daca s-a gresit cifra jocul este pierdut 
            	lcd.clear();
            	lcd.print("Wrong digit"); // se printeaza mesaj in cazul in care s-a gresit cifra
            	lcd.setCursor(0, 1);
            	lcd.print("Game over");
            	wrong = 0;		// se reseteaza var wrong
              	wrong2 = 1;
            	delay(1000);
            	lcd.clear();
            	lcd.print("Press * to");  // se printeaza mesaj in cazul in care se doreste reinceperea unui alt joc 
            	lcd.setCursor(0, 1);
            	lcd.print("restart");
            	break;
        	}
    	}
		if (wrong2 == 1){	
			score = 0;
          	wrong2 = 0;
          	level = 1;
			break;
		}
    	if(i==minDigits+level){			// daca s-au tastat toate cifrele nivelului corect, se incremeteaza nivelul, se afiseaza si se trece mai departe
      		level++;		//incrementam nivelul
          	//Serial.println("LEVEL");
            //Serial.println(level);
         	lcd.clear();
          	lcd.setCursor(0, 0);
          	lcd.print("Next level");
          	delay(500);
          	lcd.clear();
    		lcd.setCursor(0, 0);
    		lcd.print("Digit:");   // se afiseaza cifra, scorul si nivelul
    		lcd.setCursor(0, 1);
    		lcd.print("Score:");
    		lcd.print(score);
    		lcd.setCursor(9, 1);
    		lcd.print("Level:");
    		lcd.print(level);
        	wrong = 0;
    	}
  	
    }
   
    if (level == 5){		// daca se ajunge la nivelul 5, jocul este castigat
    	lcd.clear();
        lcd.print("You WIN"); 
      	lcd.setCursor(0, 1);
       	lcd.print("* to restart");
      	level = 1;
      	score = 0;
      	wrong = 0;
      	wrong2 = 0;
      	delay(500);
    }
    
  }
}
int toCifra(char c){    // functie pentru identificarea caracterului si returnarea cifrei corespunzatoare
  if(c=='1')return 1;
  else if(c=='2')return 2;
  else if(c=='3')return 3;
  else if(c=='4')return 4;
  else if(c=='5')return 5;
  else if(c=='6')return 6;
  else if(c=='7')return 7;
  else if(c=='8')return 8;
  else if(c=='9')return 9;
  else if(c=='0')return 0;
  }
  
