//Solo funciona en sistemas windows

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

struct ficha{
	char matriz[4][4];
};

struct fichas{
	struct ficha arr[19];
	int tope;
};

void imprimirMatriz(char m[36][46], struct fichas bolsa, int fichaActual, int fichaSiguiente, int fichaSiguiente2, int fichaSiguiente3, char record[6], int mover, int caer){
	int i;
	int j;
	int k;
	
	//ficha Actual
	for(i = 0; i < 4; i ++)
		for(j = 0; j < 4; j++)
			if(bolsa.arr[fichaActual-1].matriz[i][j] == '0')
				m[i+caer][j+mover] = '0';
				
	//limpiar fichas siguentes
	for(i = 0; i < 15; i ++)
		for(j = 0; j < 4; j++)
				m[i+4][j+37] = ' ';
	
	//ficha siguiente 1
	for(i = 0; i < 4; i ++)
		for(j = 0; j < 4; j++)
			if(bolsa.arr[fichaSiguiente-1].matriz[i][j] == '0')
				m[i+4][j+37] = '0';
			
	//ficha siguiente 2
	for(i = 0; i < 4; i ++)
		for(j = 0; j < 4; j++)
			if(bolsa.arr[fichaSiguiente2-1].matriz[i][j] == '0')
				m[i+9][j+37] = '0';
				
	//ficha siguiente 3
	for(i = 0; i < 4; i ++)
		for(j = 0; j < 4; j++)
			if(bolsa.arr[fichaSiguiente3-1].matriz[i][j] == '0')
				m[i+14][j+37] = '0';

	//record
	for(j = 0; j < 5; j++){
		m[27][j+37] = record[j];
	}
	
	//imprimir matriz
	/*printf("        *===============================*\n");
	printf("        |***** ***** ***** ****  *  ****|\n");
	printf("        |  *   *       *   *   * * *    |\n");
	printf("        |  *   ***     *   * **  *  *** |\n");
	printf("        |  *   *       *   *  *  *     *|\n");
	printf("        |  *   *****   *   *   * * **** |\n");
	printf("        *===============================*\n\n");
	
	printf("             .      .              .___________.\n");*/

	for(i = 0; i < 36; i++){
		printf("  ");
		for(j = 0; j < 46; j++)
			printf("%c", m[i][j]);

		printf("\n");
	}
	printf("\n\n");
	
	printf("Empezar/Pausa: P    Mover: A-S-D    Rotar: W\n");
}

void limpiarPosicion(char m[36][46], int mover, int caer){
	int i;
	int j;
	for(i = 0; i < 4; i ++)
		for(j = 0; j < 4; j++)
			if(m[i+caer][j+mover] == '0')
				m[i+caer][j+mover] = ' ';
}

void fijarFicha(char m[36][46], int mover, int caer){
	int i;
	int j;
	for(i = 0; i < 4; i ++)
		for(j = 0; j < 4; j++)
			if(m[i+caer][j+mover] == '0')
				m[i+caer][j+mover] = 'O';
}

void inicializarMatriz(char m[36][46]){
	int i;
	int j;
	for(i = 0; i < 36; i++){
		for(j = 0; j < 46; j++){
			if(j == 0 || j == 29 || j == 33 || j == 45){
				if(i == 35)
					m[i][j] = '*';
				else if(i <= 4 && (j == 0 || j == 29))
					m[i][j] = ' ';
				else
					m[i][j] = '|';
			}else if((i == 0 || i == 1 || i == 2 || i == 3 || i == 4) && (j == 11 || j == 18))
				m[i][j] = '|';
			else if(i == 4 && ((j > 0 && j < 12) || (j > 17 && j < 29)))
				m[i][j] = '_';
			else if(i == 2 && j == 36)
				m[i][j] = 'S';
			else if(i == 2 && j == 37)
				m[i][j] = 'i';
			else if(i == 2 && j == 38)
				m[i][j] = 'g';
			else if(i == 2 && j == 39)
				m[i][j] = 'u';
			else if(i == 2 && j == 40)
				m[i][j] = 'e';
			else if(i == 2 && j == 41)
				m[i][j] = ':';
			else if(i == 25 && j == 36)
				m[i][j] = 'R';
			else if(i == 25 && j == 37)
				m[i][j] = 'e';
			else if(i == 25 && j == 38)
				m[i][j] = 'c';
			else if(i == 25 && j == 39)
				m[i][j] = 'o';
			else if(i == 25 && j == 40)
				m[i][j] = 'r';
			else if(i == 25 && j == 41)
				m[i][j] = 'd';
			else if(i == 25 && j == 42)
				m[i][j] = ':';
			else if(i == 35 && j != 30 && j != 31 && j != 32)
				m[i][j] = '-';
			else
				m[i][j] = ' ';
		}
	}
}

