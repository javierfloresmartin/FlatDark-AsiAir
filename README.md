# FlatDark-AsiAir
Automatic Dark Flat for AsiAir. Built in Arduino and no drivers are necesary.

# Componentes.
* Arduino (Uno, nano, mega)
* StepDown or MB102
* Servo (RDS3115mg)
* Panel de Flats electroluminiscente de 200mm (Aliexpress)
* AsiAir

# Piezas para imprimir
Aquí podeis encontrar las piezas que he usado para la tapa.
https://www.thingiverse.com/thing:6787381

# Conexiones y funcionamiento.
El funcionamiento es sencillo, lo primero es conectar el servo a 5V y a GND en la placa del Arduino.

Luego necesitamos hacer una conexión desde los 12 voltios que sacamos del AsiAir hasta un pin del Arduino (PIN2) que va a detectar ésta corriente y abrirá la tapa o la cerrará dependiendo si le llega o no corriente. 

Por último conectamos otra salida del AsiAir a la fuente de alimentación del panel electroluminiscente de 12V y configuramos dicha salida como Flat Panel para poder tener un control sobre el voltaje que pasará al panel. Esto puede hacer que el panel parpade debido a la frecuencia modulada (PWM) del AsiAir. Quizá con un filtro paso bajo (resistencia + condensador) se pueda arreglar pero de momento no está implementado. 

# Video demostrativo.
[![Alt text](https://img.youtube.com/vi/3RFAX3CbSGA/0.jpg)](https://www.youtube.com/watch?v=sVqIuz2ImRY)

