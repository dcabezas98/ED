# ED
## Estructura de Datos - 2º Curso

### Prácticas de la asignatura:

Contine la carpeta guiones, con los enunciados de cada una de las
prácticas y una carpeta para cada práctica con los códigos fuente en
C++, scripts en bash, archivos.tex, resultados, documentación, etc. 
La documentación (realizada con la herramienta **Doxygen**) se compila 
en *HTML*, *LaTeX* o en *man 3* para linux desde el Makefile de cada 
práctica (make documentacion).

Las prácticas las he realizado en pareja, junto con [@patriciacorhid](https://github.com/patriciacorhid).

##### Primera práctica: Eficiencia

Análisis de la eficiencia de programas, tanto teórica (con la notación *O*)
como empírica. He aprendido a cronometrar el tiempo de ejecución de un algoritmo
con herramientas de la biblioteca `ctime`. Y a la represetentación de resultados
empíricos usando la herramienta ***gnuplot***. Así como a hallar la curva de 
regresión de los datos con la orden `fit`.

##### Segunda práctica: Abstracción

Implementación de la clase **Cronologia**, para agrupar y ordenar acontecimientos
históricos por años. Un objeto de la clase **Cronologia** contiene una serie de
objetos de la clase **FechaHistorica**, estructurados en un vector dinámico.
Una **FechaHistorica** a su vez contiene un año y una serie de eventos históricos
ocurridos en ese año, agrupados en un vector dinámico de *strings*.
Para la implementación de estos TDA. He montado una clase **VectorDinamico**
usando *Templates*, en la que me he apoyado para estructurar lo antes mencionado.

El programa *pruebacronologia* contiene un ejemplo de uso de la clase en el que
se encuentran funciones para consultar información en las cronologías directamente
de un año o filtrando por un intervalo de años o una cadena de caracteres (se 
crea una subcronología con las fechas históricas que contengan información sobre
Einstein, con las fechas históricas entre 1930 y 1940, etc.). También hay implementado
un método para unir los acontecimientos de dos cronologías, obviamente con las
comprobaciones necesarias para que la cronología resultante tenga sus años
ordenados, no repetidos y dentro de cada año no se archiven hechos repetidos.
Además, están sobrecargados los operadores `>>` y `<<` para leer o escribir
objetos del tipo **Cronologia** a través de un flujo de entrada o salida.

##### Tercera práctica: Estructuras de datos lineales

Implementación de la clase **PilaMax**, que almacena parejas con un entero y el
máximo de todos los valores que están debajo en la pila, de esta forma podemos
acceder con facilidad al máximo de la pila en todo momento.

Hemos implementado esta clase de dos maneras, con dos clases de templates distintas:

- **PilaMax_VD** está implementada a partir de la clase template **VectorDinamico**.
- **PilaMax_Cola** está implementada a partir de la clase template **Cola**.
 
Para compilar una u otra versión, hay que cambiar la variable **CUALCOMPILA** en el
fichero *Pila_max.h*, y ejecutar la orden correspondiente del *Makefile*: **make vd** 
o **make cola**. 

##### Cuarta práctica: STL e iteradores

Implementación de la clase **Cronologia**, esta vez usando herramientas de la **STL**.
Para la representación de la clase **FechaHistorica**, hemos utilizado un *pair\<int, set\<string\>\>*
con el año y el conjunto de acontecimientos ocurridos. Para la clase **Cronologia**,
hemos utilizado un *map\<int, FechaHistorica\>* para almacenar las fechas ordenadas por año.
También hemos definido iteradores para ambas clases a partir de los ya existentes en *set*
y en *map* utilizando **typedef typename**.
Además, hemos incluido diversos programas de prueba para mostrar la funcionalidad de
la clase: consultar estadísticas sobre una Cronología, filtrar una Cronología por un intervalo
de años o por una palabra clave y crear una nueva Cronología como resultado de unir otras dos.

##### Práctica final: Árboles binarios

Se trata de un jugador automático del clásico juego *Quien es quien*, el programa lee
de un fichero un conjunto de personajes y sus atributos y genera un árbol binario con
las distintas preguntas sobre los atributos y coloca los personajes en las hojas. Para 
generar éste árbol el programa busca el cada momento cuál es la pregunta más apropiada
(la que divide al conjunto de personajes en dos grupos lo más similares en tamaño posible),
con el fin de minimizar el número medio de preguntas necesarias para averiguar el personaje.
Incluye también funciones para añadir y eliminar personajes, eliminar las preguntas innecesarias
del árbol y consultar estadísticas sobre la partida como las preguntas hechas hasta el momento
o los personajes que aun están levantados.

El programa incluye un modo para generar tableros con personajes aleatorios, otro para simplemente
cargar un tablero y otro para jugar.

#### Retos propuestos por el profesor

Contiene los enunciados y mis soluciones de los retos y ejercicios voluntarios
planteados por el profesor.

#### Set

Contiene mi resolución del exámen práctico, sobre el tipo *Set* de la **STL**
y un ejercicio de práctica.