void vaciarMatrizFicha(char m[4][4]){
	int i, j;
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			m[i][j] = ' ';
}

void imprimirFicha(struct fichas bolsa, int indice){
	int i, j;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++)
			printf("%c", bolsa.arr[indice].matriz[i][j]);
			
		printf("\n");
	}
}

void cargarFichas(struct fichas *bolsa){
	int i, j;
	struct ficha f;
	
	/*
	  - - - -
	  - 0 0 -
	  - - 0 -
	  - - 0 -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if((j == 1 || j == 2) && i == 1 || j == 2 && (i == 2 || i == 3))
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[0] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	   - - - - 
	   - - - 0 
	   - 0 0 0
	   - - - -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if((j == 1 || j == 2 || j == 3) && i == 2 || j == 3 && i == 1)
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
	  - - 0 -
	  - - 0 -
	  - - 0 0
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j == 2 && (i == 1 || i == 2 || i == 3) || j == 3 && i == 3)
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
	  - - - -
	  -	0 0 0
	  -	0 - -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if((j == 1 || j == 2 || j == 3) && i == 2 || j == 1 && i == 3)
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	 - - - - 
	 - - 0 0 
	 - - 0 - 
	 - - 0 - 
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if((j == 2 || j == 3) && i == 1 || j == 2 && (i == 2 || i == 3))
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
	  -	0 - -
	  -	0 0 0
	  - - - -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if((j == 1 || j == 2 || j == 3) && i == 2 || j == 1 && i == 1)
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
   	  - - 0 -
	  - - 0 -
	  -	0 0 -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j == 2 && (i == 1 || i == 2 || i == 3) || j == 1 && i == 3)
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
	  - - - - 
	  - 0 0 0
	  - - - 0
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if((j == 1 || j == 2 || j == 3) && i == 2 || j == 3 && i == 3)
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
	  - - 0 -
	  -	0 0 0
	  - - - -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j == 2 && (i == 1 || i == 2) || (j == 1 || j == 2 || j == 3) && i == 2)
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
	  - - 0 -
	  - - 0 0
	  -	- 0 -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j == 2 && (i == 1 || i == 2 || i == 3) || (j == 2 || j == 3) && i == 2)
				f.matriz[i][j] = '0';	
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
	  - - - -
	  - 0 0 0
	  - - 0 -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j == 2 && (i == 2 || i == 3) || (j == 1 || j == 2 || j == 3) && i == 2)
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
	  - - 0 -
	  - 0 0 -
	  -	- 0 -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j == 2 && (i == 1 || i == 2 || i == 3) || (j == 1 || j == 2) && i == 2)
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
	  - - - -
	  - - 0 0 
	  - 0 0 - 
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if((j == 2 || j == 3) && i == 2 || (j == 1 || j == 2) && i == 3)
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);

	/*
	  - - - - 
	  -	- 0 -
	  - - 0 0
	  - - - 0 
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j == 2 && (i == 1 || i == 2) || j == 3 && (i == 2 || i == 3))
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
	  - - - -
	  -	0 0 -
	  - - 0 0 
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if((j == 1 || j == 2) && i == 2 || (j == 2 || j == 3) && i == 3)
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
	  -	- 0 -
	  - 0 0 -
	  - 0 - -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j == 1 && (i == 2 || i == 3) || j == 2 && (i == 1 || i == 2))
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - 0 - 
	  - - 0 -
	  - - 0 -
	  - - 0 -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j == 2 && (i == 0 || i == 1 || i == 2 || i == 3))
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
		- - - -
		- - - -
		0 0 0 0
		- - - -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(i == 2 && (j == 0 || j == 1 || j == 2 || j == 3))
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
	/*
	  - - - -
	  -	0 0 -
	  -	0 0 -
	  - - - -
	*/
	bolsa->tope++;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(j == 1 && (i == 1 || i == 2) || j == 2 && (i == 1 || i == 2))
				f.matriz[i][j] = '0';
			else
				f.matriz[i][j] = ' ';
		}
	}
	bolsa->arr[bolsa->tope] = f;
	vaciarMatrizFicha(f.matriz);
	
}

