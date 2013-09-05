#include <iostream>



\\globalmente podemos definir todas as constantes e um vetor float com a popula��o de cada esp�cie, e um marcador de tempo s� para evitar problemas. O tempo � 0 no instante em que surge o primeiro individuo mutante da especie.
\\Do tipo float e n�o do tipo int, pois acho que as equa��es n v�o funcionar de int.
\\ s[0] -> tempo, s[1]->popula��o de crian�as, s[2] -> popula��o de lobos, s[3] -> popula��o de lobos mutantes, s[3]=1 sempre que s[0]==0.


void diferen�asfinitas(){ 
	\\ lotka volterra com 1 presa e dois predadores

	\\a fun��o recebe em 3 floats a popula��o de cada esp�cie no tempo t+0
	\\ os par�metros s�o variaveis globais
	\\a fun��o retorna as popula��es no tempo t+1
	\\ como n�o lembro como faz para uma fun��o retornar 3 n�meros a fiz do tipo void, haver� um vetor de 3 floats o qual esta fun��o editar�.

}

int plotaponto(*imagem){  \\ como � o imput aqui? n�o me lembro

	\\essa fun��o recebe um endere�o de um arquivo de imagem
	\\a fun��o desenha um ponto nesse arquivo de imagem.
	\\importante que este arquivo registre n�o s� quais pontos foram percorridos, mas tamb�m quantas vezes, 
	\\como se registrasse em cinza claro, mas ao passar pela segunda vez sobre um ponto o pintasse de cinza escuro.
	\\assim poderemos determinar o crit�rio de parada como o momento em que um ponto foi percorrido 5 vezes AKA ficando um amontoado ileg�vel
}

int lotkavolterra(){ \\essa fun��o cria os arquivos de imagem e retorna se a fun��o acaba em extin��o ou estabilidade 

	\\essa fun��o cria um arquivo de imagem.
	\\o nome desse arquivo deve ser gigante e dar o valor de todos os par�metros no momento em que ele foi criado. exemplo: a2.0b1.5s12000s2500s31d112d120d130d220.5
	\\e depois faz o gr�fico, e retorna como ele ficou
	
	FILE *figura;

	figura = fopen(" \*colocar um nome gigante*\ " , "w");

	
	int parada=0; 
	
	while(parada<5 && s[0]>0 && s[2]>0){ \*5 um numero arbitrariamente alto, veja mais fun��o ponto*\\*se uma popula��o se extingue o la�o para tamb�m.*\\*a esp�cie s[1] representa os predadores n�o mutantes, e n�o � um problema se ele se estinguir*\
		
		diferen�asfinitas();
		parada = plotaponto(figura); \*� assim que eu endere�o?*\
	}


	\*como fecha um arquivo mesmo?*\
	\\essa fun��o vai gerar um gr�fico para cada vez que for chamada. se chamada 10000000 vezes, ir� gerar 10000000 gr�ficos, o que pode ficar pesado
	\\talvez fosse uma boa ideia colocar um contador de modo que 99 a cada 100 gr�ficos sejam apagados antes do fim da fun��o.
	\\abrir um arquivo para apaga-lo depois de obter um resultado 99% das vezes parece chato, h� como contornar isso.

	if(parada==5){ \\ estabilidade? podemos rodar umas vezes. algu�m tem par�metro melhor de detec��o de estabilidade?
		return 0;
	}

	if(s[1]==0){ \\extin��o
		return 1;
	}

	if(s[2]==0){ \\extin��o
		return 2;
	}

	if(s[3]==0){ \\extin��o
		return 3;
	}
	else{
		sout << "erro lotkavolterra";
	}
	return -1;
}

int main() {
	\\dado que iremos testar a extin��o ou estabilidade para N parametros, vamos criar uma matriz de ordem N e lado muito grande (digamos 10000)
	\\em cada casa dessa matriz colocaremos um valor 0 para estabilidade ou !=0 para extin��o
	\\assim (digamos que estamos variando 5 par�metros) se a casa [50; 200; 30; 2; 247] vale 0, ent�o se o primeiro par�metro vari�vel vale 50, o segundo 200 e assim por diante, a popula��o fica est�vel.
	
	\\digamos que queremos testar dois par�metros (z e Y),e que z pode variar de 0,00001 at� 0,00010, e y de 1 a 10.
	\*for(i=10000;i>1;i--){
		z = 0,00001 + i*0,000000009;
		for(j=10000;j>1;j--){
			y = 1 + i*0,0009.;
			Matriz[i,j]=lotkavolterra();
		}
	}*\

	\\depois resta analizar a matriz de N dimens�es
}










