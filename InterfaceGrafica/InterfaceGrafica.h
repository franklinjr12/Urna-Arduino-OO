/* Desenvolvido por Lucas Oliveira */
#include "Arduino.h"
#include <LiquidCrystal.h>

/* CLASSE INTERFACE GRAFICA */
class InterfaceGrafica{

	private:

	LiquidCrystal *lcd;
	
	public:

    void criaMensagem(int linha, int coluna, int delay, char* mensagem);
    
    void mensagemDisplay(char *msg);
    void mensagemDisplaySemEspera(char *msg);

    //GET E SET LCD

    //construtor com tela display
    void setLCD(int *p1, int *p2, int *p3, int *p4, int *p5, int *p6);
    LiquidCrystal* getLCD();
};

//classe para display de 16x2 
class DisplayLCD16x2 : public InterfaceGrafica{
	//construtor padrão
public:
	DisplayLCD16x2(int *p1, int *p2,int *p3, int *p4,int *p5, int *p6){
		setLCD(p1,p2,p3,p4,p5,p6);
	}
};
