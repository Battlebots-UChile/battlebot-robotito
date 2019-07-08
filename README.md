
# Robotito
Robotito fue realizado en el taller de proyecto "Contruye tu battlebot", el cuál combina conocimientos de electrónica, mecánica y programación, bajo un acorazado de metal giratorio.
<center><img src="https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/multimedia/desdearriba.png" width="500" /><center>
<img src="https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/multimedia/desdeellado.png" width="300" />
<img src="https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/multimedia/robotito2.jpeg" width="300" />

## Integrantes
- Leslie Cárdenas - FCFM
- Tomás Ceballos - FCFM
- Francisca Guiñez - FCFM
- Keyla Sandoval - FCFM


## Descripción del proyecto

Robotito es un robot, pero no cualquier tipo de robot, NOOO... es un BATTLEBOT (por si no quedo claro en los títulos), controlado mediante una aplicación celular (App-Inventor), cuyo objetivo en la vida es detener todos los golpes que intenten destruirlo.

Funciona en base a dos motores DC básicos, uno conectado a cada rueda, y un motor DC de 2500 rpm conectado a un bowl de cocina, a través de una pieza impresa en 3D. Cuenta con dos puentes H, uno dual y uno single, y es alimentado por dos baterias LiPo.

### Descripción morfológica
La forma elegida para nuestro robot surgió de pensar en cual sería la más óptima defensiva. Por esto nos inclinamos por utilizar un bowl. Pensamos que, por un lado, su forma semiesférica iba a imposibilitar cualquier intento de agarrarlo.
Además, al estar hecho de acero inoxidable claramente iba a ser poco probable que le produjeran daños graves.

Cabe decir que antes de tomar una decisión realizamos una exhaustiva investigación en Youtube sobre battlebots alrededor del mundo

### Estrategia utilizada

La mejor estrategia para ganar con Robotito es:
- Evitando ataques laterales: Creemos que lo que podría dañar el bowl serían golpes muy reiterativos, contundentes y punzantes de alguna forma. Por ejemplo una barra o punta de un material lo suficientemente resistente. Por lo que lo ideal es evitarlos.
- Interponiendosea a la trayetoria del arma del robocontrincante: Como Robotito es un bowl de metal, en general los golpes no lo afectan. La idea es entonces que el motor que controla el arma del contrincante sea sometido a pick de corriente que lo imposibiliten de seguir golpeandolo por un tiempo. Esto para dar opcion al siguiente punto.
- Alejarse del oponente cuando sea posible: Esto es mas que todo para evitar golpes innecesarios que no vayan a ayudar en la estrategia anteriormente mencionada. Es una buena idea alejarse, luego posicionarse y direccionarse hacia el roboenemigo en busca de un empujón que lo lleve al borde la pista, o bien, hacia alguna arma que pueda haber en esta.  
Una demostración de esto se puede ver [aquí](https://drive.google.com/file/d/1hvNaAUOcBa2c_J4brZBd_sA4WgRW3LiS/view?usp=sharing).

#### Datos defensivos
El bowl es nuestra principal , pero no única, defensa. Es de acero inoxidable. Proviene directamente de la cocina de una de las integrantes de nuestro grupo :).  
Pero como un pedazo de metal no puede con todo (¿o si?), para detener los posibles ataques a ras de suelo (ya que el bowl deja un par de centímetros al descubierto), nuestro battlebot cuenta con lo que denominamos una "falda", cortada con laser en MDF de 6mm.
Además, cabe decir que la forma circular o semiesférica conseguida también ayuda a que los golpes no lleguen de forma directa.

### Descripción control
Robotito tiene su propia app para Android, la cual pueden descargar [aquí](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/codigos/APK).
Al ingresar, se pueden ver 3 secciones:

#### Conexión
Para conectar la app al módulo BT del robot, basta con:
1. Prender el robot (nunca está de más cerciorarse)
2. Activar el Bluetooth del celular
3. Entrar a la app desde el celular
4. Presionar "Buscar dispositivos"
5. Seleccionar el nombre correspondiente al módulo bluetooth (modificable, Google es la luz)
6. Esperar. Cuando la luz del módulo BT deje de parpadear, será un indicador de que se ha establecido una conexión.

#### Movimiento
Estos 7 botones cumplen con el objetivo de movilizar nuestro robot. Cuando se presiona un botón, la orden se manda de manera constante, es decir, que, a menos que se presione otro, la acción se seguirá ejecutando.  
A continuación, se especifica cómo giran los motores, dependiendo del botón presionado. 
<img src="https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/multimedia/tabla_botones.png" width="320" width="550"/>

