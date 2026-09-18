

/******************************************************************************************/
/* Affichage d'une voiture et test avec des data provenant de la PF arduino
/* Les données sont envoyées par le Sketch SerialDataSend_Arduino_car_v1 (Envoi de 4  trames différentes)
/* Les données : 1 trame de 5 octets
/* data : 
/* login_info = 17
/* meter_info = 2
/* Phares allumés (Light) si light_info = 1 et light_info = 0 pour les éteindre
/* Position de la voiture :   joystick_info = 1 -> front 
/*                            joystick_info = 2 -> back
/*                            joystick_info = 3 -> left
/*                            joystick_info = 4 -> right
/*                            joystick_info = 5 -> stop
/*                            joystick_info = 11 -> front_left_blink (front way and turn on left)
/*                            joystick_info = 12 -> front_right_blink
/*                            joystick_info = 13 -> back_left_blink
/*                            joystick_info = 14 -> back_right_blink
/*                            joystick_info = 15 -> left_front_blink
/*                            joystick_info = 16 -> left_back_blink
/*                            joystick_info = 17 -> right_front_blink
/*                            joystick_info = 18 -> right_back_blink
/*  logout_info = 17
/*  
/*  Rajout d'un texte à l'aide d'un Font
/*
/* S. CRAND - 26 juin 2012
/* Statut : OK 
/******************************************************************************************/

import processing.serial.*;
Serial myPort;        // The serial port

car une_voiture;
int width_cx = 100;
int length_cx = 200;
boolean stop_cx = false;
int  position_cx=5;
int light_cx = 0;
int blink_cx;

/* Réception d'une trame de 5 octets envoyé par ARDUINO*/
int login_info = 17;
/*********************************************/
/* light_info
/* 1 -> Light OK
/* 0 -> No Light
/*********************************************/
int light_info = 1;

int meter_info = 12;
/*********************************************/
/* Joystick_info 
/* 1 -> Front
/* 2 -> Back
/* 3 -> Right
/* 4 -> Left
/* 5 -> Stop
/*********************************************/
int joystick_info = 10;

int logout_info= 10;

boolean on=true;
int nb=0;
int data_serial=0;

PFont fontA;
String chaine;


int width_s = 1000;
int length_s = 800;


void setup() {
  size(1000, 800);
  nb = 0;
  //size(width_s, length_s);
  // Set the font and its size (in units of pixels)
  fontA = loadFont("ArialMT-12.vlw");
  textAlign(LEFT);
  textFont(fontA, 20);

  //myPort = new Serial(this, Serial.list()[10], 9600);
   println(Serial.list());
 myPort = new Serial(this, Serial.list()[0], 9600); // [0] car il y a un seul port disponible
 myPort.bufferUntil('\n');


  noStroke();
  smooth();
  une_voiture = new car(color(255, 0, 0), stop_cx, blink_cx, light_cx, position_cx, width/2, height/2, width_cx, length_cx);
  //light_info = 1;
}

