#include <Servo.h>
#include <SoftwareSerial.h>

Servo servo1, servo2, servo3, servo4, servo5;
int bluetoothTx = 7, bluetoothRx = 8, angle;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup(){
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);
  servo5.attach(13);

  open();
  
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop(){
  if(bluetooth.available() > 0){
    int command = bluetooth.read()*4+2;
    Serial.println(command);

    if(command== 2 ){ /* Open */
      open();
    }
    
    if(command== 6 ){ /* Close */
      close();
    }

    if(command > 10 && command < 200){
      angle=command-0;
      setServo(1, angle);
    }
    if(command > 200 && command < 400){
      angle=command-200;
      setServo(2, angle);
    }
    if(command > 400 && command < 600){
      angle=command-400;
      setServo(3, angle);
    }
    if(command > 600 && command < 800){
      angle=command-600;
      setServo(4, angle);
    }
    if(command > 800){
      angle=command-800;
      setServo(5, angle);
    }
  }
}

void setServo(int X, int Y){
  if(X==1){
    servo1.write(Y);
  }
  if(X==2){
    servo2.write(Y);
  }
  if(X==3){
    servo3.write(Y);
  }
  if(X==4){
    servo4.write(Y);
  }
  if(X==5){
    servo5.write(Y);
  }
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
