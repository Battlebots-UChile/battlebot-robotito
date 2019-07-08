
# Robotito
Robotito fue realizado en el taller de proyecto "Contruye tu battlebot", el cuál combina conocimientos de electrónica, mecánica y programación, bajo un acorazado de metal giratorio.
<img src="https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/multimedia/desdearriba.png" width="600" width="400"/>
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
La forma elegida para nuestro robot surgió de pensar en cual sería la más óptima defensiva. Por esto nos inclinamos por utilizar un bowl. Pensamos que, por un lado, su forma semiesférica iba a imposibilitar cualquier intento de agarrarlo.
Además, al estar hecho de acero inoxidable claramente iba a ser poco probable que le produjeran daños graves.

Cabe decir que antes de tomar una decisión realizamos una exhaustiva investigación en Youtube sobre battlebots alrededor del mundo
### Estrategia utilizada

Elegimos este diseño como un modo de unir defensa y ataque.
Según nuestra hipótesis la velocidad del casco iba a ser tanta que cualquier intento por detenerlo o atacarlo directamente iba a resultar en el battlebot enemigo siendo empujado, o ,en el mejor de los casos dada a la alta cantidad de potencia necesaria para detener el giro del bowl ,podríamos llegar a quemar el sistema que da vida a su arma.
Tomando de ejemplo una experiencia del combate, nuestro contricante tenía una barra de metal que giraba; nuestro robotito solo se interponía en el giro de la barra provocando que se detuviera y automaticamente el motor que daba vida a esa barra comenzaba a presentar problemas por el amperaje .

La mejor manera de ganar es evitar ataques laterales; nos referimos a golpes contundentes con un objeto cuyo borde sea masivo, por ejemplo una barra de metal;esto es porque al golpear de manera lateral raya el casco provocando su desgaste y a largo plazo puede generar abolladuras.

#### Defensiva
El bowl es nuestra principal , pero no única, defensa. Es de acero inoxidable. Proviene directamente de la cocina de una de las integrantes de nuestro grupo :).
Pero como un pedazo de metal no puede con todo (¿o si?), para detener los posibles ataques a ras de suelo (ya que el bowl deja un par de centímetros al descubierto), nuestro battlebot cuenta con lo que denominamos una "falda", cortada con laser en MDF de 6mm.
Además, cabe decir que la forma circular o media esférica conseguida también ayuda a que los golpes no lleguen de forma directa.

Nuestro principal recurso es el giro.

Al atacar, hacerlo de costado si es que el contricante presenta algún tipo de arma  y tratar de interponerse en su movimiento de forma permante; un motor DC convencional no soporta la subida extrema de amperaje debido a la resistencia presentada, lo que provoca que se quemen, o bien detengan su función momentáneamente,  propicio para empujarlos y botarlos de la plataforma.

Las debilidades de robotito son mas bien de control, al ser un casco esférico si no se coloca una distinción no se puede saber donde esta el frente por lo que es difícil maniobrar.

#### Ofensiva
Como dijimos anteriormente nuestro modelo en sí mismo es una arma, pero aún así pensamos integrar un complemento a la carcasa en la zona mas baja de la misma, dicha estructura hecha de placa MDF consta de un anillo con tres protuberancias que dada a su ubicacion pasarían por debajo de los distintos robots levantandolos usando solo la velocidad y fuerza del motor conectado a nuestro casco.

### Descripción control
Robotito tiene su propia app para Android, la cual pueden descargar [aquí](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/codigos/APK).
Al ingresar, se pueden ver 3 secciones:

#### Conexión
Para conectar la app al modulo BT del robot, basta con:
1. Prender el robot (nunca está de más cerciorarse)
2. Activar el Bluetooth del celular
3. Entrar a la app desde el celular
4. Presionar "Buscar dispositivos"
5. Seleccionar el nombre correspondiente al módulo bluetooth (modificable, Google es la luz)
6. Esperar. Cuando la luz del modulo BT deje de parpadear, sera un indicador de que se ha establecido una conexión.

#### Movimiento
<img src="https://github.com/Battlebots-UChile/battlebot-robotito/blob/master/multimedia/tabla_botones.png" width="320" width="550"/>

