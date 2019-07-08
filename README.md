
# Robotito
Robotito es un battlebot realizado en el taller de proyecto "Contruye tu battlebot", el cuál combina conocimientos de electrónica, mecánica y programación, bajo un acorazado de metal giratorio.
### ![Desde arriba](/multimedia/desdearriba.png)
### ![Desde el lado](/multimedia/desdeellado.png)
### ![Exterior](/multimedia/robotito2.jpeg)


## Integrantes
- Leslie Cárdenas - FCFM
- Tomás Ceballos - FCFM
- Francisca Guiñez - FCFM
- Keyla Sandoval - FCFM


## Descripción del proyecto

Robotito es un robot, pero no cualquier tipo de robot, NOOO... es un BATTLEBOT (por si no quedo claro en los títulos), controlado mediante una aplicación celular (App-Inventor), cuyo objetivo en la vida es detener todos los golpes que intenten destruirlo.

Funciona en base a dos motores DC básicos, uno conectado a cada rueda, y un motor DC de 2500 rpm conectado a un bowl de cocina, a través de una pieza impresa en 3D. Cuenta con dos puentes H, uno dual y uno single, y es alimentado por dos baterias LiPo.

### Descripción morfológica
La forma elegida para nuestro robot surgio pensar en cual seria la más óptima defensivamente. Por esto nos inclinamos por utilizar un bowl. Pensamos que, por un lado, su forma semiesférica iba a imposibilitar cualquier intento de agarrarlo. Además, al estar hecho de acero inoxidable claramente iba a ser poco probable que le produjeran daños graves.
Cabe decir que antes de tomar una desicion realizamos una exhaustiva investigacion en Youtube sobre battlebots alrededor del mundo.

### Estrategia utilizada

Elegimos este diseño como un modo de unir defensa y ataque. Según nuestra hipótesis la velocidad del objeto iba a ser tanta que cualquier intento por detenerlo o atacarlo directamente iba a resultar en el battlebot enemigo siendo empujado, o en el mejor de los casos podría detener su sistema de ataque, dada a la alta cantidad de potencia necesaria para detener el giro del bowl.

La mejor manera de ganar es evitar golpes laterales; nos referimos a golpes contundentes con un objeto cuyo borde sea masivo, por ejemplo una barra de metal;esto es porque al golpear de manera lateral raya el casco provocando su desgaste y a largo plazo puede provocar abolladuras.

#### Defensiva
El bowl es nuestra principal y evidente, pero no única, defensa. Es de acero inoxidable. Proviene directamente de la cocina de una de las integrantes de nuestro grupo :).
Pero como un pedazo de metal no puede con todo (¿o si?), para detener los posibles ataques a ras de suelo (ya que el bowl deja un par de centímetros al descubierto), nuestro battlebot cuenta con lo que denominamos una "falda", cortada con laser en MDF de 6mm.
Además, cabe decir que la forma circular o media esférica conseguida también ayuda a que los golpes no lleguen de forma directa.

Nuestro principal recurso es el giro, al atacar, hacerlo de costado si es que el contricante presenta algún tipo de arma  y tratar de interponerse en su movimiento de forma permante; un motor DC convencional no soporta la subida extrema de amperaje debido a la resistencia presentada, lo que provoca que se quemen o bien detengan su función momentáneamente, momento propicio para empujarlos y botarlos de la plataforma.
Las debilidades son mas bien de control, al ser un casco esférico si no se coloca una distinción no se puede saber donde esta el frente por lo que es dificil maniobrar.

#### Ofensiva
Como dijimos anteriormente nuestro modelo en sí mismo es una arma, pero aún así pensamos integrar un complemento a la carcasa en la zona mas baja de la misma, dicha estructura hecha de placa MDF consta de un anillo con tres protuberancias que dada a su ubicacion pasarían por debajo de los distintos robots levantandolo usando solo la velocidad y fuerza del motor conectado al casco.

### Descripcion control
<img src="tabla_botones.png" width="320" height="550">

### Diagrama funcional
<Diagrama general de funcionamiento. Se sugiere un esquema de sistemas, completo.>

###  Paso a Paso