#### Arma y emergencia
En caso de emergencia de debe presionar el botón STOP. ¿Qué hace? Manda una señal que detiene el movimiento de los 3 motores que componen a Robotito de manera instantánea (en cuando la señal sea recibida). No afecta el funcionamiento del ventilador, ya que funciona de manera independiente.
Luego, podemos ver una numeración de 5 botones, los cuales son las posibles velocidades del arma (se pueden modificar dentro del código. ino, pero no lo sugerimos). En "0" el motor no se mueve. Si se presiona cualquiera que modifique la velocidad actual, el aumento o descenso será paulatino.
#### Otros
La app también cuenta con un particular sonido al presionar algunas de las teclas. Fuente: desconocida.  
Además, cuenta con la posibilidad de activar la reproducción de la canción "Mr. Roboto", presionando el switch de la parte inferior.

##  Paso a Paso

### Materiales:
- 1 Arduino Nano
- 1 Bowl de acero inoxidable
- 1 Rueda loca
- 2 Motores DC con ruedas
- 1 Puente H BTS7960
- 1 Puente H dual L298n
- 1 Módulo Bluetooth HC-06
- 2 Baterías Li-Po de 7.4V
- 1 Ventilador de 30x30mm
- 3 Ruedas de 20mm
- 4 Separadores hexagonales de 50mm (\*)
- 20 cm de Velcro
- 2 Conectores hembra HT60 (\*\*)
- 2 Interruptores (\*\*\*)
- 4 Pernos de 2mm
- 2 Tuercas de 2mm
- Pernos y tuercas de 3mm
- Cables
- Cables para Arduino
- Placa MDF de 3mm (opcional 6mm)
- Soldadura para electrónica
- Termoretráctil de varias medidas
- Adhesivo instantáneo, como La Gotita (\*\*\*\*)

### Herramientas:
- Alicates varios
- Destornilladores varios
- Pistola de calor o encendedor
- Cautín
- Dremel
- Impresora 3D
- Cortadora Láser
- Limas metálicas
- Celular Android

### Opcionales:
- Alarma para Li-Po
- Cargador de Li-Po

