#include <Servo.h>
boolean lu;
Servo servo1, servo2, servo3, servo4, servo5;
int found;
String value1, value2, value3;

void setup(){
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);
  servo5.attach(13);

  open();

  Serial.begin(9600);
}

void loop(){
  if(Serial.available() > 0){
    String command = Serial.readString();
    
    decompose(command);

    bool lu=false;

    if(value1=="help"){
      lu=true;
      Serial.print("Command list :\n");
      Serial.print("open = Set all servos to 180 degrees\n");
      Serial.print("close = Set all servos to 0 degrees\n");
      Serial.print("set X Y = Sets servo n°X to Y degrees\n");
    }

    if(value1=="open"){
      lu=true;
      open();
    }
    
    if(value1=="close"){
      lu=true;
      close();
    }

    if(value1=="set"){
      lu=true;
      if(value2=="all"){allwrite(value3.toInt());}
      else{setServo(value2, value3.toInt());}
    }

    if(lu==false){
      Serial.print("Erreur: Commande inconnue. Tapez 'help' pour la liste des commandes.\n");
    }
  }
}

void decompose(String command){
  found=0;
  value1="";
  value2="";
  value3="";
  for(int i=0; i<=command.length()-1; i++){
    if(command.charAt(i)==' '){
      found+=1;
    }
    else{
      if(found==0){value1+=command.charAt(i);}
      if(found==1){value2+=command.charAt(i);}
      if(found==2){value3+=command.charAt(i);}
    }
  }
}

void setServo(String X, int Y){
  if(X=="1"){
    servo1.write(Y);
  }
  if(X=="2"){
    servo2.write(Y);
  }
  if(X=="3"){
    servo3.write(Y);
  }
  if(X=="4"){
    servo4.write(Y);
  }
  if(X=="5"){
    servo5.write(Y);
  }
}

void allwrite(int X){
  servo1.write(X);
  servo2.write(X);
  servo3.write(X);
  servo4.write(X);
  servo5.write(X);
}

void open(){
  servo1.write(10);
  servo2.write(10);
  servo3.write(10);
  servo4.write(10);
  servo5.write(10);
}

void close(){
  servo1.write(180);
  servo2.write(170);
  servo3.write(170);
  servo4.write(170);
  servo5.write(170);
}
