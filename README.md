
# Robotito
Robotito es un robot de pelea del taller de proyecto universitario "Construye tu battlebot"  del presente año 2019  que combina conocimientos de electrica , mecánica y programación,bajo un acorazado de metal giratorio.
Sus partes generales son:

### ![ Piso inferior](/multimedia/robotito2.jpeg)
### ![Piso superior](/)

### ![Exterior](/multimedia/robotito1.jpeg)


## Integrantes
- Leslie Cárdenas - FCFM
- Tomás Ceballos - FCFM
- Francisca Guiñez - FCFM
- Keyla Sandoval - FCFM


## Descripción del proyecto

El robot es controlado a través de una aplicación celular (App-Inventor) conectado vía bluetooth  para mandar instrucciones al arduino hc06 quien controla los motores del sistema de avance y giratorio del acorazado.

El funcionamiento general se basa en dos motores reductores (yellow motors DC)  encargados de las ruedas del battlebot y un motor DC de 2500 rpm conectado al casco a través de una pieza impresa en 3D que se mostrará en el extenso del documento.Cabe destacar que cada motor tiene su propio puente H ;todo alimentado por dos baterias lipo.

El modelo es similiar al de un OVNI ya que apostamos que la velocidad evitaría que nos atraparan y haría difícil acercarse sin ser expulsados lejos debido a la aceleración además el material elegido es un acero que funciona como acorazado lo que nos brinda resistencia.

### Estrategia utilizada
Elegimos este diseño como un modo de unir defensa y ataque; según nuestra hipótesis la velocidad del objeto iba a ser tanta ,que cualquier intento por detenerlo o atacarlo directamente iba a resultar en el battlebot empujado o incluso podría quemar el sistema de ataque dada a la alta cantidad de amperaje necesaria para detner el giro de la caracasa.A su vez elegimos una carcasa de acero (que anteriormente era un bool) lo que bloqueo todos los intentos de corte o golpes contundentes.

La mejor manera de ganar es evitar golpes laterales; nos referimos a golpes contundentes con un objeto cuyo borde sea masivo, por ejemplo una barra de metal;esto es porque al golpear de manera lateral raya el casco provocando su desgaste y a largo plazo puede provocar abolladuras.

### [Daños tipo]()

#### Defensiva
Nuestro principal recurso es el giro , al atacar, hacerlo de costado si es que el contricante presenta algún tipo de arma  y tratar de interponerse en su movimiento de forma permante; un motor DC convencional no soporta la subida extrema de amperaje debido a la resistencia presentada, lo que provoca que se quemen o bien detengan su función momentaneamente, momento propicio para empujarlos y botarlos de la plataforma.
Las debilidades son mas bien de control, al ser un casco esférico si no se coloca una distinción no se puede saber donde esta el frente por lo que es dificil maniobrar.

#### Ofensiva
Como dijimos anteriormente nuestro modelo en sí mismo era una arma, pero aún así pensamos integrar un complemento a la carcasa en la zona mas baja de la misma, dicha estructura hecha de placa MDF consta de un anillo con tres protuberancias que dada a su ubicacion pasarían por debajo de los distintos robots levantandolos usando solo la velocidad y fuerza del motor conectado al casco.


### Diagrama funcional
<Diagrama general de funcionamiento. Se sugiere un esquema de sistemas, completo.>

###  Paso a Paso
#### Materiales:
- Placas MDF (número indefinido)
- 1 bool de hacerlo
- 1 rueda pivote
- 1 par de motores reductores con ruedas
- Cables de arduino hembra-hembra,
  macho-macho,hembra-macho
- Cinta aislante
- Soldadura
- Alicates(varios)
- Pistola de calor
- Impresora 3D
- Cortadora Lasér
- Ventilador de CPU
- Termoretráctil
- Puente H BTS7960
- Puente H L298n
- 2 baterias Lipo
- Alarma de bateria lipo
- Cargadores de lipo
- Rueditas
- Tuercas y tornillos (3mm)
- Cautín
- Dremel
- Arduino nano

Para empezar el arduino va conectado a dos puentes H ;el primero llamado BTS7960 43A,tiene la peculiaridad de soportar 43 amperes de corriente continua lo que fue ideal para nuestro gran motor DC el cual con los constantes golpes tenia que ejercer una gran fuerza para no detenerse para lo cual consumia mucho amperaje;tuvimos cuidado de elegir el puente H correcto ya que si este o soportaba podría quemarse y con el todo el circuito relacionado a ese motor, aún así por precaución lo ubicamos sobre una carcasa hecha en la impresora 3D que contenía un ventilador conectado directamente a una  Lipo ,dicho puente tenía dos entradas conectadas a la bateria y dos salidas conectadas 
![ ](/multimedia/rueda.jpeg)
Luego con ello


### Sobre la app

![Tabla Explicativa](/multimedia/tabla_botones.png)

## Licencia
<a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/"><img alt="Licencia Creative Commons" style="border-width:0" src="https://i.creativecommons.org/l/by-nc/4.0/88x31.png" /></a><br />Esta obra está bajo una <a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/">Licencia Creative Commons Atribución-NoComercial 4.0 Internacional</a>.
