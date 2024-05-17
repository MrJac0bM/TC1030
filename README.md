# TC1030_Proyecto

Este proyecto está diseñado para implementar un sistema de emergencia simulado con diversas autoridades, como policía, bomberos y paramédicos.

### Problema
En situaciones de emergencia, es crucial tener un sistema eficiente para gestionar y coordinar las diferentes autoridades que responden a los incidentes. Este proyecto se centra en la creación de un sistema que simule el funcionamiento de las autoridades de emergencia, permitiendo a cada una de ellas realizar sus funciones específicas, como investigar crímenes, apagar incendios y atender heridos.
### Funcionamiento
El programa permite:

 - Policia:Policía: Investigar crímenes y patrullar áreas designadas.
 - Bomberos: Apagar incendios en lugares específicos.
  -Paramédicos: Atender a los heridos en emergencias médicas.
Funciones generales:
  -alertar_autoridades(): Alertar a las autoridades sobre una emergencia.
  -agregar_autoridades(): Agregar autoridades al sistema.
  -registrar_historial(): Registrar el historial de emergencias.
  -evaluar_nivel(): Evaluar el nivel de la emergencia.
  -finalizar_emergencia(): Finalizar la emergencia y liberar recurso.

 
### Consideraciones
El programa no funcionará correctamente si no se crean objetos de las clases Policia, Bombero y Paramedico. 
Asegúrese de compilar el código con g++ para evitar problemas de compatibilidad.
