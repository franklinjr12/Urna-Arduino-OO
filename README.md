# Urna Eletrônica com Arduino e Programação C++ OO
Urna eletrônica simples feita em plataforma de desenvolvimento arduino com programação orientada a objetos.


## Começando

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Pré-requisitos

Lista do que será necessário para a execução do projeto

```
Hardware:
- Arduino UNO;
- Protoboard;
- Display LCD 16x2;
- Resistores;
- Teclado Numérico;
- Buzzer.

Software:
- Thinkercad Online Circuit Simulator;
- Arduino IDE Software;
- IDE p/ C++.
```

### Instalação

A step by step series of examples that tell you have to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Desenvolvimento

Explain how to run the automated tests for this system

### CORE

Explain what these tests test and why

```
Give an example
```

### DATABASE

Explain what these tests test and why

```
Give an example
```

### INTERFACE GRAFICA

Para começar, acrescente a biblioteca do Display LCD no header do seu código e defina os pinos que serão utilizados no Arduino

```
#include <LiquidCrystal.h>
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
```

A estrutura do método criaMensagem está definida abaixo:

```
criaMensagem(int linha, int coluna, int tempoDespera, char* mensagem);
Linha: 0 - primeira linha do display, 1 - segunda linha do display(por padrão já esta em 0);
Coluna: As colunas variam entre 0 - 15 colunas;
Tempo de Espera: O tempo é em milisegundos;
Mensagem: Crie uma váriavel do tipo char com a sua mensagem;
```


Para utilizar os métodos da classe basta criar um ponteiro para a mesma, passar um texto no formato char e chamar o método criaMensagem();
```
InterfaceGrafica p1;//instancia um ponteiro para a classe interfaceGrafica
char msg1[] = "Lucas de Oliveira Pereira";//cria uma variavel com a mensagem
p1.criaMensagem(0,0,1000,msg1);//instancia o metodo criarmensagem
```
Se um texto conter mais de 16 colunas, ele será quebrado aonde ultrapassou para ser mostrado em outra linha.


### INTERFACE TECLADO

Explain what these tests test and why

```
Give an example
```


## Ferramentas utilizadas

* [Arduino IDE](https://www.arduino.cc/en/Main/Software) - Arduino IDE
* [Code::Blocks](http://www.codeblocks.org/downloads) - Code::Blocks - IDE C/C++ 
* [Sublime Text](https://www.sublimetext.com/) - Sublime Text
* [Thinkercad](http://www.tinkercad.com/) - Web Circuit Simulator

## Contribuição

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Autores

* **Lucas de Oliveira Pereira** - *Interface Gráfica* - [Lucas Oliveira](https://github.com/lucsoliveira)

Veja a lista completa [neste link](https://github.com/franklinjr12/Urna-Arduino-OO/graphs/contributors) dos contribuidores que participam nesse projeto.

## Licença

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
