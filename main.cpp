#include <iostream>



\\globalmente podemos definir todas as constantes e um vetor float com a população de cada espécie, e um marcador de tempo só para evitar problemas. O tempo é 0 no instante em que surge o primeiro individuo mutante da especie.
\\Do tipo float e não do tipo int, pois acho que as equações n vão funcionar de int.
\\ s[0] -> tempo, s[1]->população de crianças, s[2] -> população de lobos, s[3] -> população de lobos mutantes, s[3]=1 sempre que s[0]==0.


void diferençasfinitas(){ 
	\\ lotka volterra com 1 presa e dois predadores

	\\a função recebe em 3 floats a população de cada espécie no tempo t+0
	\\ os parãmetros são variaveis globais
	\\a função retorna as populações no tempo t+1
	\\ como não lembro como faz para uma função retornar 3 números a fiz do tipo void, haverá um vetor de 3 floats o qual esta função editará.

}

int plotaponto(*imagem){  \\ como é o imput aqui? não me lembro

	\\essa função recebe um endereço de um arquivo de imagem
	\\a função desenha um ponto nesse arquivo de imagem.
	\\importante que este arquivo registre não só quais pontos foram percorridos, mas também quantas vezes, 
	\\como se registrasse em cinza claro, mas ao passar pela segunda vez sobre um ponto o pintasse de cinza escuro.
	\\assim poderemos determinar o critério de parada como o momento em que um ponto foi percorrido 5 vezes AKA ficando um amontoado ilegível
}

int lotkavolterra(){ \\essa função cria os arquivos de imagem e retorna se a função acaba em extinção ou estabilidade 

	\\essa função cria um arquivo de imagem.
	\\o nome desse arquivo deve ser gigante e dar o valor de todos os parâmetros no momento em que ele foi criado. exemplo: a2.0b1.5s12000s2500s31d112d120d130d220.5
	\\e depois faz o gráfico, e retorna como ele ficou
	
	FILE *figura;

	figura = fopen(" \*colocar um nome gigante*\ " , "w");

	
	int parada=0; 
	
	while(parada<5 && s[0]>0 && s[2]>0){ \*5 um numero arbitrariamente alto, veja mais função ponto*\\*se uma população se extingue o laço para também.*\\*a espécie s[1] representa os predadores não mutantes, e não é um problema se ele se estinguir*\
		
		diferençasfinitas();
		parada = plotaponto(figura); \*é assim que eu endereço?*\
	}


	\*como fecha um arquivo mesmo?*\
	\\essa função vai gerar um gráfico para cada vez que for chamada. se chamada 10000000 vezes, irá gerar 10000000 gráficos, o que pode ficar pesado
	\\talvez fosse uma boa ideia colocar um contador de modo que 99 a cada 100 gráficos sejam apagados antes do fim da função.
	\\abrir um arquivo para apaga-lo depois de obter um resultado 99% das vezes parece chato, há como contornar isso.

	if(parada==5){ \\ estabilidade? podemos rodar umas vezes. alguém tem parâmetro melhor de detecção de estabilidade?
		return 0;
	}

	if(s[1]==0){ \\extinção
		return 1;
	}

	if(s[2]==0){ \\extinção
		return 2;
	}

	if(s[3]==0){ \\extinção
		return 3;
	}
	else{
		sout << "erro lotkavolterra";
	}
	return -1;
}

int main() {
	\\dado que iremos testar a extinção ou estabilidade para N parametros, vamos criar uma matriz de ordem N e lado muito grande (digamos 10000)
	\\em cada casa dessa matriz colocaremos um valor 0 para estabilidade ou !=0 para extinção
	\\assim (digamos que estamos variando 5 parâmetros) se a casa [50; 200; 30; 2; 247] vale 0, então se o primeiro parâmetro variável vale 50, o segundo 200 e assim por diante, a população fica estável.
	
	\\digamos que queremos testar dois parâmetros (z e Y),e que z pode variar de 0,00001 até 0,00010, e y de 1 a 10.
	\*for(i=10000;i>1;i--){
		z = 0,00001 + i*0,000000009;
		for(j=10000;j>1;j--){
			y = 1 + i*0,0009.;
			Matriz[i,j]=lotkavolterra();
		}
	}*\

	\\depois resta analizar a matriz de N dimensões
}










