/*
Proyecto realizado por Bernardo Cruz.

Canal de YouTube donde seguir el curso en el que realizamos
todos los proyectos que puedas ver en mi página de TinkerCAD:
Youtube:   http://www.youtube.com/c/BernardoVB

Tienda de Amazon de mi canal en la que puedes adquirir
cualquier artículo para tus proyectos de Arduino (No dejes de
visitar el escaparate "ARDUINO, ROBÓTICA Y ELECTRÓNICA)":
https://www.amazon.es/shop/bernardocruz

Es muy aconsejable que veas el capítulo del ejercicio en el
curso de Arduino de YouTube para una mejor comprension:
https://www.youtube.com/watch?v=A75o7NI2NNY
________________________________
*/

void setup() {
  //Declaramos el pin que activa y desactiva el relé
  pinMode(10, OUTPUT);
  //Abrimos puerto serie para ver el estado del relé
  Serial.begin(9600);
}

void loop() {
  //Activo relé y éste cierra el circuito y pone en marcha el motor
  digitalWrite(10, HIGH);
  Serial.println("Relé está activado y el motor funcionando");
  //Mantengo el motor funcionando durante 3 segundos
  delay(3000);

  //Desactivo relé y éste abre el circuito y detiene el motor
  digitalWrite(10, LOW);
  Serial.println("Relé está desactivado y el motor detenido");
  //Mantengo el motor parado durante 3 segundos
  delay(3000);
}
