#include "utils/commandline.h"
#include "stm32f4_discovery.h"
extern CommandLine cmdline;
extern int estado;

uint16_t cmd_leds(uint16_t argc, uint8_t *argv8[]){
	const char **argv=(const char **)argv8;
	uint16_t size=0;
	char* buffer=(char*)argv[0];

	// Esse comentado faz com que alterna entre piscar ou nao apenas com comando "pisca"
	//if(argc==1){
	//	size+=sprintf(buffer+size, "USB do Zimmermann\r\n");
	//	estado = estado^1; //esse xor faz com que alterne entre 0 e 1 cada vez que o comando é enviado
	//}

	if(argc==1){
			size+=sprintf(buffer+size, "USB do Zimmermann, liga/desliga todos os LEDs\r\n");
			estado = 0;
			//acende ou apaga todos quando fala apenas "led"
			STM_EVAL_LEDToggle(LED3);
			STM_EVAL_LEDToggle(LED4);
			STM_EVAL_LEDToggle(LED5);
			STM_EVAL_LEDToggle(LED6);
		}
	else if(argc==2){

			int complemento= atoi((char*)argv8[1]); //complemento recebera o codigo correspondente à segunda palavra lida
			estado = 0;
			size+=sprintf(buffer+size, "USB do Zimmermann, controles extras\r\n");
			if (complemento == atoi((char*)'pisca')) //faz os LEDs girarem até que mande "led para"
			{
				size+=sprintf(buffer+size, "PISCANDO TUDO\r\n");
				estado = 1;
			}

	else if (complemento == 3)
	{
		size+=sprintf(buffer+size, "Toggle no 3\r\n");
		STM_EVAL_LEDToggle(LED3);
	}
	else if (complemento == 4)
		{
		size+=sprintf(buffer+size, "Toggle no 4\r\n");
			STM_EVAL_LEDToggle(LED4);
		}
	else if (complemento == 5)
		{
		size+=sprintf(buffer+size, "Toggle no 5\r\n");
			STM_EVAL_LEDToggle(LED5);
		}
	else if (complemento == 6)
		{
		size+=sprintf(buffer+size, "Toggle no 6\r\n");
			STM_EVAL_LEDToggle(LED6);
		}
	else
	{
		size+=sprintf(buffer+size, "Complemento invalido\r\n");
	}

	}
	else
			{
		size+=sprintf(buffer+size, "Sintaxe: led complemento\r\n");
	}

	return size;
}



CommandLine cmdline({"led"},
					{cmd_leds});

