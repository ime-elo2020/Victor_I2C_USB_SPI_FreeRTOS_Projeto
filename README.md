# Victor_I2C_USB_SPI_FreeRTOS_Projeto

Nesse repositório tem os códigos com o USB, FreeRTOS e no projeto final tem o I2C e o SPI.

--Conceito e Movitação
 
Projeto de firmmware para o microcontrolador STM32F411, que utilizando o acelerômetro e o giroscópio, com os dados recebidos e com
o algoritmo conseguirá detectar o movimento do usuário. A ideia seria criar um app ou dispositivo que avise quando o usuário está 
para chegar na estação do metro, por exemplo. Uma situação seria sair da Afonso Pena e ir para Botafogo, o app avisaria o usuário 
entre o fFlmengo e Botafogo, já que por experiência própria é muito fácil perder a estação e chegar atrasado na aula.

--Diagrama de Blocos 

![alt text](https://github.com/ime-elo2020/Victor_I2C_USB_SPI_FreeRTOS_Projeto/blob/master/Diagrama_de_Blocos_Eletronica.PNG)

--Pinagem

![alt text](https://github.com/ime-elo2020/Victor_I2C_USB_SPI_FreeRTOS_Projeto/blob/master/Pinagem.PNG)

--Configuração dos Periféricos

I2C - LSM303DLHC

ACCESS(RCC_AHB1ENR) |= (1 << 1); // RCC AHB1 peripheral clock enable register nas portas B6 e B9
ACCESS(GPIOB_MODER) |= ((1 << 13) | (1 << 19)); // Configura PB6 e PB9 para função alternativa
ACCESS(GPIOB_AFRL) |= (4 << 24); // Setou os bits 24 - 27 de AFRL com o PB6
ACCESS(GPIOB_AFRH) |= (4 << 4); // Setou os bits 4 - 7 de AFRH com o PB9
ACCESS(GPIOB_OSPEEDR) |= ((2 << 12) | (2 << 18)); // Seta os pinos para modo rápido PB6 e PB9
ACCESS(RCC_APB1ENR) |= (1 << 21); // Habilita o clock no I2C1
ACCESS(I2C1_CR2) &= ~(0x3F);
ACCESS(I2C1_CR2) |= (0x02); // Seta o Clock em 2MHz no  CR2 peripheral clock frequency
ACCESS(I2C1_CCR) &= ~(0xFFF);
ACCESS(I2C1_CCR) |= 0x50; Seta o Clock em 16MHz no  I2C Clock control register
ACCESS(I2C1_TRISE) &= ~(0x3F);
ACCESS(I2C1_TRISE) |= 0x03; Seta o I2C TRISE register em 3
ACCESS(I2C1_OAR1) |= ((0x21 << 1) | (1 << 14)); // Bit 1-7: Interface Address: 100001 = 0x21 e Bit 14:O datasheet fala que o bit 14 sempre tem que estar 1
ACCESS(I2C1_CR1) |= 1; Habilita o I2C1

SPI - L3GD20

ACCESS(RCC_AHB1ENR) |= 1;// RCC AHB1 peripheral clock enable register nas portas A5 a A7
ACCESS(RCC_AHB1ENR) |= (1 << 4);// RCC AHB1 peripheral clock enable register na porta E3
ACCESS(GPIOA_MODER) |= ((1 << 11) | (1 << 13) | (1 << 15)); // Configura PA5 a PA7 para função alternativa
ACCESS(GPIOE_MODER) |= (1 << 6); // Configura PE3 para função alternativa
ACCESS(GPIOA_AFRL) |= ((5 << 20) | (5 << 24) | (5 << 28)); // Setou os bits 20 - 23 com o PA5, 24 - 27 com o PA6 e 28 - 31 com o PA7 de AFRL
ACCESS(GPIOA_OSPEEDR) |= ((2 << 10) | (2 << 12) | (2 << 14));// Seta os pinos para modo rápido PA5 - PA7
ACCESS(GPIOE_OSPEEDR) |= (2 << 6);//Seta o pino para modo rápido PE3
ACCESS(RCC_APB2ENR) |= (1 << 12); Habilita o clock no SPI1
ACCESS(SPI1_CR1) |= (1 | (1 << 1) | (1 << 2) | (2 << 3) | (1 << 8) | (1 << 9)); Configura o SPI1 Control Register
ACCESS(SPI1_CR1) |= (1 << 6); Habilita SPI
ACCESS(GPIOE_BSRR) |= (1 << 3); Seta CS em 1
