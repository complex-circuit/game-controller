#include <Keyboard.h>
#include <Mouse.h>
void setup() {
  Mouse.begin();
Keyboard.begin();


}

void loop() {int Ly=analogRead(A0);int Lx=analogRead(A1);
  int Ry=analogRead(A3);int Rx=analogRead(A4);
  int rx=0;int ry=0;
  
  
  if(analogRead(A9)>=1000){//                   Minetest controls
if(analogRead(A2)==0){Mouse.press(MOUSE_LEFT);}else{Mouse.release(MOUSE_LEFT);}
if(analogRead(A5)==0){Mouse.press(MOUSE_RIGHT);}else{Mouse.release(MOUSE_RIGHT);}
if(Ly>900){Keyboard.press(119);}else{Keyboard.release(119);}
if(Lx<10){Keyboard.press(97);}else{Keyboard.release(97);}
if(Ly<10){Keyboard.press(115);}else{Keyboard.release(115);}
if(Lx>900){Keyboard.press(100);}else{Keyboard.release(100);}

if(Ry<400){ry=(400-Ry)/100;}
if(Ry>500){ry=(500-Ry)/100;}

if(Rx<400){rx=(Rx-400)/100;}
if(Rx>500){rx=(Rx-500)/100;}

Mouse.move(rx,ry,0);

if(analogRead(A6)>=1000){Keyboard.press(129);}else{Keyboard.release(129);}
if(analogRead(A7)>=1000){Keyboard.press(101);}else{Keyboard.release(101);}
if(analogRead(A8)>=1000){Keyboard.press(32);}else{Keyboard.release(32);}
delay(10);
  }else{//                   Nethack mode
    boolean h=LOW;boolean j=LOW;boolean k=LOW;boolean l=LOW;
if(Ly>900){k=HIGH;}
if(Lx<100){h=HIGH;}
if(Ly<10){j=HIGH;}
if(Lx>900){l=HIGH;}

if(h&&k){Keyboard.print("y");}
if(h&&j){Keyboard.print("b");}
if(l&&k){Keyboard.print("u");}
if(l&&j){Keyboard.print("n");}
if(h&&!k&&!j){Keyboard.print("h");}
if(j&&!h&&!l){Keyboard.print("j");}
if(k&&!h&&!l){Keyboard.print("k");}
if(l&&!k&&!j){Keyboard.print("l");}
if(analogRead(A6)>=1000){Keyboard.print(">");}
if(analogRead(A7)>=1000){Keyboard.press(46);}else{Keyboard.release(46);}
if(analogRead(A8)>=1000){Keyboard.print("<");}

if(Ry>900){Keyboard.press(129);}else{Keyboard.release(129);}
if(Rx<100){Keyboard.print(",");}
if(Ry<10){Keyboard.press(128);Keyboard.press(100);Keyboard.release(100);Keyboard.release(128);}
if(Rx>900){Keyboard.print(" ");}
if(analogRead(A2)==0){Keyboard.print("#loot\n");}
if(analogRead(A5)==0){Keyboard.print("nethack\nnwhmny, .");}

delay(125);digitalWrite(13,HIGH);
delay(125);digitalWrite(13,LOW);
  }

}
