#include "stm32f10x_conf.h"
#include "police.h"
high Hauteur=Up;
int Angle=1;
void Set_Servo_Angle(int angle){
  if(Angle!=angle){
    Servo_Angle(angle*840/7);
    Delay(duree_servo);
  }
  Angle=angle;
}
void Set_stylo(high hauteur){
  if(Hauteur!=hauteur){
    Set_Pen(hauteur);
    Delay(duree_servo);
  }
  Hauteur=hauteur;
}
void ecrire_ligne(char ligne){
  int i;
    Set_stylo(Up);
//    Set_Servo_Angle(0);
    for(i=0;i<7 && ligne!=0;i++){
      if(ligne&0x1){
       Set_Servo_Angle(i);
       Set_stylo(Down);
       Set_Servo_Angle(i+1);
     }
     else
      Set_stylo(Up);
    ligne=ligne>>1;
  }
  return;
}
void avancer(int distance){
  Set_stylo(Up);
  rouler(distance);
}

void ecrire_lettre(char lettre){
  int i,j;
  for (i=0;i<5;i++){
    for(j=0;j<repetition_ligne;j++){
      ecrire_ligne(police[(int)lettre][i]);
      avancer(distance_entreligne);
    }
  }
  avancer(distance_entrecaractere);
  return;
}
void printf(char* chaine){
  int i=0;
  while(chaine[i]!='\n'){
    ecrire_lettre(chaine[i]);
    i++;
  }
  return;
}