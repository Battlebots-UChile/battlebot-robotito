
# Robotito
Robotito es un battlebot de un taller  universitario que combina conocimientos de electrica , mecánica y programación,bajo un acorazado de metal giratorio.

<Insertar una imagen del proyecto terminado, de vista general, como el que aparece abajo>

![Modelo inicial](/multimedia/robot_ejemplo.png)



## Integrantes
- Leslie Cárdenas - FCFM
- Tomás Ceballos - FCFM
- Francisca Guiñez - FCFM
- Keyla Sandoval - FCFM


## Descripción del proyecto

Un robot controlado a traves de una aplicación celular (App-Inventor) conectado vía bluetooth para mandar instrucciones al arduino hc06 quien controla los moteres del sistema de avance y giratorio del acorazado.

El funcionamiento general se basa en dos motores reductores  encargados de las ruedas del battlebot y un motor DC de 2500 rpm conectado al casco atravez de una pieza impresa en 3D que se mostrará en el extenso del documento.Cabe destacar que cada motor tiene su propio puente H ;todo alimentado por dos baterias lipo.

### Estrategia utilizada
Elegimos este diseño como un modo de unir defensa y ataque; según nuestra hipótesis la velocidad del objeto iba a ser tanta que cualquier intento por detenerlo o atacarlo directamente iba a resultar en el battlebot empujado o incluso podría quemar el sistema de ataque  dada a la alta cantidad de amperaje necesario para detner el giro de la caracasa.

A su vez elegimos una caracasa de acero (que anteriormente era un bool) lo que bloqueo todos los intentos de corte o golpes.
#### Ofensiva
Como dijimos anteriormente nuestro modelo en sí mismo era una arma, pero aún así pensamos integrar un complemento a la carcasa en la zona mas baja de la misma, dicha estructura hecha de placa MDF consta de un anillo con tres protuberancias que dada a su ubicacion pasarían por debajo de los distintos robots levantandolo usando solo la velocidad y fuerza del motor conectado al casco.

#### Defensiva
El casco era nuestra defensa, la cual resulto ser muy efectiva , ya que en la batalla solo lograron raspar la superficie, e inclusive ni siquiera fuimos empujados.


### Diagrama funcional
<Diagrama general de funcionamiento. Se sugiere un esquema de sistemas, completo.>

### *BONUS*: Paso a Paso
<Explicar brevemente el paso a paso de cómo construir el battlebot.>

### Sobre la app

![Tabla Explicativa](/multimedia/tabla_botones.png)

## Licencia
<a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/"><img alt="Licencia Creative Commons" style="border-width:0" src="https://i.creativecommons.org/l/by-nc/4.0/88x31.png" /></a><br />Esta obra está bajo una <a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/">Licencia Creative Commons Atribución-NoComercial 4.0 Internacional</a>.