void draw() {
  background(255);
  fill(0);
  text("L1 ISTN 25/26", 50, 50);
  chaine = " Distance : " + meter_info;
  text(chaine, 50, 100);

  une_voiture.stop();
  //une_voiture.stop_c = false; // exemple pour accéder directement à l'argument "stop_c"
  une_voiture.blink();

  une_voiture.light_c = light_info;
  if (light_info == 1) {
    chaine = " Light ";
  } else {
    chaine = " No Light";
  }
  text(chaine, 50, 150);

  // une_voiture.light(); // Fonction pour actionner les phares à l'aide du clavier


  switch (joystick_info) {
  case 5 : 
    une_voiture.stop_c = true;
    une_voiture.blink_c = 0;
    break;
  case 1 : 
    une_voiture.position_c = 1;
    une_voiture.blink_c = 0;
    break;
  case 2 : 
    une_voiture.position_c = 2;
    une_voiture.blink_c = 0;
    break;
  case 3 : 
    une_voiture.position_c = 3;
    une_voiture.blink_c = 0;
    break;
  case 4 : 
    une_voiture.position_c = 4;
    une_voiture.blink_c = 0;
    break;
  case 11 : 
    une_voiture.blink_c = 3;
    une_voiture.position_c = 1;
    break; // Blink_front_left
  case 12 : 
    une_voiture.blink_c = 4;
    une_voiture.position_c = 1;
    break; // Blink_front_right
  case 13 : 
    une_voiture.blink_c = 3;
    une_voiture.position_c = 2;
    break; // Blink_back_left
  case 14 : 
    une_voiture.blink_c = 4;
    une_voiture.position_c = 2;
    break; // Blink_back_right
  case 15 : 
    une_voiture.blink_c = 1;
    une_voiture.position_c = 3;
    break; // Blink_left_front
  case 16 : 
    une_voiture.blink_c = 2;
    une_voiture.position_c = 3;
    break; // Blink_left_back 
  case 17 : 
    une_voiture.blink_c = 1;
    une_voiture.position_c = 4;
    break; // Blink_right_front 
  case 18 : 
    une_voiture.blink_c = 2;
    une_voiture.position_c = 4;
    break; // Blink_right_back
  }

  // if (meter_info < 5) une_voiture.stop_c = true; Arrêt de la voiture si meter_info < 5 cm

  chaine = " Joystick : " + joystick_info;
  text(chaine, 50, 200);



  //if (joystick_info == 5) une_voiture.stop_c = true;  // Arret de la voiture
  //      else {//une_voiture.position_c = joystick_info;
  //      
  //if (joystick_info == 1) une_voiture.position_c = 1;
  //if (joystick_info == 2) une_voiture.position_c = 2;
  //if (joystick_info == 3) une_voiture.position_c = 3;
  //if (joystick_info == 4) une_voiture.position_c = 4;
  //if (joystick_info == 11) {une_voiture.blink_c = 3;une_voiture.position_c = 1;} // Blink_front_left
  //if (joystick_info == 12) {une_voiture.blink_c = 4;une_voiture.position_c = 1;} // Blink_front_right
  //if (joystick_info == 13) {une_voiture.blink_c = 3;une_voiture.position_c = 2;} // Blink_back_left
  //if (joystick_info == 14) {une_voiture.blink_c = 4;une_voiture.position_c = 2;} // Blink_back_right
  //if (joystick_info == 15) {une_voiture.blink_c = 3;une_voiture.position_c = 3;} // Blink_left_left
  //if (joystick_info == 16) {une_voiture.blink_c = 4;une_voiture.position_c = 3;} // Blink_left_right
  //if (joystick_info == 17) {une_voiture.blink_c = 3;une_voiture.position_c = 4;} // Blink_right_left
  //if (joystick_info == 18) {une_voiture.blink_c = 4;une_voiture.position_c = 4;} // Blink_right_left
  // 
  //      }



  //une_voiture.position(); // Fonction pour orienter la voiture à l'aide du clavier


  une_voiture.display();
  une_voiture.drive();
}

void serialEvent (Serial myPort) {

  String inString = myPort.readStringUntil('\n');
  if (inString != null) {
    // trim off any whitespace:
    inString = trim(inString);
    data_serial = int(inString);
    println(data_serial);
    if (data_serial == 35) nb=0;
    if (nb==0) login_info = data_serial;
    if (nb==1) meter_info = data_serial;
    if (nb==2) light_info = data_serial;
    if (nb==3) joystick_info = data_serial;
    if (nb==4) {
      logout_info = data_serial;  
      nb=0;
    } else nb = nb + 1;
    println("nb : "+nb);
  }
}

class car {

  color color_c;
  boolean stop_c;
  int light_c;
  int blink_c;
  int position_c;
  float center_cx;
  float center_cy;
  int width_c;
  int length_c;

