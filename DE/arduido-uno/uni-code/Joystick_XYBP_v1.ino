const int BP = A3;       // pin ADC3
const int X  = A4;       // pin ADC4
const int Y  = A5;       // pin ADC5
                 
void setup() 
{
  Serial.begin(9600);
} 

void loop() 
{  
  int data_x = analogRead(X);
  int data_y = analogRead(Y);
  
  if (data_x==495 && data_y==490) {
    Serial.println("gauche en bas");
  }
  if (data_x==1 && data_y==1) {
    Serial.println("gauche en haut");
  }
  if (data_x==0 && data_y==1021) {
    Serial.println("droite en bas");
  }
  if (data_x==1021 && data_y==460) {
    Serial.println("droite au milieu");
  }
  if (data_x==1021 && data_y==1) {
    Serial.println("droite en haut");
  }
  if (data_x==495 && data_y==490) {
    Serial.println("milieu");
  }
  if (data_x==495 && data_y==1) {
    Serial.println("milieu en haut");
  }
  if (data_x==495 && data_y==1021) {
    Serial.println("milieu en bas");
  }

  Serial.print("X = ");
  Serial.println(data_x);
  Serial.print("Y = ");
  Serial.println(data_y);

  delay(100);                      
}