#### Materiales:
- 1 Arduino Nano
- 1 Bowl de acero inoxidable
- 1 Rueda loca
- 2 Motores reductores con ruedas
- 1 Puente H BTS7960
- 1 Puente H dual L298n
- 2 Baterías Li-Po de 7.4V
- 1 Ventilador de 3x3cm
- 3 Ruedas de 20mm
- 4 Separadores hexagonales de 50mm*
- 20 cm de Velcro

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
- Limas metálicas

#### Opcionales:
- Alarma para Li-Po
- Cargador de Li-Po

* o alguna combinación que resulte en esa altura
#### Instrucciones

1. Imprimir las piezas en 3d, desde [aquí](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/planos/Piezas%203d), y lijar para eliminar imperfecciones.
2. Cortar las dos bases para el robot (Archivo: [Bases](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/planos/Bases)) y quitar imperfecciones.
3. 

Para empezar el arduino va conectado a dos puentes H; el primero llamado BTS7960 43A,tiene la peculiaridad de soportar 43 amperes de corriente continua lo que fue ideal para nuestro gran motor DC el cual con los constantes golpes tenia que ejercer una gran fuerza para no detenerse por lo que consumía mucho amperaje;tuvimos cuidado de elegir el puente H correcto ya que si este no soportaba podría quemarse y con el todo el circuito relacionado a ese motor, aún así por precaución lo ubicamos sobre una carcasa hecha en la impresora 3D que contenía un ventilador conectado directamente a una  Lipo ,dicho puente tenía dos entradas conectadas a la bateria y dos salidas conectadas al motor bélico (así denominados al motor DC desconocido)
![ ](/multimedia/rueda.jpeg)

### Problema - Solución
1- Conexiones sueltas.
Inicialmente teniamos muchas conexiones que estaban agarradas mediante cinta aislante. Pero llegó un punto en el desarrollo del robot donde esto no era eficiente, ya que, debido a la gran cantidad de cables y componentes, estas se soltaban regularmente y entorpecia el avance.
Solucion: Aprender a soldar. Soldar "todo".
Aclaracion: "Todo": Todo lo que estaba mas o menos fijo (referido a: Si, este cable va con este hasta el fin de los tiempos) y obviamente funcional.

2- el motor tendía a rodar ligeramente sobre si mismo por lo que toda la fuerza de rotación no se centraba en el bowl, para ello se le creo una pieza en la impresora 3D que se apernaba a la base manteniendlo quieto.

3-La gran cantidad de amperaje quemo nuestro puente H inicial el VNH2SP30 por lo que lo reemplazamos por uno que aguantara 43 amperes de corriente continua
4- Cables rozando con el bowl

5- Baterias no daban tanta corriente como se necesitaba

6- Espacio.

7- Baterias que deben ser recargadas
### Proyecciones a futuro
Dado al satisfactorio resultado de la competencia, cuyos video se puede ver en (https://drive.google.com/drive/folders/1BpDF191vPP6yp6vsLNgYQf0TWKebsp2z) nuestras modificaciones son meramente opcionales y de ser quisquillosos.
La primera es cambiar el metodo de manejo, es decir, en vez de usar la App pensamos en cambiarlo para utilizar un joystick lo que obviamente implicaría cambiar los códigos los que serán agregados una vez hecha la modificación.
#### ![Joystick con arduino](/multimedia/arduino-joystick.png)

La otra modificación es agregar un especie de cinturon al casco con 3 protuberancias ubicadas en la parte inferior del mismo, la idea surgió de la observación en batalla ,nos percatamos que casi todos los golpes son efectuados en la parte inferior del acorazado por lo tanto pensamos agregar esta estructura que pasará debajo de los robots(pensado en los modelos con los que ya peleamos) y los levatará con la velocidad del giro. Obviamente una vez lista la estructura se subirán los planos correspondientes.


## Licencia
<a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/"><img alt="Licencia Creative Commons" style="border-width:0" src="https://i.creativecommons.org/l/by-nc/4.0/88x31.png" /></a><br />Esta obra está bajo una <a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/">Licencia Creative Commons Atribución-NoComercial 4.0 Internacional</a>.
