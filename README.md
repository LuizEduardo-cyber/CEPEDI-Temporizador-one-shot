# Projeto Temporizador de apenas um disparo (one-shot) 🚀

Este projeto faz com que ascenda os 3 LED(vermeljo,verde e amarelo) em apenas um disparo ao apertar no pushbutton, e logo em seguida vai alternando o sinal de cada LED periodicamente. 
## Hardware 🛠️

- Microcontrolador RP2040 (Raspberry Pi Pico).
- PushButton.
- Resistores.
- 3 LEDs.

## Software 💻

* **SDK do Raspberry Pi Pico:** O SDK (Software Development Kit) do Pico, que inclui as bibliotecas e ferramentas necessárias para desenvolver e compilar o código. [Instruções de instalação](https://www.raspberrypi.com/documentation/pico/getting-started/)
* **CMake:** Um sistema de construção multiplataforma usado para gerar os arquivos de construção do projeto.
* **Compilador C/C++:**  Um compilador C/C++ como o GCC (GNU Compiler Collection).
* **Git:** (Opcional) Para clonar o repositório do projeto.


### O código está dividido em vários arquivos para melhor organização:

- **`Temporizador_one_Shot.C`**: Código com a função de loop principal: gera o código que faz com que ascenda os leds em apenas um disparo e desligue os leds periodicamente.
- **`CMakeLists.txt`:** Define a estrutura do projeto para o CMake.
- **`diagram.json`:** projeta a simulação do semaforo.
- **`wokwi.toml`:** configuração para sicronizar o código a simulação.




## Como Compilar e Executar ⚙️

1. **Instale o SDK do Raspberry Pi Pico:** Siga as instruções no site oficial do Raspberry Pi.
2. **Clone este repositório:** `https://github.com/LuizEduardo-cyber/CEPEDI-Temporizador-one-shot.git`
3. **Navegue até o diretório do projeto:** `cd CEPEDI-Temporizador-one-shot`
4. **Compile o projeto:** `cmake -B build && cmake --build build`
5. **Copie para o Pico:** Copie o conteúdo da pasta `build` (gerada após a compilação) para o Raspberry Pi Pico. O programa iniciará automaticamente.


## Funcionamento do Loop Principal 🔄 
```
     while (true) {
         if (gpio_get(BUTTON) == 0 && !led_active) {
            sleep_ms(50);

            if (gpio_get(BUTTON) == 0 && gpio_get(LED_RED)==0 && gpio_get(LED_BLUE)==0 && gpio_get(LED_GREEN)==0) {
                sleep_ms(1000);
                gpio_put(LED_RED, true);
                gpio_put(LED_BLUE,true);
                gpio_put(LED_GREEN,true);


                led_active = true;
                add_alarm_in_ms(1000, turn_off_callback, NULL, false);
                add_alarm_in_ms(4000, turn_off_callback2, NULL, false);
                add_alarm_in_ms(7000, turn_off_callback3, NULL, false);
 
            }
           
        }
    
    sleep_ms(10);

  ```
O loop while (true) garante execução contínua. A primeira condição IF tem como objetivo fazer o debounce que faz controle de corrente ao clicar no pushbutton. A segunda condição serve para chamar as interrupções apenas qyuando clicar no pushbutton e todos os Leds estiverem desligados.led_active = true é para indicar que os Leds vao ligar. add_alarm_in_ms interrupção que chama uma função e dispara em um tempo definido. sleep_ms(10) para apos 10 milisegundos voltar ao inicio do loop.

## Funcionamento da interrupção.
```
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
 
        gpio_put(LED_BLUE,false);
     
    led_active = false;

    return 0;
}
int64_t turn_off_callback2(alarm_id_t id, void *user_data) {
 
        gpio_put(LED_RED,false);
     
    led_active = false;

    return 0;
}
int64_t turn_off_callback3(alarm_id_t id, void *user_data) {
 
        gpio_put(LED_GREEN,false);
     
    led_active = false;

    return 0;
}


  ```
as funções turn_off_callback, turn_off_callback2 e turn_off_callback3 são interrupções que tem como função desligar cada Led e retornar um valor.

## Diagrama de Conexões 💡:

https://drive.google.com/file/d/1MEYWebIbpzQ6gUQRP9w9c6Tk-MA6CKln/view?usp=drive_link

## Próximos Passos ➡️

- Fazer um semaforo que indique um tempo mais adequado para os acionamento de cada led.
- implementar condições mais complexas para que se encaixe mais na realidade..
  
 ## 🔗 Link do Vídeo de Funcionamento:
 

 ## Contribuições 🤝

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.
