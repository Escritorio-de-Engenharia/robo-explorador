#include <Arduino.h>

// Declarando variaveis pros sensores (IR / LDR)
#define IRExtremoDireita A0   // Sensor extremidade direita
#define IREsquerda A1         // Sensor esquerda meio
#define IRExtremoEsquerda A2  // Sensor extremidade esquerda
#define IRDireita A3          // Sensor direita meio
#define LDR A5                // Sensor meio

// Declarando variaveis pros motores (IN1, IN2, IN3, IN4)
#define MDireita1 10  // Motor Direita (IN1)
#define MDireita2 11  // Motor Direita (IN2)
#define MEsquerda1 9  // Motor Esquerda (IN3)
#define MEsquerda2 6  // Motor Esquerda (IN4)

// Declarando variaveis para a velocidade dos motores
#define vRetaDireita 80   // Velocidade Motor Direita
#define vRetaEsquerda 80  // Velocidade Motor Esquerda
#define vCurvaDireita 100 // Velocidade do motor direito quando se ajusta
#define vCurvaEsquerda 100 // Velocidade do motor esquerdo quando se ajusta

// Declarando variaveis para os valores 'branco' do sensor
#define pretoIR 1000  // Valor que o sensor IR detecta como branco
#define pretoLDR 985  // Valor que o LDR detecta como branco

// Variaveis que recebem a leitura dos sensores (Iniciam 0)
short SenED = 0;
short SenD = 0;
short SenM = 0;
short SenE = 0;
short SenEE = 0;

// Declarando as funções
void AndarFrente();      // Carro segue a linha
void AjeitarEsquerda();  // Ajeita o carro na linha reta
void AjeitarDireita();   // Ajeita o carro na linha reta
void CurvaEsquerda();    // Curva 90º
void CurvaDireita();     // Curva 90º

void setup() {
  Serial.begin(9600);  // Iniciando o monitor serial (9600 baud)

  // Declarando o tipo dos pinos dos motores como OUTPUT
  pinMode(MDireita1, OUTPUT);
  pinMode(MDireita2, OUTPUT);
  pinMode(MEsquerda1, OUTPUT);
  pinMode(MEsquerda2, OUTPUT);
}

void loop() {
  Sensores();

  Serial.print("ED: ");
  Serial.println(SenED);
  Serial.print("D: ");
  Serial.println(SenD);
  Serial.print("M: ");
  Serial.println(SenM);
  Serial.print("E: ");
  Serial.println(SenE);
  Serial.print("EE: ");
  Serial.println(SenEE);
  Serial.print("\n");

  // Sensor IR < pretoIR -> Sensor está no branco
  // LDR < pretoLDR -> Sensor está no branco

  // Andar para frente
  if (SenM < pretoLDR && SenE < pretoIR && SenD < pretoIR && SenED >= pretoIR && SenEE >= pretoIR) {
    AndarFrente();
  } else {
    // Ajusta a direção do carro pra direita
    if (SenE >= pretoIR && SenD < 970  && SenEE >= pretoIR) {
      AjeitarDireita();
    } else {
      // Ajusta a direção do carro pra esquerda
      if (SenD >= pretoIR && SenED >= pretoIR && SenE < pretoIR) {
        AjeitarEsquerda();
      } else {
        // Gira no proprio eixo pra fazer a curva
        if (SenM < pretoLDR && SenE < pretoIR && SenD < pretoIR && SenEE < 950 && SenED >= pretoIR) {
          CurvaEsquerda();
        } else {
          // Gira no propiro eixo pra fazer a curva
          if (SenM < 950 && SenE < 950 && SenD < 950 && SenEE >= pretoIR && SenED < 950) {
            CurvaDireita();
          }
        }
      }
    }
  }
}




    // Funções
    void Sensores() {
      SenED = analogRead(IRExtremoDireita);   // Valores do sensor IR da extremidade direita
      SenD = analogRead(IRDireita);           // Valores do sensor IR da direita (próximo do meio)
      SenM = analogRead(LDR);                 // Valores do sensor LDR (sensor do meio)
      SenE = analogRead(IREsquerda);          // Valores do sensor IR da esquerda (próximo do meio)
      SenEE = analogRead(IRExtremoEsquerda);  // Valores do sensor IR da extremidade esquerda
    }

    void AndarFrente() {
      analogWrite(MDireita1, vRetaDireita);
      analogWrite(MDireita2, 0);
      analogWrite(MEsquerda1, vRetaEsquerda);
      analogWrite(MEsquerda2, 0);
    }

    void AjeitarEsquerda() {
      analogWrite(MDireita1, 70);
      analogWrite(MDireita2, 0);
      analogWrite(MEsquerda1, 63);
      analogWrite(MEsquerda2, 0);
    }

    void AjeitarDireita() {
      analogWrite(MDireita1, 70);
      analogWrite(MDireita2, 0);
      analogWrite(MEsquerda1, 96);
      analogWrite(MEsquerda2, 0);
    }

    void CurvaEsquerda() {
      analogWrite(MDireita1, vCurvaDireita);
      analogWrite(MDireita2, 0);
      analogWrite(MEsquerda1, 0);
      analogWrite(MEsquerda2, vCurvaEsquerda);
    }

    void CurvaDireita() {
      analogWrite(MDireita1, 0);
      analogWrite(MDireita2, vCurvaDireita);
      analogWrite(MEsquerda1, vCurvaEsquerda);
      analogWrite(MEsquerda2, 0);
    }

    void Parar() {
      analogWrite(MDireita1, 0);
      analogWrite(MDireita2, 0);
      analogWrite(MEsquerda1, 0);
      analogWrite(MEsquerda2, 0);
    }