#### Arma y emergencia
En caso de emergencia de debe presionar el boton STOP. ¿Que hace? Manda un señal que detiene el movimiento de los 3 motores que componen a Robotito de manera instantánea (en cuando la señal sea recibida). No afecta el funcionamiento del ventilador, ya que funciona de manera independiente.
Luego, podemos ver una numeracion de 5 botones, los cuales son las posibles velocidades del arma (se pueden modificar dentro del código .ino, pero no lo sugerimos). En "0" el motor no se mueve. Si se presiona cualquiera que modifique la velocidad actual, el aumento o descenso será paulatino.
#### Otros
La app tambien cuenta con un particular sonido al presionar algunas de las teclas. Fuente: desconocida. Además de la posibilidad de activar la reproducción de la cancion Mr. Roboto, presionando el switch de la parte inferior.
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
- 4 Separadores hexagonales de 50mm (*)
- 20 cm de Velcro
- 2 Conectores hembra HT60 (**)
- 2 Interruptores

- Tuercas y pernos de 3mm
- Cables
- Cables para Arduino
- Placa MDF de 3mm (opcional 6mm)
- Soldadura para electrónica
- Termoretráctil de varias medidas

### Herramientas:
- Alicates varios
- Destornilladores varios
- Pistola de calor o encendedor
- Cautín
- Dremel
- Impresora 3D
- Cortadora Lasér
- Limas metálicas
- Celular Android

### Opcionales:
- Alarma para Li-Po
- Cargador de Li-Po

(*) o alguna combinación que resulte en esa altura.
(**) o del tipo que corresponda, segun el conector de las LiPos.
(***) Deben poder soportar la corriente del motor. Nosotros usamos uno que soportaba 15A.


### Instrucciones

1. Imprimir las piezas en 3d, desde [aquí](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/planos/Piezas%203d), y lijar para eliminar imperfecciones.
2. Cortar las dos bases para el robot, desde [aquí](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/planos/Bases) y quitar imperfecciones.
3. Conectar el Arduino Nano a un PC, y cargar el [codigo](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/codigos/arduino/app_bt).
4. Descargar el [apk](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/codigos/APK) mediante el celular y ejecutar el instalador.
5. Realizar las [conexiones](https://github.com/Battlebots-UChile/battlebot-robotito/tree/master/diagrama).
Como sugerencia, probar los componentes individualmente antes de comenzar a ensamblar todo.


![ ](/multimedia/rueda.jpeg)

## Problema - Solución
1- Conexiones sueltas.
Inicialmente teniamos muchas conexiones que estaban agarradas mediante cinta aislante. Pero llegó un punto en el desarrollo del robot donde esto no era eficiente, ya que, debido a la gran cantidad de cables y componentes, estas se soltaban regularmente y entorpecia el avance.
Solucion: Aprender a soldar. Soldar "todo".
Aclaracion: "Todo": Todo lo que estaba mas o menos fijo (referido a: Si, este cable va con este hasta el fin de los tiempos) y obviamente funcional.

2- el motor tendía a rodar ligeramente sobre si mismo por lo que toda la fuerza de rotación no se centraba en el bowl, para ello se le creo una pieza en la impresora 3D que se apernaba a la base manteniendlo quieto.

3-La gran cantidad de amperaje quemo nuestro puente H inicial el VNH2SP30 por lo que lo reemplazamos por uno que aguantara 43 amperes de corriente continua
4- Cables rozando con el bowl

5- Baterias no daban la corriente necesitada

6- Espacio.

7- Baterias que deben ser recargadas
8. Pines RX y TX

### Proyecciones a futuro
Dado al satisfactorio resultado de la competencia, cuyos video se puede ver en (https://drive.google.com/drive/folders/1BpDF191vPP6yp6vsLNgYQf0TWKebsp2z) nuestras modificaciones son meramente opcionales y de ser quisquillosos.
La primera es cambiar el metodo de manejo, es decir, en vez de usar la App pensamos en cambiarlo para utilizar un joystick lo que obviamente implicaría cambiar los códigos los que serán agregados una vez hecha la modificación.
#### ![Joystick con arduino](/multimedia/arduino-joystick.png)

La otra modificación es agregar un especie de cinturon al casco con 3 protuberancias ubicadas en la parte inferior del mismo, la idea surgió de la observación en batalla ,nos percatamos que casi todos los golpes son efectuados en la parte inferior del acorazado por lo tanto pensamos agregar esta estructura que pasará debajo de los robots(pensado en los modelos con los que ya peleamos) y los levatará con la velocidad del giro. Obviamente una vez lista la estructura se subirán los planos correspondientes.


## Licencia
<a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/"><img alt="Licencia Creative Commons" style="border-width:0" src="https://i.creativecommons.org/l/by-nc/4.0/88x31.png" /></a><br />Esta obra está bajo una <a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/">Licencia Creative Commons Atribución-NoComercial 4.0 Internacional</a>.
