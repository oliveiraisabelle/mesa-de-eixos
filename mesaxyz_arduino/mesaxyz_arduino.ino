// Mesa de eixos x,y,z 
//Mesa pneumática com valvula e ventosa
//Isabelle Oliveira Santos

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define X0 36
#define X1 34
#define Y0 32
#define Y1 30
#define Z0 22
#define Z1 24
#define X 38
#define Y 40
#define Z 42
#define Vent 44

unsigned char Passo = 0;
unsigned char Tecla = A0;
unsigned int cont = 0;

void setup() {
  pinMode( X0, INPUT_PULLUP);
  pinMode ( X1, INPUT_PULLUP);
  pinMode ( Y0, INPUT_PULLUP);
  pinMode ( Y1, INPUT_PULLUP);
  pinMode( Z0, INPUT_PULLUP);
  pinMode ( Z1, INPUT_PULLUP);
  pinMode( X, OUTPUT);
  pinMode( Y, OUTPUT);
  pinMode ( Z, OUTPUT);
  pinMode (Vent, OUTPUT);
  digitalWrite(X, 0);
  digitalWrite(Y, 0);
  digitalWrite(Z, 0);
  lcd.begin(16, 2);

  lcd.setCursor(0, 0 );
  lcd.print("PECAS PRONTAS:");
  lcd.print(cont);

  lcd.setCursor(0, 1 );
  lcd.print("Press Iniciar   ");


}

void loop() {
  Tecla = analogRead(A0);
  switch (Passo)
  {
    case 0:
      if (Tecla == 0)
      {
        Passo = 1;
        digitalWrite(Z, 1);
        lcd.setCursor(0, 1 );
        lcd.print("                ");
      }
      break;

    case 1:
      if (digitalRead(Z1) == 0)
      {
        Passo = 2;
        digitalWrite(Vent, 1);
        delay(1000);
        digitalWrite(Z, 0);
        lcd.setCursor(0, 1 );
        lcd.print("Objeto capturado");
      }
      break;

    case 2:
      if (digitalRead(Z0) == 0)
      {
        Passo = 3;
        digitalWrite(Y, 1);
        lcd.setCursor(0, 1 );
        lcd.print("Eixo Y em avanco");
      }
      break;

    case 3:
      if (digitalRead(Y1) == 0)
      {
        Passo = 4;
        digitalWrite(Z, 1); //primeira descida
        lcd.setCursor(0, 1 );
        lcd.print("Objeto banhado 1");
      }
      break;

    case 4:
      if (digitalRead(Z1) == 0)
      {
        Passo = 5;
        digitalWrite(Z, 0);
      }
      break;

    case 5:
      if (digitalRead(Z0) == 0)
      {
        Passo = 6;
        digitalWrite(Z, 1); // segunda descida
        lcd.setCursor(0, 1 );
        lcd.print("Objeto banhado 2");
      }
      break;

    case 6:
      if (digitalRead(Z1) == 0)
      {
        Passo = 7;
        digitalWrite(Z, 0);
      }
      break;

    case 7:
      if (digitalRead(Z0) == 0)
      {
        Passo = 8;
        digitalWrite(Z, 1); // terceira descida
        lcd.setCursor(0, 1 );
        lcd.print("Objeto banhado 3");
      }
      break;

    case 8:
      if (digitalRead(Z1) == 0)
      {
        Passo = 9;
        digitalWrite(Z, 0);
      }
      break;

    case 9:
      if (digitalRead(Z0) == 0)
      {
        Passo = 10;
        digitalWrite(Z, 1); // quarta descida
        lcd.setCursor(0, 1 );
        lcd.print("Objeto banhado 4");
      }
      break;

    case 10:
      if (digitalRead(Z1) == 0)
      {
        Passo = 11;
        digitalWrite(Z, 0);
      }
      break;

    case 11:
      if (digitalRead(Z0) == 0)
      {
        Passo = 12;
        digitalWrite(Z, 1); // quinta descida
        lcd.setCursor(0, 1 );
        lcd.print("Objeto banhado 5");
      }
      break;

    case 12:
      if (digitalRead(Z1) == 0)
      {
        Passo = 13;
        digitalWrite(Z, 0);
        lcd.setCursor(0, 1 );
        lcd.print("Eixo Z em recuo ");

      }
      break;

    case 13:
      if (digitalRead(Z0) == 0)
      {
        Passo = 14;
        digitalWrite(Y, 0);
        lcd.setCursor(0, 1 );
        lcd.print("Eixo Y em recuo ");
      }
      break;

    case 14:
      if (digitalRead(Y0) == 0)
      {
        Passo = 15;
        digitalWrite(X, 1);
        lcd.setCursor(0, 1 );
        lcd.print("Eixo X em avanco");

      }
      break;

    case 15:
      if (digitalRead(X1) == 0)
      {
        Passo = 16;
        digitalWrite(Z, 1); //primeira descida
        lcd.setCursor(0, 1 );
        lcd.print("Objeto banhado 1");
      }
      break;

    case 16:
      if (digitalRead(Z1) == 0)
      {
        Passo = 17;
        digitalWrite(Z, 0);
      }
      break;

    case 17:
      if (digitalRead(Z0) == 0)
      {
        Passo = 18;
        digitalWrite(Z, 1); //segunda descida
        lcd.setCursor(0, 1 );
        lcd.print("Objeto banhado 2");
      }
      break;

    case 18:
      if (digitalRead(Z1) == 0)
      {
        Passo = 19;
        digitalWrite(Z, 0);
      }
      break;

    case 19:
      if (digitalRead(Z0) == 0)
      {
        Passo = 20;
        digitalWrite(Z, 1); //terceira descida
        lcd.setCursor(0, 1 );
        lcd.print("Objeto banhado 3");
      }
      break;

    case 20:
      if (digitalRead(Z1) == 0)
      {
        Passo = 21;
        digitalWrite(Z, 0);
        lcd.setCursor(0, 1 );
        lcd.print("Eixo Z em recuo ");

      }
      break;

    case 21:
      if (digitalRead(Z0) == 0)
      {
        Passo = 22;
        digitalWrite(Y, 1);
        lcd.setCursor(0, 1 );
        lcd.print("Eixo Y em avanco");
      }
      break;

    case 22:
      if (digitalRead(Y1) == 0)
      {
        Passo = 23;
        digitalWrite(Z, 1);
        lcd.setCursor(0, 1 );
        lcd.print("Etapa final     ");
      }
      break;

    case 23:
      if (digitalRead(Z1) == 0)
      {
        Passo = 24;
        digitalWrite(Vent, 0);
        lcd.setCursor(0, 1 );
        lcd.print("Objeto solto    ");
      }
      break;

    case 24:
      if (digitalRead(Vent) == 0)
      {
        Passo = 25;
        digitalWrite(Z, 0);
        lcd.setCursor(0, 1 );
        lcd.print("Finalizado      ");
      }
      break;

    case 25:
      if (digitalRead(Z0) == 0)
      {
        Passo = 26;
        digitalWrite(Y, 0);
        lcd.setCursor(0, 1 );
        lcd.print("Reiniciando     ");
      }
      break;

    case 26:
      if (digitalRead(Y0) == 0)
      {
        Passo = 27;
        digitalWrite(X, 0);
      }
      break;

    case 27:
      if (digitalRead(X0) == 0)
      {
        Passo = 0;
        ++cont;
        lcd.setCursor(14, 0 );
        lcd.print(cont);
        lcd.setCursor(0, 1 );
        lcd.print("Press Reiniciar ");
      }
      break;
  }

}