  car(color color_cx, boolean stop_cx, int blink_cx, int light_cx, int position_cx, float center_cxx, float center_cxy, int width_cx, int length_cx) {
    color_c = color_cx;
    stop_c = stop_cx;
    blink_c = blink_cx;
    light_c = light_cx;
    position_c = position_cx;
    center_cx = center_cxx;
    center_cy = center_cxy;
    width_c = width_cx;
    length_c = length_cx;
  }


  void stop() {
    if (keyPressed) {
      println(stop_c);
      if (key == 's') stop_c = true ;
    } else stop_c = false;
  }

  void blink() {
    if (keyPressed) {
      if (key == CODED) {
        if (keyCode == UP) 
          blink_c = 1;
        if (keyCode == DOWN) 
          blink_c = 2;
        if  (keyCode == LEFT)
          blink_c = 3;
        if  (keyCode == RIGHT)
          blink_c = 4;
      }
    }
  }

  void light() {
    if (keyPressed) {
      if (key == 'A' || key == 'a') light_c = 1;
      if (key == 'Q' || key == 'q') light_c = 0;
    }
  }

  void position() {
    if (keyPressed) {
      if (key == 'F' || key == 'f') position_c = 1;
      if (key == 'B' || key == 'b') position_c = 2;
      if (key == 'L' || key == 'l') position_c = 3;
      if (key == 'R' || key == 'r') position_c = 4;
    }
  }

