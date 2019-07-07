﻿
# Robotito
Robotito es un battlebot realizado en el taller de proyecto "Contruye tu battlebot", el cuál combina conocimientos de electrónica, mecánica y programación, bajo un acorazado de metal giratorio.

### ![ Piso inferior](/multimedia/robotito2.jpeg)
### ![Piso superior](/)

### ![Exterior](/multimedia/robotito1.jpeg)


## Integrantes
- Leslie Cárdenas - FCFM
- Tomás Ceballos - FCFM
- Francisca Guiñez - FCFM
- Keyla Sandoval - FCFM


## Descripción del proyecto

Robotito es un robot, pero no cualquier tipo de robot, NOOO... es un BATTLEBOT (por si no quedo claro en los títulos), controlado mediante una aplicación celular (App-Inventor), cuyo objetivo en la vida es detener todos los golpes que intenten destruirlo.

Funciona en base a dos motores DC básicos, uno conectado a cada rueda, y un motor DC de 2500 rpm, conectado a un bowl de cocina, a través de una pieza impresa en 3D. Cuenta con dos puentes H, uno dual y uno single, y es alimentado por dos baterias LiPo.

El modelo es similiar al de un OVNI ya que apostamos que la velocidad evitaría que nos atraparan y haría difícil acercarse sin ser expulsados lejos debido a la aceleración ,además el material elegido es un acero que funciona como acorazado lo que nos brinda resistencia.

### Estrategia utilizada
Elegimos este diseño como un modo de unir defensa y ataque. Según nuestra hipótesis la velocidad del objeto iba a ser tanta que cualquier intento por detenerlo o atacarlo directamente iba a resultar en el battlebot enemigo siendo empujado, o en el mejor de los casos podría detener su sistema de ataque, dada a la alta cantidad de potencia necesaria para detener el giro del bowl.

La mejor manera de ganar es evitar golpes laterales; nos referimos a golpes contundentes con un objeto cuyo borde sea masivo, por ejemplo una barra de metal;esto es porque al golpear de manera lateral raya el casco provocando su desgaste y a largo plazo puede provocar abolladuras.

### [Daños tipo]()

#### Defensiva
El bowl es nuestra principal y evidente, pero no única, defensa. Es de acero inoxidable. Proviene directamente de la cocina de una de las integrantes de nuestro grupo :).
Pero como un pedazo de metal no puede con todo (¿o si?), para detener los posibles ataques a ras de suelo (ya que el bowl deja un par de centímetros al descubierto), nuestro battlebot cuenta con lo que denominamos una "falda", cortada con laser en MDF de 6mm.
Además, cabe decir que la forma circular o media esférica conseguida también ayuda a que los golpes no lleguen de forma directa.

Nuestro principal recurso es el giro, al atacar, hacerlo de costado si es que el contricante presenta algún tipo de arma  y tratar de interponerse en su movimiento de forma permante; un motor DC convencional no soporta la subida extrema de amperaje debido a la resistencia presentada, lo que provoca que se quemen o bien detengan su función momentáneamente, momento propicio para empujarlos y botarlos de la plataforma.
Las debilidades son mas bien de control, al ser un casco esférico si no se coloca una distinción no se puede saber donde esta el frente por lo que es dificil maniobrar.

#### Ofensiva
Como dijimos anteriormente nuestro modelo en sí mismo es una arma, pero aún así pensamos integrar un complemento a la carcasa en la zona mas baja de la misma, dicha estructura hecha de placa MDF consta de un anillo con tres protuberancias que dada a su ubicacion pasarían por debajo de los distintos robots levantandolo usando solo la velocidad y fuerza del motor conectado al casco.

### Diagrama funcional
<Diagrama general de funcionamiento. Se sugiere un esquema de sistemas, completo.>

###  Paso a Paso

#### Materiales:

- 1 Arduino Nano
- 1 bowl de acero inoxidable
- 1 rueda pivote
- 2 motores reductores con ruedas
- 1 Puente H BTS7960
- 1 Puente H dual L298n
- 2 Baterías Li-Po de 7.4V
- 1 Ventilador de 3x3cm
- 3 Ruedas de 20mm

- Tuercas y pernos de 3mm
- Cables para Arduino
- Placa MDF de 3mm (opcional 6mm)
- Soldadura para electrónica
- Termoretráctil

#### Herramientas:
- Alicates
- Destornilladores
- Pistola de calor o encendedor
- Cautín
- Dremel
- Impresora 3D
- Cortadora Lasér

#### Opcionales:
- Alarma para Li-Po
- Cargador de Li-Po

Para empezar el arduino va conectado a dos puentes H; el primero llamado BTS7960 43A,tiene la peculiaridad de soportar 43 amperes de corriente continua lo que fue ideal para nuestro gran motor DC el cual con los constantes golpes tenia que ejercer una gran fuerza para no detenerse por lo cual consumía mucho amperaje;tuvimos cuidado de elegir el puente H correcto ya que si este no soportaba podría quemarse y con el todo el circuito relacionado a ese motor, aún así por precaución lo ubicamos sobre una carcasa hecha en la impresora 3D que contenía un ventilador conectado directamente a una  Lipo ,dicho puente tenía dos entradas conectadas a la bateria y dos salidas conectadas al motor bélico (así denominados al motor DC desconocido)
![ ](/multimedia/rueda.jpeg)

### Sobre la app

![Tabla Explicativa](/multimedia/tabla_botones.png)

### Problema - Solución
1- el primer conflicto fueron las conexiones las que se soltaban constantemente lo que provocaba problemas de cortos al tratar de provar el funcionamiento de los mecanismos, en específico del motor bélico que dado a la gran cantidad de amperaje eran mucho mas notorios los chispazos, para esto una vez decicidida la mejor distribución soldamos las conexiones.

2- el motor tendía a rodar ligeramente sobre si mismo por lo que toda la fuerza de rotación no se centraba en el bool, para ello se le creo una pieza en la impresora 3D que se apernaba a la base manteniendlo quieto.

3-La gran cantidad de amperaje quemo nuestro puente H inicial el VNH2SP30 por lo que lo reemplazamos por uno que aguantara 43 amperes de corriente continua

### Proyecciones a futuro
Dado al satisfactorio resultado de la competencia, cuyos video se puede ver en (https://drive.google.com/drive/folders/1BpDF191vPP6yp6vsLNgYQf0TWKebsp2z) nuestras modificaciones son meramente opcionales y de ser quisquillosos.
La primera es cambiar el metodo de manejo, es decir, en vez de usar la App pensamos en cambiarlo para utilizar un joystick lo que obviamente implicaría cambiar los códigos los que serán agregados una vez hecha la modificación.
#### ![Joystick con arduino](/multimedia/arduino-joystick.png)

La otra modificación es agregar un especie de cinturon al casco con 3 protuberancias ubicadas en la parte inferior del mismo, la idea surgió de la observación en batalla ,nos percatamos que casi todos los golpes son efectuados en la parte inferior del acorazado por lo tanto pensamos agregar esta estructura que pasará debajo de los robots(pensado en los modelos con los que ya peleamos) y los levatará con la velocidad del giro. Obviamente una vez lista la estructura se subirán los planos correspondientes.


## Licencia
<a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/"><img alt="Licencia Creative Commons" style="border-width:0" src="https://i.creativecommons.org/l/by-nc/4.0/88x31.png" /></a><br />Esta obra está bajo una <a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/">Licencia Creative Commons Atribución-NoComercial 4.0 Internacional</a>.