bool contactoParedDerecha(int fichaActual, char m[36][46], int mover, int caer){
	bool toca = false;
	switch(fichaActual){
		case 1:
			if(m[caer+1][mover+3] != ' ' || m[caer+2][mover+3] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 2:
			if(m[caer+1][mover+4] != ' ' || m[caer+2][mover+4] != ' ')
				toca = true;
			break;
			
		case 3:
			if(m[caer+1][mover+3] != ' ' || m[caer+2][mover+3] != ' ' || m[caer+3][mover+4] != ' ')
				toca = true;
			break;
		
		case 4:
			if(m[caer+2][mover+4] != ' ' || m[caer+3][mover+2] != ' ')
				toca = true;
			break;
			
		case 5:
			if(m[caer+1][mover+4] != ' ' || m[caer+2][mover+3] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
		
		case 6:
			if(m[caer+2][mover+4] != ' ')
				toca = true;
			break;
		
		case 7:
			if(m[caer+1][mover+3] != ' ' || m[caer+2][mover+3] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 8:
			if(m[caer+2][mover+4] != ' ' || m[caer+3][mover+4] != ' ')
				toca = true;
			break;
			
		case 9:
			if(m[caer+1][mover+3] != ' ' || m[caer+2][mover+4] != ' ')
				toca = true;
			break;
			
		case 10:
			if(m[caer+1][mover+3] != ' ' || m[caer+2][mover+4] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 11:
			if(m[caer+2][mover+4] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 12:
			if(m[caer+1][mover+3] != ' ' || m[caer+2][mover+3] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 13:
			if(m[caer+2][mover+4] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 14:
			if(m[caer+1][mover+3] != ' ' || m[caer+2][mover+4] != ' ' || m[caer+3][mover+4] != ' ')
				toca = true;
			break;
			
		case 15:
			if(m[caer+2][mover+3] != ' ' || m[caer+3][mover+4] != ' ')
				toca = true;
			break;
			
		case 16:
			if(m[caer+1][mover+3] != ' ' || m[caer+2][mover+3] != ' ' || m[caer+3][mover+2] != ' ')
				toca = true;
			break;
			
		case 17:
			if(m[caer][mover+3] != ' ' || m[caer+1][mover+3] != ' ' || m[caer+2][mover+3] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 18:
			if(m[caer+2][mover+4] != ' ')
				toca = true;
			break;
			
		case 19:
			if(m[caer+1][mover+3] != ' ' || m[caer+2][mover+3] != ' ')
				toca = true;
			break;
			
	}
	return toca;
}

bool contactoParedIzquierda(int fichaActual, char m[36][46], int mover, int caer){
	bool toca = false;
	switch(fichaActual){
		case 1:
			if(m[caer+1][mover] != ' ' || m[caer+2][mover+1] != ' ' || m[caer+3][mover+1] != ' ')
				toca = true;
			break;
			
		case 2:
			if(m[caer+1][mover+2] != ' ' || m[caer+2][mover] != ' ')
				toca = true;
			break;
			
		case 3:
			if(m[caer+3][mover+1] != ' ' || m[caer+1][mover+1] != ' ' || m[caer+2][mover+1] != ' ')
				toca = true;
			break;
		
		case 4:
			if(m[caer+2][mover] != ' ' || m[caer+3][mover] != ' ')
				toca = true;
			break;
			
		case 5:
			if(m[caer+1][mover+1] != ' ' || m[caer+2][mover+1] != ' ' || m[caer+3][mover+1] != ' ')
				toca = true;
			break;
		
		case 6:
			if(m[caer+1][mover] != ' ' && m[caer+2][mover] != ' ')
				toca = true;
			break;
		
		case 7:
			if(m[caer+1][mover+1] != ' ' || m[caer+2][mover+1] != ' ' || m[caer+3][mover] != ' ')
				toca = true;
			break;
			
		case 8:
			if(m[caer+2][mover] != ' ' || m[caer+3][mover+2] != ' ')
				toca = true;
			break;
			
		case 9:
			if(m[caer+1][mover+1] != ' ' || m[caer+2][mover] != ' ')
				toca = true;
			break;
			
		case 10:
			if(m[caer+1][mover+1] != ' ' || m[caer+2][mover+1] != ' ' || m[caer+3][mover+1] != ' ')
				toca = true;
			break;
			
		case 11:
			if(m[caer+2][mover] != ' ' || m[caer+3][mover+1] != ' ')
				toca = true;
			break;
			
		case 12:
			if(m[caer+1][mover+1] != ' ' || m[caer+2][mover] != ' ' || m[caer+3][mover+1] != ' ')
				toca = true;
			break;
			
		case 13:
			if(m[caer+2][mover+1] != ' ' || m[caer+3][mover] != ' ')
				toca = true;
			break;
			
		case 14:
			if(m[caer+1][mover+1] != ' ' || m[caer+2][mover+1] != ' ' || m[caer+3][mover+2] != ' ')
				toca = true;
			break;
			
		case 15:
			if(m[caer+2][mover] != ' ' || m[caer+3][mover+1] != ' ')
				toca = true;
			break;
			
		case 16:
			if(m[caer+1][mover+1] != ' ' || m[caer+2][mover] != ' ' || m[caer+3][mover] != ' ')
				toca = true;
			break;
			
		case 17:
			if(m[caer][mover+1] != ' ' || m[caer+1][mover+1] != ' ' || m[caer+2][mover+1] != ' ' || m[caer+3][mover+1] != ' ')
				toca = true;
			break;
			
		case 18:
			if(m[caer+2][mover-1] != ' ')
				toca = true;
			break;
			
		case 19:
			if(m[caer+1][mover] != ' ' || m[caer+2][mover] != ' ')
				toca = true;
			break;
	}
	return toca;
}

bool contactoPiso(int fichaActual, char m[36][46], int mover, int caer){
	bool toca = false;
	switch(fichaActual){
		case 1:
			if(m[caer+2][mover+1] != ' ' || m[caer+4][mover+2] != ' ')
				toca = true;
			break;
			
		case 2:
			if(m[caer+3][mover+1] != ' ' || m[caer+3][mover+2] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 3:
			if(m[caer+4][mover+2] != ' ' || m[caer+4][mover+3] != ' ')
				toca = true;
			break;
		
		case 4:
			if(m[caer+4][mover+1] != ' ' || m[caer+3][mover+2] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 5:
			if(m[caer+4][mover+2] != ' ' || m[caer+2][mover+3] != ' ')
				toca = true;
			break;
		
		case 6:
			if(m[caer+3][mover+1] != ' ' || m[caer+3][mover+2] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
		
		case 7:
			if(m[caer+4][mover+1] != ' ' || m[caer+4][mover+2] != ' ')
				toca = true;
			break;
			
		case 8:
			if(m[caer+3][mover+1] != ' ' || m[caer+3][mover+2] != ' ' || m[caer+4][mover+3] != ' ')
				toca = true;
			break;
			
		case 9:
			if(m[caer+3][mover+1] != ' ' || m[caer+3][mover+2] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 10:
			if(m[caer+4][mover+2] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 11:
			if(m[caer+3][mover+1] != ' ' || m[caer+4][mover+2] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 12:
			if(m[caer+3][mover+1] != ' ' || m[caer+4][mover+2] != ' ')
				toca = true;
			break;
			
		case 13:
			if(m[caer+4][mover+1] != ' ' || m[caer+4][mover+2] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 14:
			if(m[caer+3][mover+2] != ' ' || m[caer+4][mover+3] != ' ')
				toca = true;
			break;
			
		case 15:
			if(m[caer+3][mover+1] != ' ' || m[caer+4][mover+2] != ' ' || m[caer+4][mover+3] != ' ')
				toca = true;
			break;
			
		case 16:
			if(m[caer+4][mover+1] != ' ' || m[caer+3][mover+2] != ' ')
				toca = true;
			break;
			
		case 17:
			if(m[caer+4][mover+2] != ' ')
				toca = true;
			break;
			
		case 18:
			if(m[caer+3][mover] != ' ' || m[caer+3][mover+1] != ' ' || m[caer+3][mover+2] != ' ' || m[caer+3][mover+3] != ' ')
				toca = true;
			break;
			
		case 19:
			if(m[caer+3][mover+1] != ' ' || m[caer+3][mover+2] != ' ')
				toca = true;
			break;
	}
	return toca;
}

void rotarFicha(int *fichaActual, char m[36][46], int *mover, int *caer){
	switch(*fichaActual){
		case 1:
			if(m[*caer+2][*mover] == ' ' && m[*caer+2][*mover+1] == ' ' && (m[*caer+1][*mover+3] != ' ' || m[*caer+2][*mover+3] != ' ')){
				*fichaActual = 2;
				(*mover)--;
				
			}else if(m[*caer+2][*mover+3] == ' ' && m[*caer+2][*mover+4] == ' ' && m[*caer+1][*mover+4] == ' ' && m[*caer+2][*mover+1] != ' '){
				*fichaActual = 2;
				(*mover)++;
				
			}else if(m[*caer+2][*mover+1] == ' ' && m[*caer+1][*mover+3] == ' ' && m[*caer+2][*mover+3] == ' ')
				*fichaActual = 2;
				
			break;
			
		case 2:
			if(m[*caer][*mover+2] == ' ' && m[*caer+1][*mover+2] == ' ' && (m[*caer+3][*mover+2] != ' ' || m[*caer+3][*mover+3] != ' ')){
				*fichaActual = 3;
				(*caer)--;
				
			}else if(m[*caer+1][*mover+2] == ' ' && m[*caer+3][*mover+2] == ' ' && m[*caer+3][*mover+3] == ' ')
				*fichaActual = 3;
				
			break;
			
		case 3:
			if(m[*caer+2][*mover] == ' ' && m[*caer+2][*mover+1] == ' ' && m[*caer+3][*mover] == ' ' && m[*caer+2][*mover+3] != ' '){
				*fichaActual = 4;
				(*mover)--;
				
			}else if(m[*caer+2][*mover+3] == ' ' && m[*caer+2][*mover+4] == ' ' && (m[*caer+2][*mover+1] != ' ' || m[*caer+3][*mover+1] != ' ')){
				*fichaActual = 4;
				(*mover)++;
				
			}else if(m[*caer+2][*mover+1] == ' ' && m[*caer+3][*mover+1] == ' ' && m[*caer+2][*mover+3] == ' ')
				*fichaActual = 4;
			
			break;
			
		case 4:
			if(m[*caer][*mover+1] == ' ' && m[*caer][*mover+2] == ' ' && m[*caer+1][*mover+2] == ' ' && m[*caer+3][*mover+2] != ' '){
				*fichaActual = 1;
				(*caer)--;
			
			}else if(m[*caer+1][*mover+1] == ' ' && m[*caer+1][*mover+2] == ' ' && m[*caer+3][*mover+2] == ' ')
				*fichaActual = 1;
			
			break;
			
		case 5:
			if(m[*caer+1][*mover] == ' ' && m[*caer+2][*mover] == ' ' && (m[*caer+2][*mover+1] == ' ' && m[*caer+2][*mover+3] != ' ')){
				*fichaActual = 6;
			
				(*mover)--;
			}else if(m[*caer+2][*mover+3] == ' ' && m[*caer+2][*mover+4] == ' ' && (m[*caer+1][*mover+1] != ' ' || m[*caer+2][*mover+1] != ' ')){
				*fichaActual = 6;
				(*mover)++;
			
			}else if(m[*caer+1][*mover+1] == ' ' && m[*caer+2][*mover+2] == ' ' && m[*caer+2][*mover+3] == ' ')
				*fichaActual = 6;
			
			break;
			
		case 6:
			if(m[*caer][*mover+2] == ' ' && m[*caer+1][*mover+2] == ' ' && (m[*caer+3][*mover+1] != ' ' || m[*caer+3][*mover+2] != ' ')){
				*fichaActual = 7;
				(*caer)--;
			
			}else if(m[*caer+1][*mover+2] == ' ' && m[*caer+3][*mover+1] == ' ' && m[*caer+3][*mover+2] == ' ')
				*fichaActual = 7;
			
			break;
			
		case 7:
			if(m[*caer+2][*mover] == ' ' && m[*caer+2][*mover+1] == ' ' && (m[*caer+2][*mover+3] != ' ' || m[*caer+3][*mover+3] != ' ')){
				*fichaActual = 8;
				(*mover)--;
			
			}else if(m[*caer+2][*mover+3] == ' ' && m[*caer+2][*mover+4] == ' ' && m[*caer+3][*mover+4] == ' ' && m[*caer+2][*mover+1] != ' '){
				*fichaActual = 8;
				(*mover)++;
			
			}else if(m[*caer+2][*mover+1] == ' ' && m[*caer+2][*mover+3] == ' ' && m[*caer+3][*mover+3] == ' ')
				*fichaActual = 8;
			
			break;
			
		case 8:
			if(m[*caer][*mover+2] == ' ' && m[*caer][*mover+3] == ' ' && m[*caer+1][*mover+2] == ' ' && m[*caer+3][*mover+2] != ' '){
				*fichaActual = 5;
				(*caer)--;
			
			}else if(m[*caer+1][*mover+2] == ' ' && m[*caer+1][*mover+3] == ' ' && m[*caer+3][*mover+2] == ' ')
				*fichaActual = 5;
			
			break;
			
		case 9:
			if(m[*caer][*mover+2] == ' ' && m[*caer+2][*mover+3] == ' ' && m[*caer+3][*mover+2] != ' '){
				*fichaActual = 10;
				(*caer)--;
			
			}else if(m[*caer+3][*mover+2] == ' ')
				*fichaActual = 10;
			
			break;
			
		case 10:
			if(m[*caer+1][*mover+3] == ' ' && m[*caer+2][*mover+4] == ' ' && m[*caer+2][*mover+1] != ' '){
				*fichaActual = 11;
				(*mover)++;
			
			}else if(m[*caer+2][*mover+1] == ' ')
				*fichaActual = 11;
			
			break;
			
		case 11:
			if(m[*caer+1][*mover+2] == ' ')
				*fichaActual = 12;
			
			break;
			
		case 12:
			if(m[*caer+2][*mover] == ' ' && m[*caer+1][*mover+1] == ' ' && m[*caer+2][*mover+3] != ' '){
				*fichaActual = 9;
				(*mover)--;
			
			}else if(m[*caer+2][*mover+3] == ' ')
				*fichaActual = 9;
			
			break;
			
		case 13:
			if(m[*caer+1][*mover+1] == ' ' && m[*caer+2][*mover+1] == ' ' && m[*caer+3][*mover+3] != ' '){
				*fichaActual = 14;
				(*mover)--;
			
			}else if(m[*caer+1][*mover+2] == ' ' && m[*caer+3][*mover+3] == ' ')
				*fichaActual = 14;
			
			break;
			
		case 14:
			if(m[*caer+1][*mover+3] == ' ' && m[*caer+1][*mover+4] == ' ' && m[*caer+2][*mover+1] != ' ' && m[*caer+3][*mover+2] != ' '){
				*fichaActual = 13;
				(*mover)++;
				(*caer)--;
			
			}else if(m[*caer+3][*mover+2] == ' ' && m[*caer+2][*mover+4] == ' ' && m[*caer+3][*mover+1] != ' '){
				*fichaActual = 13;
				(*mover)++;
			
			}else if(m[*caer+1][*mover+3] == ' ' && m[*caer+1][*mover+4] == ' ' && m[*caer+3][*mover+2] != ' '){
				*fichaActual = 13;
				(*caer)--;
			
			}else if(m[*caer+3][*mover+1] == ' ' && m[*caer+3][*mover+2] == ' ')
				*fichaActual = 13;
			
			break;
			
		case 15:
			if(m[*caer+1][*mover+3] == ' ' && m[*caer+2][*mover+3] == ' ' && m[*caer+3][*mover+1] != ' '){
				*fichaActual = 16;
				(*mover)++;
			
			}else if(m[*caer+3][*mover+1] == ' ' && m[*caer+1][*mover+2] == ' ')
				*fichaActual = 16;
			
			break;
			
		case 16:
			if(m[*caer+1][*mover] == ' ' && m[*caer+1][*mover+1] == ' ' && m[*caer+2][*mover+3] != ' ' && m[*caer+3][*mover+2] != ' '){
				*fichaActual = 15;
				(*mover)--;
				(*caer)--;
			
			}else if(m[*caer+2][*mover] == ' ' && m[*caer+3][*mover+2] == ' ' && m[*caer+3][*mover+3] != ' '){
				*fichaActual = 15;
				(*mover)--;
			
			}else if(m[*caer+1][*mover] == ' ' && m[*caer+1][*mover+1] == ' ' && m[*caer+3][*mover+2] != ' '){
				*fichaActual = 15;
				(*caer)--;
			
			}else if(m[*caer+3][*mover+2] == ' ' && m[*caer+3][*mover+3] == ' ')
				*fichaActual = 15;
			
			break;
			
		case 17:
			if(m[*caer+2][*mover-1] == ' ' && m[*caer+2][*mover] == ' ' && m[*caer+2][*mover+1] == ' ' && m[*caer+2][*mover+3] != ' '){
				*fichaActual = 18;
				(*mover)--;
			
			}else if(m[*caer+2][*mover+3] == ' ' && m[*caer+2][*mover+4] == ' ' && m[*caer+2][*mover+5] == ' ' && m[*caer+2][*mover+1] != ' '){
				*fichaActual = 18;
				(*mover)+= 2;
			
			}else if(m[*caer+2][*mover+1] == ' ' && m[*caer+2][*mover+3] == ' ' && m[*caer+2][*mover+4] == ' ' && m[*caer+2][*mover] != ' '){
				*fichaActual = 18;
				(*mover)++;
				
			}else if(m[*caer+2][*mover] == ' ' && m[*caer+2][*mover+1] == ' ' && m[*caer+2][*mover+3] == ' ')
				*fichaActual = 18;
			
			break;
			
		case 18:
			if(m[*caer-1][*mover+2] == ' ' && m[*caer][*mover+2] == ' ' && m[*caer+1][*mover+2] == ' ' && m[*caer+3][*mover+2] != ' '){
				*fichaActual = 17;
				(*caer)--;
			
			}else if(m[*caer][*mover+2] == ' ' && m[*caer+1][*mover+2] == ' ' && m[*caer+3][*mover+2] == ' ')
				*fichaActual = 17;
			
			break;
	}
}

void romperLinea(char m[36][46], char record[6], int *velocidad, int *vel2, int *velFlag, int *velFlag2){
	int i;
	int j;
	int k;
	int l;
	int combo = 0;
	int res = 0;
	
	j = 10000;
	for(i = 0; i < 5; i++){
		res += ((int)record[i] - (int)'0') * j;
		j /= 10;
	}

	for(i = 6; i < 36; i++){
		j = 1;
		while(m[i][j] == 'O')
			j++;

		if(j == 29){
			j = 1;
			while(m[i][j] == 'O'){
				m[i][j] = ' ';
				j++;
			}
			combo++;
			k = 0;
			l = 1;
			while(i-l > 4){
				j = 1;
				while(j != 29){
					m[i-k][j] = m[i-l][j];
					m[i-l][j] = ' ';
					j++;
				}
				k++;
				l++;
			}
		}
	}
	
	
	if(combo > 1)
		res += combo * 2;
	else
		res += combo;


	if(res >= *velFlag){
		*velocidad /= 2;
		*velFlag *= 2;
		if(res >= *velFlag2){
			*vel2 /= 2;
			*velFlag2 *= 2;
		}
	}
		
	for(i = 4; i >= 0; i--){
		record[i] = (char)(res%10 + (int)'0');
		res /= 10;
	}
}

int main(){
	srand(time(NULL));
	system("mode 50, 50");

	char matriz[36][46];
	char tecla;
	char record[6] = {'0','0','0','0','0','\0'};
	
	bool pausa = true;
	bool terminar = false;
	bool colision = false;
	
	int fichaSiguiente;
	int fichaSiguiente2;
	int fichaSiguiente3;
	int fichaActual;
	int mover = 12;
	int caer = 0;
	int velocidad = 30000;
	int vel2 = 3000;
	int velFlag = 20;
	int velFlag2 = 60;
	int i = 0;

	struct fichas bolsaDeFichas;
	bolsaDeFichas.tope = -1;
	
	cargarFichas(&bolsaDeFichas);
	fichaActual = rand() % 19 + 1;
	fichaSiguiente = rand() % 19 + 1;
	fichaSiguiente2 = rand() % 19 + 1;
	fichaSiguiente3 = rand() % 19 +1;
	inicializarMatriz(matriz);
	
	imprimirMatriz(matriz, bolsaDeFichas, fichaActual, fichaSiguiente, fichaSiguiente2, fichaSiguiente3, record, mover, caer);
	printf("\n     Presione (s) para salir del juego...");

	while(tecla != 'p' && tecla != 's'){
		if(kbhit()){
			tecla = getch();
			if(tecla == 'p')
				pausa = false;
			else if(tecla == 's')
				terminar = true;
		}
	}
	
	while(!terminar){
			
		colision = false;
		while(kbhit() && i <= velocidad && !colision){
			
			tecla = getch();
			if(tecla == 'a'){
				
				if(contactoParedIzquierda(fichaActual, matriz, mover, caer)){
					
					colision = true;
					limpiarPosicion(matriz, mover, caer);
					system("cls||clear");
					imprimirMatriz(matriz, bolsaDeFichas, fichaActual, fichaSiguiente, fichaSiguiente2, fichaSiguiente3, record, mover, caer);
				}else{
					
					limpiarPosicion(matriz, mover, caer);
					mover--;
					system("cls||clear");
					imprimirMatriz(matriz, bolsaDeFichas, fichaActual, fichaSiguiente, fichaSiguiente2, fichaSiguiente3, record, mover, caer);
				}
				
				i += vel2;
				
			}else if(tecla == 'd'){
				
				if(contactoParedDerecha(fichaActual, matriz, mover, caer)){
					
					colision = true;
					limpiarPosicion(matriz, mover, caer);
					system("cls||clear");
					imprimirMatriz(matriz, bolsaDeFichas, fichaActual, fichaSiguiente, fichaSiguiente2, fichaSiguiente3, record, mover, caer);
				}else{
					
					limpiarPosicion(matriz, mover, caer);
					mover++;
					system("cls||clear");
					imprimirMatriz(matriz, bolsaDeFichas, fichaActual, fichaSiguiente, fichaSiguiente2, fichaSiguiente3, record, mover, caer);
				}
				
				i += vel2;
				
			}else if(tecla == 's'){
				
				if(contactoPiso(fichaActual, matriz, mover, caer))
				
					colision = true;
					
				else{
					
					limpiarPosicion(matriz, mover, caer);
					caer++;
					system("cls||clear");
					imprimirMatriz(matriz, bolsaDeFichas, fichaActual, fichaSiguiente, fichaSiguiente2, fichaSiguiente3, record, mover, caer);
					i += vel2;
				}
				
			}else if(tecla == 'w'){
				
				limpiarPosicion(matriz, mover, caer);
				system("cls||clear");
				rotarFicha(&fichaActual, matriz, &mover, &caer);
				imprimirMatriz(matriz, bolsaDeFichas, fichaActual, fichaSiguiente, fichaSiguiente2, fichaSiguiente3, record, mover, caer);
				i += vel2;
				
			}else if(tecla == 'p'){
				
				pausa = true;
				tecla = '0';
				printf("                Pausa!\n");
				printf("     Presione (s) para salir del juego...");

				while(tecla != 'p' && tecla != 's'){
					if(kbhit()){
						tecla = getch();
						if(tecla == 'p')
							pausa = false;
						else if(tecla == 's')
							terminar = true;
					}
				}
			}
		}
		
		if(i > velocidad){
			
			if(contactoPiso(fichaActual, matriz, mover, caer)){
				
				fijarFicha(matriz, mover, caer);
				romperLinea(matriz, record, &velocidad, &vel2, &velFlag, &velFlag2);
				
				if(caer < 3)
				
					terminar = true;
					
				else{
					
					fichaActual = fichaSiguiente;
					fichaSiguiente = fichaSiguiente2;
					fichaSiguiente2 = fichaSiguiente3;
					fichaSiguiente3 = rand() % 19 +1;
					mover = 12;
					caer = 0;
				}
				
			}
			i = 0;
			system("cls||clear");
			limpiarPosicion(matriz, mover, caer);
			caer++;
			imprimirMatriz(matriz, bolsaDeFichas, fichaActual, fichaSiguiente, fichaSiguiente2, fichaSiguiente3, record, mover, caer);
			
		}
		i++;	
	}
		
	printf("\n\n               Fin del juego");

	return 0;
}
