  /******************************************************************************************/
  /* Gestion du Jostick
  /*
  /* Direction verticale : Front en positif (flèche)
  /* Direction Horizontale : Left en positif (flèche)
  /* Appui sur Bouton-poussoir : Stop
  /* Joystick = 2 potentiomètres 10 k
  /* 
  /* Affichage de la distance mesurée par le SRF05
  /*
  /* Allumage des feux si lumière insuffisante, mesurée par le TSL257
  /*
  /* Clignotant à droite et à gauche
  /*
  /* S. CRAND - 3 juillet 2012
  /* Révision - 28 mai 2025 
  /* Statut : OK
  /******************************************************************************************/

  /************************************************************* 
   BALISE BEGIN
   pixel == 17
  
   TELEMETER
   pixel == distance
   
   LIGHT SENSOR
   pixel == 1 -> light
   pixel == 0 -> no light

   JOYSTICK
   pixel == 1 -> Front
   pixel == 2 -> Back 
   pixel == 3 -> Right 
   pixel == 4 -> Left 
   pixel == 11 -> front_left_blink
   pixel == 12 -> front_right_blink
   pixel == 13 -> "back_left_blink
   pixel == 14 -> back_right_blink 
   pixel == 15 -> left_front_blink 
   pixel == 16 -> left_back_blink 
   pixel == 17 -> right_front_blink 
   pixel == 18 -> right_back_blink 
   pixel == 5 -> STOP 
  
   BALISE END  
   pixel == 17  
  *************************************************************/
 
 

 
 // Setup pins and variables for Joystick
const int BP = A3;       // pin ADC3
const int X  = A4;       // pin ADC5
const int Y  = A5;       // pin ADC5

int posY = 0;                  // X
int posX = 0;                  // Y
int posBp = 0;                 // BP

int directionPrec = 1; // Direction initiale = front

 // Setup pins and variables for light sensor
const int LUM = A0;        // pin ADC0
int dataTsl257 = 0;      

 // Setup pins and variables for telemeter
const int echo    = 4;	// pin 4                       
const int trigger = 3;	// pin 3 


int pixel;
 
const int numOfReadings = 10;     // nombre de mesures de la distance
int distance;         


 void setup() {  
  pinMode(trigger, OUTPUT);                     
  pinMode(echo, INPUT); 

  Serial.begin(9600);
 }


 void loop() {
   

  distance =  distance_measurement(numOfReadings); // measurement of the distance
 
  posY = analogRead(Y);    	  
  posX = analogRead(X);  
  posBp = analogRead(BP);
  dataTsl257 = analogRead(LUM); // Interrogation du light sensor
  
  pixel = 35;
  Serial.println(pixel, DEC);
  
  pixel = distance;          
  Serial.println(pixel, DEC);
  
  if (dataTsl257 < 300 ) pixel = 1; // Light si dataTsl257 < 700 (mode nuit)
  else pixel = 0;                   // no Light sinon
  Serial.println(pixel, DEC);
  
  if (posBp < 5) pixel = 5; // BP appuyé
  else pixel = direction(posY, posX, directionPrec);
  Serial.println(pixel);
  
  switch (pixel) {
  case 1 : directionPrec=1; break;
  case 2 : directionPrec=2; break;
  case 3 : directionPrec=3; break;
  case 4 : directionPrec=4; break;

  case 11 : directionPrec=4; break;
  case 12 : directionPrec=3; break;
  case 13 : directionPrec=4; break;
  case 14 : directionPrec=3; break;

  case 15 : directionPrec=1; break;
  case 16 : directionPrec=2; break;
  case 17 : directionPrec=1; break;
  case 18 : directionPrec=2; break;
  }
  
  pixel = 36;
  Serial.println(pixel);
}

/*******************************************************************************/
/*  Fonction pour récupérer les informations du Joystick                       */
/*******************************************************************************/

int direction(int fbData, int rlData, int dataPrec) {
   // 1 = front, 2 = back, 3 = left, 4 = right
   int fbResult;
   int fbFinal;
   
   if (fbData < 400) {
    fbResult = 2;} // Back 
   else {
		if (fbData > 620) {
			fbResult = 1;}
		else {
			if (rlData < 400) {
				fbResult = 4; }
			else {
				if (rlData > 620) 
					fbResult = 3;
				else fbResult = 5;
         }
       }          
    }
   
   switch(fbResult) {
     case 1 :
       if ((dataPrec == 1) or (dataPrec == 2)) {fbFinal = 1; } // front
       if (dataPrec == 3) {fbFinal = 15; } // left_front_blink
       if (dataPrec == 4) {fbFinal = 17; } // right_front_blink
       break;
    case 2 :
       if ((dataPrec == 2) or (dataPrec == 1)) {fbFinal = 2; }  // back
       if (dataPrec == 3) {fbFinal = 16; } // left_back_blink
       if (dataPrec == 4) {fbFinal = 18; } // right_back_blink
       break;
    case 3 :
       if ((dataPrec == 4) or (dataPrec == 3)) {fbFinal = 3; } // left 
       if (dataPrec == 2) {fbFinal = 13; } // back_left_blink
       if (dataPrec == 1) {fbFinal = 11; } // front_left_blink
       break;   
    case 4 :
       if ((dataPrec == 3) or (dataPrec == 4)) {fbFinal = 4; } // right
       if (dataPrec == 1) {fbFinal = 12; } // front_right_blink
       if (dataPrec == 2) {fbFinal = 14; } // back_right_blink
       break;
    case 5 :
       fbFinal = dataPrec;  
       break;
   }
   
  return (fbFinal); 
  }

/*******************************************************************************/
/*  Fonction pour piloter le SRF05 - Capteur à Ultrasons                       */
/*******************************************************************************/

int distance_measurement(int numOfReadings) {
  int total = 0;
  int averagedistance = 0;    
  int pulseTime = 0;                   
  
  for (int i = 1; i <= numOfReadings; i++) {  //Moyenne sur numOfReadings mesures
    digitalWrite(trigger, HIGH);                    
    delayMicroseconds(10);                         
    digitalWrite(trigger, LOW);
  
    pulseTime = pulseIn(echo, HIGH);             
    distance = pulseTime/58;                        // distance en cm.
    total = total + distance;
    
    delay(100);
    
    }
    averagedistance = total / numOfReadings;    
    return(averagedistance);
}
