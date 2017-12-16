# ED
## Estructura de Datos - 2º Curso

### Prácticas de la asignatura:

Contine la carpeta guiones, con los enunciados de cada una de las
prácticas y una carpeta para cada práctica con los códigos fuente en
C++, scripts en bash, archivos.tex, resultados, documentación, etc. Los 
archivos ya compilados se encuentran en la sección *releases*. Las prácticas 
las he realizado en pareja, junto con [@patriciacorhid](https://github.com/patriciacorhid).

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
usando *Templates*, en la que me he apoyado para estructurar lo antes mencionado. También he documentado el código fuente usando la herramienta ***Doxygen***.
Con ayuda del Makefile, se puede compilar tanto el programa de prueba de la clase como la documentación.

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

La documentación se compila en *HTML*, *LaTeX*, y en *man 3* para linux desde el
Makefile (make documentacion).

La documentación compilada se encuentra en tanto en *HTML* como en *LaTeX* en la
sección *releases*, al igual que el programa de prueba *pruebacronologia*.
*pruebacronologia* lee de la línea de comandos un archivo para leer un objeto
**Cronologia** (hay varios ejemplos de estos en la carpeta datos).

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

En la sección releases están los ejecutables correspondientes del programa de prueba
para las dos versiones, y la documentación en *LaTeX* y en *HTML* ya compiladas.

##### Cuarta práctica: STL e iteradores


#### Retos propuestos por el profesor:

Contiene los enunciados y los asociados de los retos y ejercicios voluntarios
planteados por el profesor. Los archivos ya compilados se encuentran en la 
sección *releases*.
