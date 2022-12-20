# Proyecto Final - Videojuego
Proyecto Final de Laboratorio de Microcontroladores
En este proyecto se implementó un videojuego usando 2 PIC18F4550 donde en el primer PIC(U1) contiene la parte visual o gráfica
mientras que en el PIC(U2) contiene la parte auditiva. El videojuego dura 90 segundos, cada 15 segundos aumenta el valor multiplicativo
del 1 al 6. Este valor multiplicatico aumenta la velocidad del juego y de la melodía. El puntaje va aumentando cada segundo dependiendo
de dicho valor multiplicativo, al igual que el "vehículo" cae en un "bache" (obstáculo, hoyo, etc.) se resta el puntaje de dicho valor. 
Al final se presenta el puntaje máximo obtenido.

Para poder realizar este proyecto se usa el ADC del PIC(U1) para poder manipular el "vehículo" hacia arriba y abajo con un potenciómetro,
la parte visual se muestra en un LCD de 16x2. U1 se conecta al U2 mediante el PORTB controlando la velocidad de la melodía enviando una señal.

Las conexiones para hacer la simulación en Proteus se muestran en la imagen "Conexiones en Proteus".

Equipo:
Manuel Amadeo Villarreal González; Anthony Ibrail Ortega Méndez
