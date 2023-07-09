/*
Proyecto realizado por Bernardo Cruz.

Canal de YouTube donde seguir el curso en el que realizamos
todos los proyectos que puedas ver en mi página de TinkerCAD:
Youtube:   http://www.youtube.com/c/BernardoVB

Tienda de Amazon de mi canal en la que puedes adquirir
cualquier artículo para tus proyectos de Arduino (No dejes de
visitar el escaparate "ARDUINO, ROBÓTICA Y ELECTRÓNICA":
https://www.amazon.es/shop/bernardocruz

Capítulo del ejercicio en el curso de Arduino de YouTube:


________________________________
*/
float Tiempo;     //Variable que almacena el tiempo recogido en Echo
float Distancia;  //Variable que almacena la distancia recorrida

void setup()  {
  Serial.begin(9600);   //Inicializo el puerto serie
  pinMode(2, OUTPUT);   //Declaro pin de TRIGGER como salida
  pinMode(3, INPUT);    //Declaro pin de ECHO como entrada
  pinMode(8, OUTPUT);   //Declaro pin de CONTROL DEL RELÉ como salida    
}

void loop() {
  //Pongo ambos pines del sensor ultrasónico en LOW para inicializarlo y que
  //haga un lanzamiento limpio
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  //Espero el tiempo que establece el fabricante, antes de ejecutar el lanzamiento
  delayMicroseconds(5);

  //Activo el pin del trigger (2) para ejecutar el lanzamiento ultrasónico
  digitalWrite(2, HIGH);
  //Espero el tiempo que establece el fabricante para que se realice el lanzamiento
  delayMicroseconds(10);
  //Desactivo el pin del Trigger (2) y con ello detengo el lanzamiento ultrasónico
  //y el pin del Echo (3) se activa automáticamente y recoge el tiempo que tarda
  //el ultrasonido en ir y regresar cuando choca con un obstáculo
  digitalWrite(2, LOW);

  //Recojo en la variable 'Tiempo', el tiempo almacenado en el sensor, mediante
  //la función 'pulseIn'
  Tiempo = pulseIn(3, HIGH);

  //A partir del tiempo recogido, calculo la distancia recorrida y la guardo
  //en la variable 'Distancia'
  Distancia = (0.0344 * Tiempo) / 2;

  //Hacemos una pausa necesaria para un eficaz siguiente lanzamiento
  delay(100);

  //Vemos los resultados en el puerto serie
  Serial.print("Distancia ");
  Serial.print(Distancia);
  Serial.println(" Ctms.");

  //Si acercamos las manos a menos de 7 Ctms. del sensor ultrasónico, se ha de
  //poner en marcha el secamanos, así que activamos el relé para que lo encienda.
  //Mientras las manos estén a más de 7 Ctms. del sensor, el relé debe de estar
  //desactivado para mantener el secamanos apagado.
  if (Distancia <= 7)   {
    digitalWrite(8, HIGH);  }
  else  {
    digitalWrite(8, LOW);   }  
}