(\*) o alguna combinación que resulte en esa altura.  
(\*\*) o del tipo que corresponda, según el conector de las LiPos.  
(\*\*\*) Debe poder soportar la corriente del motor. Nosotros usamos uno que soportaba 15A.  
(\*\*\*\*) No nos auspician :(
### Instrucciones

1. Imprimir las piezas en 3d, desde [aquí](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/planos/Piezas%203d), según lo que se indica en su descripción, y lijar para eliminar imperfecciones.  
2. Cortar las dos bases para el robot, desde [aquí](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/planos/Bases) y quitar imperfecciones.
3. Conectar el Arduino Nano a un PC, y cargar el [codigo](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/codigos/arduino/app_bt).
4. Descargar el [apk](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/codigos/APK) mediante el celular y ejecutar el instalador.
5. Probar las componentes individualmente.
6. Ubicar los [motores DC](https://www.wiltronics.com.au/wp-content/uploads/images/make-and-create/gear-motor-dc-toy-car-wheel-arduino.jpg) con sus respectivas ruedas, utilizando el [agarre 1](https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/planos/Piezas%203d/agarre_yellowmotor1.stl) y el [agarre 2](https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/planos/Piezas%203d/agarre_yellowmotor2.stl) en la base cortada con láser que tiene los orificios para las ruedas, utilizando 4 pernos de 3mm. Esta parte puede ser un poco complicada, pero de ser necesario las piezas 3d se pueden lijar un poco más.   
Para reforzar, aplicar el adhesivo instantáneo a la unión entre las piezas 3d y la base. 
7. Solo con pernos(3mm) (con 2 es suficiente), agarrar el ventilador a la [base del ventilador](https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/planos/Piezas%203d/base_ventilador.stl) y posteriormente al puente H BTS7960. Esto último, solo con 2 orificios opuestos utilizando pernos de 2 mm (la tuerca va puesta por el lado de la pieza 3d).
8. A la estructura anterior, agregarle la [base](https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/planos/Piezas%203d/base_bts7960.stl), utilizando pernos de 3 mm, y ensamblar a la base de las ruedas en la posición determinada. En este punto se puede notar que los pines del puente H quedan hacia la base. Nosotros creamos una pequeña pieza, que no ha sido detallada, debido a que tuvo fallas y será definitivamente modificada.
9. Juntar el puente H L298n a su respectiva [base](https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/planos/Piezas%203d/base_l298n.stl). Para esto, primero se deben ubicar las tuercas en los orificios que correspondan. Luego, con pernos de un largo limitado (posiblemente deban cortarlos), agarrar el puente H.
10. Ensamblar como se detalla en el [esquema](https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/multimedia/esquema_rueda.png), agregando pernos donde corresponda.
11. Cortar dos pedazos de velcro, del tamaño de las baterías y, con silicona caliente (y mucho cuidado, nunca se sabe), pegárselos.
12. Para fijar el Arduino a la base de arriba, también se hizo una pieza, que se evidencia en la siguiente imagen. (algún día estará acá)
13. Agregar los interruptores en los orificios laterales a las ruedas.
14. Usar [esto](https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/planos/Piezas%203d/agarre_motorarma.stl) para fijar el motor del arma a la base de arriba. Primero introducir con mucho cuidado los pernos que agarran el motor con la pieza 3d.
15. Teniendo en cuenta las [conexiones](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/diagrama), ahora se puede comenzar a cablear.  
Tener en cuenta: no mantener conectadas las baterías cuando se realice esto. Tener claro cuando los interruptores no están dejando pasar energía. Todas los GND deben estar conectados. La base de arriba tiene orificios para los conectores HT60 de las baterías. Para las conexiones desde la LiPo al puente H BTS7960 se debe utilizar un cable más grueso que pueda soportar altos de corriente.
16. Probar las direcciones de las ruedas, si estas no tienen sentido, probar rotar cables de los motores de las ruedas.
17. Si existe algún otro problema operacional, consultar sección [Problema-Solución](https://github.com/Battlebots-UChile/battlebot-robotito#problema---solución)
18. Una vez que todos los motores funcionen según las indicaciones dadas por la app, se recomienda fijar los cables de Arduino con silicona caliente, o en el caso de ser necesario, soldar.
19. Agregar los separadores en los espacios determinados con pernos y tuercas.
20. Al bowl realizarle 3 orificios con un taladro a 40mm desde el centro, ser lo más preciso posible. Esto puede ser muy complicado, por lo que: paciencia.
21. Fijar la [pieza](https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/planos/Piezas%203d/agarre_motorbowl.stl) al bowl, usando pernos.
22. Posicionar la pieza anterior sobre el motor del arma.
23. Destruir a todos

## Problema - Solución
1. Conexiones sueltas  	
Inicialmente teníamos muchas conexiones que estaban agarradas mediante cinta aislante. Pero llegó un punto en el desarrollo del robot donde esto no era eficiente, ya que, debido a la gran cantidad de cables y componentes, estas se soltaban regularmente y entorpecía el avance.  
Solución: Aprender a soldar. Soldar todo lo que estaba más o menos fijo (referido a: Si, este cable va con este hasta el fin de los tiempos) y obviamente funcional.

2. No se cargaba el código al Arduino  
El principal error cuando uno se inicia en el uso de Arduino y módulos BT, es conectar los pines RX y TX con sus opuestos en el otro dispositivo. En el Arduino estos están designados a los pines 0 y 1, pero cuando están ocupados: no se le puede cargar otro código, ni tampoco interactuar con el Serial.  
Solución: Designar nuevos pines RX y TX dentro del Arduino, con la librería SofwareSerial. 

3. El motor del arma no giraba de manera constante  
Desde un principio, la corriente del motor del arma fue desconocida, por lo que, al momento de conectarlo a diversas pilas y baterías, no alcanza la velocidad ni la fuerza que buscábamos.  
Solución: Utilizar baterías LiPo. Su principal característica es que puede entregar mucha corriente en poco tiempo, justo lo que necesitábamos.

4. Quemamos un puente H  
La gran cantidad de amperaje quemo nuestro puente H inicial (VNH2SP30), ya que los 30A que suposimos podia soportar, era solo para picks, no de manera continua. Además, se calentaba hasta los 70-100°C.  
Solución: Lo reemplazamos por el BTS7960, capaz de soportar 40A de manera continua. Este ahora cuenta un disipador bastante grande y un ventilador.

5. Cables rozando con el bowl  
Provocaba que el motor del arma necesitara más corriente para funcionar y ocasionaba que las baterias se gastaran más rapido.  
Solución: Tomar los cables del piso superior con una pieza plastica y pegar otros con silicona caliente.

6. Falta de espacio  
Al decidirnos a utilizar un bowl, creímos que el espacio no iba a ser un problema, pero con el cambio de baterías, nos faltaba.  
Solución: Cambiar un Arduino Uno por un Arduino Nano. Reubicar componentes.

### Proyecciones a futuro
* Cambiar el método de control: es decir, en vez de usar la App, crearemos un control con botones y un joystick. Esto ya esta en proceso y sus respectivos códigos están actualizados y funcionaless.
#### ![Joystick con Arduino](/multimedia/arduino-joystick.png)
* Adición de un arma: Fijaremos a la parte inferior del bowl una estructura hecha de placa MDF, la cual constará de un anillo con tres protuberancias. La idea es que debido a la velocidad y la fuerza con la que gira el bowl, si un roboenemigo se acerca lo suficiente, este sera levantado y dejado caer en reiteradas ocasiones en un periodo corto de tiempo, con la intención de provocar sacudidas que puedan dañar interna y/o externamente a los demás robots. (Planos: Próximamente...)

## Licencia
<a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/"><img alt="Licencia Creative Commons" style="border-width:0" src="https://i.creativecommons.org/l/by-nc/4.0/88x31.png" /></a><br />Esta obra está bajo una <a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/">Licencia Creative Commons Atribución-NoComercial 4.0 Internacional</a>.