  void display() { // 1 = Nord-Sud, 2 = Sud-Nord, 3 = Ouest-Est, 4 = Est-Ouest
    fill(color_c); 

    if (position_c == 1) { 
      rect(center_cx, center_cy-length_c/8-1, width_c, length_c/8);
      fill(255, 0, 255);
      rect(center_cx, center_cy, width_c, length_c);

      fill(0, 0, 0);
      rect(center_cx-7, center_cy-length_c/8-1, 7, 20);
      rect(center_cx+width_c, center_cy-length_c/8-1, 7, 20);
      rect(center_cx-7, center_cy+length_c-20, 7, 20);
      rect(center_cx+width_c, center_cy+length_c-20, 7, 20);

      if (light_c == 1) {
        fill(0, 255, 0);
        rect(center_cx+10, center_cy-length_c/8-1-10, 10, 10);
        rect(center_cx+width_c-20, center_cy-length_c/8-1-10, 10, 10);
      } 
      if   (blink_c == 4) { // Right
        if (frameCount%5 == 0) {
          if (on)
            fill(255, 255, 255);
          else
            fill(255, 100, 0);
          on = !on;
          rect(center_cx+width_c-10, center_cy-length_c/8-1-10, 10, 10);
        }
      }
      if   (blink_c == 3) { // Left
        if (frameCount%5 == 0) {
          if (on)
            fill(255, 255, 255);
          else
            fill(255, 100, 0);
          on = !on;
          rect(center_cx, center_cy-length_c/8-1-10, 10, 10);
        }
      }
    }

    if (position_c == 2) { 
      rect(center_cx, center_cy+length_c+1, width_c, length_c/8);
      fill(255, 0, 255);
      rect(center_cx, center_cy, width_c, length_c);

      fill(0, 0, 0);
      rect(center_cx-7, center_cy, 7, 20);
      rect(center_cx+width_c, center_cy, 7, 20);
      rect(center_cx-7, center_cy+length_c+1+length_c/8-20, 7, 20);
      rect(center_cx+width_c, center_cy+length_c+1+length_c/8-20, 7, 20);

      if (light_c == 1) {
        fill(0, 255, 0);
        rect(center_cx+10, center_cy+length_c+1+length_c/8, 10, 10);
        rect(center_cx+width_c-20, center_cy+length_c+1+length_c/8, 10, 10);
      }
      if   (blink_c == 4) { // Right
        if (frameCount%5 == 0) {
          if (on)
            fill(255, 255, 255);
          else
            fill(255, 100, 0);
          on = !on;
          rect(center_cx+width_c-10, center_cy+length_c+1+length_c/8, 10, 10);
        }
      }
      if   (blink_c == 3) { // Left
        if (frameCount%5 == 0) {
          if (on)
            fill(255, 255, 255);
          else
            fill(255, 100, 0);
          on = !on;
          rect(center_cx, center_cy+length_c+1+length_c/8, 10, 10);
        }
      }
    }   
    if (position_c == 3) { 
      rect(center_cx-length_c/8-1, center_cy, length_c/8, width_c);
      fill(255, 0, 255);
      rect(center_cx, center_cy, length_c, width_c);

      fill(0, 0, 0);
      rect(center_cx-length_c/8-1, center_cy-7, 20, 7);
      rect(center_cx+length_c-20, center_cy-7, 20, 7);
      rect(center_cx-length_c/8-1, center_cy+width_c, 20, 7);
      rect(center_cx+length_c-20, center_cy+width_c, 20, 7);

      if (light_c == 1) {
        fill(0, 255, 0);
        rect(center_cx-1-length_c/8-10, center_cy+10, 10, 10);
        rect(center_cx-1-length_c/8-10, center_cy+width_c-20, 10, 10);
      } 
      if   (blink_c == 1) { // Up
        fill(255, 255, 0); // Test
        rect(100, 100, 50, 50);

        if (frameCount%5 == 0) {
          if (on)
            fill(255, 255, 255);
          else
            fill(255, 100, 0);
          on = !on;
          rect(center_cx-length_c/8-1-10, center_cy, 10, 10);
        }
      }
      if   (blink_c == 2) { // Down
        if (frameCount%5 == 0) {
          if (on)
            fill(255, 255, 255);
          else
            fill(255, 100, 0);
          on = !on;
          rect(center_cx-length_c/8-1-10, center_cy+width_c-10, 10, 10);
        }
      }
    }   
    if (position_c == 4) { 
      rect(center_cx+length_c+1, center_cy, length_c/8, width_c);
      fill(255, 0, 255);
      rect(center_cx, center_cy, length_c, width_c);

      fill(0, 0, 0);
      rect(center_cx, center_cy-7, 20, 7);
      rect(center_cx+length_c+length_c/8-20+1, center_cy-7, 20, 7);
      rect(center_cx, center_cy+width_c, 20, 7);
      rect(center_cx+length_c+length_c/8-20+1, center_cy+width_c, 20, 7);

      if (light_c == 1) {  
        fill(0, 255, 0);
        rect(center_cx+length_c+length_c/8+1, center_cy+10, 10, 10);
        rect(center_cx+length_c+length_c/8+1, center_cy+width_c-20+1, 10, 10);
      }
      if   (blink_c == 1) { // Up
        if (frameCount%5 == 0) {
          if (on)
            fill(255, 255, 255);
          else
            fill(255, 100, 0);
          on = !on;
          rect(center_cx+length_c+length_c/8+1, center_cy, 10, 10);
        }
      }
      if   (blink_c == 2) { // Down
        if (frameCount%5 == 0) {
          if (on)
            fill(255, 255, 255);
          else
            fill(255, 100, 0);
          on = !on;
          rect(center_cx+length_c+length_c/8+1, center_cy+width_c-10, 10, 10);
        }
      }
    }
  }

  void drive() {

    // if (stop_c) {fill(255,0,0);rect(100,100,100,100);}
    if (!stop_c) { // si stop_c = true -> Arret
      if (position_c == 1) center_cy = center_cy - 1;
      if (position_c == 2) center_cy = center_cy + 1;
      if (position_c == 3) center_cx = center_cx - 1;
      if (position_c == 4) center_cx = center_cx + 1;

      if (center_cx > width) center_cx = 0;
      if (center_cx < 0) center_cx = width;
      if (center_cy > height) center_cy = 0;
      if (center_cy < 0) center_cy = height;
    }
  }
}
