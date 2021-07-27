#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
  srand(time(NULL));
  int tam=10;
  char tecla_digitada;
  char matriz_esta[3][10];
  char matriz_casas[tam];
  char matriz_sala[5][5];
  char matriz_bairro[8][10];
  char produtos[4];
  char personagem = 'W';
  int personagem_l = 1;
  int personagem_c = 0;
  int contador[5][1];
  char matriz_sala_copia[5][5];
  char matriz_esta_copia[3][10];
  char matriz_bairro_copia[8][10];
  int proxima_fase = 0;

//contadores dos produtos quimicos
  contador[1][0] = 0;
  contador[2][0] = 0;
  contador[3][0] = 0;
  contador[4][0] = 0;

  //estágio 1 : (sala)

  //gerar sala
  for(int linha=0;linha<6;linha++)
  {
    printf("\n");
     for(int coluna=0;coluna<5;coluna++)
  {
    matriz_sala[linha][coluna]='.';
  } 
   printf("\n");
  }
  //Atribuindo valores as matrizes
    produtos [0] = '1';
    produtos [1] = '2';
    produtos [2] = '3';
    produtos [3] = '4';

    matriz_sala[0][0]='P';
    matriz_sala[1][0]= personagem;
    matriz_sala[0][3]= produtos [0];
    matriz_sala[0][4]= produtos [0];
    matriz_sala[1][3]= produtos [1];
    matriz_sala[1][4]= produtos [0];
    matriz_sala[2][3]= produtos [1];
    matriz_sala[2][4]= produtos [1];
    matriz_sala[3][3]= produtos [2];
    matriz_sala[3][4]= produtos [3];
    matriz_sala[4][3]= produtos [2];
    matriz_sala[4][4]= produtos [3];
    matriz_sala[1][0]= personagem;

    //atribuindo valores à matriz copia
    for(int linha=0;linha < 6;linha++)
    {
     for(int coluna=0;coluna < 5;coluna++)
    {
      matriz_sala_copia[linha][coluna]= matriz_sala[linha][coluna];
    } 
    }
  
  //movimentação na sala
  do
  { 
    printf("||Bem vindo ao jogo do Breaking Bad, conclua cada um dos estágios com suas respectivas missões||\n");
    printf("Recolha todos os produtos químicos, pegue seu carro, vá buscar Jessie e conclua o jogo,mas cuidado com a polícia!\n");
    printf("\nLegenda : P - Porta ou Polícia/ W - Walter / 1,2,3,4 - Produtos ou carros / J - Jessie / E - Entrada / S - Saída\n");
    printf("\nMovimentação: W - cima / S - baixo / A - Esquerda / D - Direita\n");
    printf("\n");
    printf("\nPegue um produto de cada tipo (1,2,3,4), não pegue mais ou será preso!\n");
    printf("\nitem(1) = %i \nitem(2) = %i \nitem(3) = %i \nitem(4) = %i", contador[1][0], contador[2][0], contador[3][0], contador[4][0]);
    
    printf("\n-------------------------------------------\n");
    
    //impressao da matriz atualizada
    for(int linha=0;linha<5;linha++)
    {
      for(int coluna=0;coluna<5;coluna++)
    {
      printf("%c ", matriz_sala[linha][coluna]);
    }
    printf("\n");
    }

    //leitura do movimento do personagem
    char tecla_digitada;
    printf("\n");
    printf("Movimento:\n");
    scanf("%c",&tecla_digitada);
    getchar();

    printf("\n");

    
    switch(tecla_digitada)
    {
      case 'w':
      if(personagem_l > 0){
        personagem_l--;
        matriz_sala[personagem_l][personagem_c] = personagem;
        matriz_sala[personagem_l + 1][personagem_c] = '.';

      }
      break;

      case 's': 
      if(personagem_l < 4){
      personagem_l++;
      matriz_sala[personagem_l][personagem_c] = personagem;
      matriz_sala[personagem_l - 1][personagem_c] = '.';
      }
      break;

      case 'd': 
      if(personagem_c < 4){
      personagem_c++;
      matriz_sala[personagem_l][personagem_c] = personagem;
      matriz_sala[personagem_l][personagem_c - 1] = '.';
      }
      break;
      
      case 'a':
      if(personagem_c > 0){
        personagem_c--;
        matriz_sala[personagem_l][personagem_c] = personagem;
        matriz_sala[personagem_l][personagem_c+1] = '.';  

      }
      break;

      default: printf("\ndigite um tecla válida");
    }

    matriz_sala[0][0] = 'P';
    
    //Verificação da posição do personagem em realação ao 'P'.
    if(matriz_sala_copia[personagem_l][personagem_c] == 'P')
      {
        if(contador[1][0] == 1 &&   contador[2][0] == 1 && contador[3][0] == 1 && contador[4][0] == 1){
        printf("\nWalter saiu da sala e foi para o o estacionamento");
        proxima_fase = 1;
        }
        else
        {
          printf("\n\nVolte e pegue os materiais necessários");
        }
        matriz_sala[0][0] = 'P';
        
      }
    //Atribuindo +1 ao contador caso a posição do personagem seja igual a de um produto
    if(matriz_sala_copia[personagem_l][personagem_c] == '1')
    {
      contador[1][0]++;
      matriz_sala_copia[personagem_l][personagem_c] = '.';
    }
    else if(matriz_sala_copia[personagem_l][personagem_c] == '2')
    { 
      contador[2][0]++;
      matriz_sala_copia[personagem_l][personagem_c] = '.';
    }
    else if(matriz_sala_copia[personagem_l][personagem_c] == '3')
    {
      contador[3][0]++;
      matriz_sala_copia[personagem_l][personagem_c] = '.';
    }
    else if(matriz_sala_copia[personagem_l][personagem_c] == '4')
    {
      contador[4][0]++;
      matriz_sala_copia[personagem_l][personagem_c] = '.';
    }
    //Verificando se o player pegou 2 itens do mesmo tipo
    if(contador[1][0] == 2 || contador[2][0] == 2 || contador[3][0] == 2 || contador[4][0] == 2)
    {
      printf("Você foi preso!\n");
      return 0;
    }

    system ("clear");
  
}while(proxima_fase == 0);


//estágio 2 : (estacionamento)

personagem_l= 1;
personagem_c= 0;

//gerar estacionamento
for(int linha=0;linha < 3;linha++)
    {
     printf("\n");
     for(int coluna=0;coluna < 10;coluna++)
    {
      matriz_esta[linha][coluna]='.';        
    }
    }
      matriz_esta[0][0] = 'P';
      matriz_esta[2][9] = 'S';
      matriz_esta[0][3] = '1';
      matriz_esta[0][4] = '2';
      matriz_esta[0][5] = '3';
      matriz_esta[0][6] = '4';
      matriz_esta[0][7] = '5';
      matriz_esta[0][8] = '6';
      matriz_esta[0][9] = '7';
      matriz_esta[personagem_l][personagem_c] = personagem;
    
    //Atribuindo a matriz copia a matriz original
    for(int linha=0;linha < 3;linha++)
    {
     for(int coluna=0;coluna < 10;coluna++)
    {
      matriz_esta_copia[linha][coluna]= matriz_esta[linha][coluna];
      //printf("%c ", matriz_esta[linha][coluna]);
    }
    printf("\n"); 
    }
  
  //movimentação no estacionamento
    do
    {
    //atualizar mapa
    printf("\n\n");
    for(int linha=0;linha < 3;linha++)
    {
     for(int coluna=0;coluna < 10;coluna++)
    {
      printf("%c ", matriz_esta[linha][coluna]);
    }
      printf("\n"); 
    }


    printf("\n");

    printf("\nAgora você está no estacionamento, pegue o seu carro (5)e vá para a saída\n");
    printf("\nMovimento: \n");
    scanf("%c",&tecla_digitada);
    getchar();

    switch(tecla_digitada)
    {
      case 'w':
      if(personagem_l>0)
      {
        personagem_l--;
        matriz_esta[personagem_l][personagem_c] = personagem;
        matriz_esta[personagem_l + 1][personagem_c] = '.';
      }
      break;

      case 's':
      if(personagem_l<2)
      {
          personagem_l++;
          matriz_esta[personagem_l][personagem_c]=personagem;
          matriz_esta[personagem_l-1][personagem_c]='.';
      }
      break;

      case 'd':
      if(personagem_c<9)
      {
          personagem_c++;
          matriz_esta[personagem_l][personagem_c]=personagem;
          matriz_esta[personagem_l][personagem_c-1]='.';
      }
      break;

      case 'a':
      if(personagem_c>0)
      {
          personagem_c--;
          matriz_esta[personagem_l][personagem_c]=personagem;
          matriz_esta[personagem_l][personagem_c+1]='.';
      }
      break;

      default:
      printf("\nMovimento inválido\n");
    }
      matriz_esta[0][0] = 'P';
      matriz_esta[2][9] = 'S';
      matriz_esta[0][3] = '1';
      matriz_esta[0][4] = '2';
      matriz_esta[0][5] = '3';
      matriz_esta[0][6] = '4';
      matriz_esta[0][8] = '6';
      matriz_esta[0][9] = '7';

      if(matriz_esta_copia[personagem_l][personagem_c] == 'P')
      {
        printf("\nVocê não pode voltar, a porta está tracanda!");
      }
      //Imprimindo uma mensagem caso o player entre no carro errado.
      if(matriz_esta_copia[personagem_l][personagem_c] == '1' || matriz_esta_copia[personagem_l][personagem_c] == '2' || matriz_esta_copia[personagem_l][personagem_c] == '3' || matriz_esta_copia[personagem_l][personagem_c] == '4' || matriz_esta_copia[personagem_l][personagem_c] == '6' || matriz_esta_copia[personagem_l][personagem_c] == '7')
      {
        printf("\nVocê colocou a chave e o carro não ligou. Este não é o seu carro!");
      }   
      
      if(matriz_esta_copia[personagem_l][personagem_c]=='5')
      {
        personagem ='5';
        printf("\nDiriga-se a saída");
      }  

      if(matriz_esta_copia[personagem_l][personagem_c]=='S')
      {
        if(personagem=='5')
        {
          printf("\nWalter saiu do estacionamento\n");
          proxima_fase++;
        }else
        {
          printf("\nPegue seu carro para sair");
        }
      }
    
      system("clear");

    }while(proxima_fase == 1);
    
    //estágio 3 :(Bairro)
    char carro='5';
    
    //gerar mapa
    for(int linha=0;linha < 8;linha++)
    {
      for(int coluna=0;coluna < 10;coluna++)
    {
      matriz_bairro[linha][coluna]= ' ';
    }
    }
    //Atribuindo valores das linhas principais horizontais e verticais da matriz bairro
    for(int i = 0; i <= 1; i++)
    {
      for(int coluna_1 = 1; coluna_1 < 6; coluna_1++)
      {
        matriz_bairro[0][coluna_1] = '.';
      }

      for(int coluna_2 = 6; coluna_2 < 9; coluna_2++)
      {
        matriz_bairro[1][coluna_2] = '.';
      }

      for(int coluna_3 = 0; coluna_3 < 10; coluna_3++)
      {
        matriz_bairro[3][coluna_3] = '.';
      }

      for(int coluna_4 = 1; coluna_4 < 9; coluna_4++)
      {
        matriz_bairro[7][coluna_4] = '.';
      }

      for (int linha_1 = 4; linha_1 < 7; linha_1++)
      {
        matriz_bairro[linha_1][8] = '.';
      }

      for (int linha_2 = 3; linha_2 < 6; linha_2++)
      {
        matriz_bairro[linha_2][0] = '.';
      }

    }
    //Atribuindo valores a matriz_bairro
     matriz_bairro[1][0] = '.';
     matriz_bairro[5][1] = '.';
     matriz_bairro[6][1] = '.';
     matriz_bairro[6][5] = '.';
     matriz_bairro[0][0] = 'E';
     matriz_bairro[1][9] = 'P';
     matriz_bairro[4][5] = 'P';
     matriz_bairro[7][9] = 'S';
     matriz_bairro[6][3] = 'J';
     matriz_bairro[2][9] = '1';
     matriz_bairro[5][5] = '2';
     matriz_bairro[2][0] = '3';
     matriz_bairro[1][5] = '4';
     matriz_bairro[0][1] = carro;
     personagem_l = 0;
     personagem_c = 1;
     int jessie=0;

    //Gerar cópia
    for(int linha=0;linha < 8;linha++)
    {
      for(int coluna=0;coluna < 10;coluna++)
    {
      matriz_bairro_copia[linha][coluna]= matriz_bairro[linha][coluna];
    }
    }

do
{   
    printf("\n");
    printf("\nitem(1) = %i \nitem(2) = %i \nitem(3) = %i \nitem(4) = %i",contador[1][0], contador[2][0], contador[3][0], contador[4][0]);
    
    printf("\n-------------------------------------------\n");


    printf("\n\n");
    //Printar mapa
    for(int linha=0;linha < 8;linha++)
    {
      for(int coluna=0;coluna < 10;coluna++)
    {
      printf("%c  ", matriz_bairro[linha][coluna]);
    }
    printf("\n");
    }

    //movimentação no bairro
    printf("\n");

    printf("\nAgora você está no bairro, pegue todos os produtos no mapa, pegue Jessie, e vá até a saída\n");
    printf("\nLegenda: P - Polícia / J - Jessie / 1,2,3,4 - Produtos / S - Saída / E - Entrada\n");
    printf("\nO valor de passar de fase: %i", proxima_fase);
    printf("\nMovimento: \n");
    scanf("%c",&tecla_digitada);
    getchar();

    switch(tecla_digitada)
    {
      case 'w':
      
        if(matriz_bairro[personagem_l -1][personagem_c] != ' ' && personagem_l > 0){
        personagem_l--;
        matriz_bairro[personagem_l][personagem_c] = carro;
        matriz_bairro[personagem_l + 1][personagem_c] = '.';
        }
      break;

      case 's':
          if(matriz_bairro[personagem_l +1][personagem_c] != ' ' && personagem_l < 7){
          personagem_l++;
          matriz_bairro[personagem_l][personagem_c]=carro;
          matriz_bairro[personagem_l-1][personagem_c]='.';
          }
      break;

      case 'd':
        if(matriz_bairro[personagem_l][personagem_c + 1] != ' ' && personagem_c < 9){
          personagem_c++;
          matriz_bairro[personagem_l][personagem_c]=carro;
          matriz_bairro[personagem_l][personagem_c-1]='.';
        }
        
      break;

      case 'a':
      if(matriz_bairro[personagem_l][personagem_c - 1] != ' ' && personagem_c > 0){
          personagem_c--;
          matriz_bairro[personagem_l][personagem_c]=carro;
          matriz_bairro[personagem_l][personagem_c+1]='.';}
      break;

      default:
      printf("\nMovimento inválido");
    }
    
      matriz_bairro[0][0] = 'E';
      matriz_bairro[1][9] = 'P',
      matriz_bairro[4][5] = 'P';
      matriz_bairro[7][9] = 'S';

    //Atribuindo +1 ao contador caso a posição do personagem seja igual a de um produto
    if(matriz_bairro_copia[personagem_l][personagem_c]=='1')
    {
      contador[1][0]++;
      matriz_bairro_copia[personagem_l][personagem_c] = '.';
    }
    else if (matriz_bairro_copia[personagem_l][personagem_c] == '2')
    {
      contador[2][0]++;
      matriz_bairro_copia[personagem_l][personagem_c] = '.';
    }
    else if(matriz_bairro_copia[personagem_l][personagem_c]=='3')
    {
      contador[3][0]++;
      matriz_bairro_copia[personagem_l][personagem_c] = '.';
    }
    else if (matriz_bairro_copia[personagem_l][personagem_c] == '4')
    {
      contador[4][0]++;
      matriz_bairro_copia[personagem_l][personagem_c] = '.';
    }  
    //Decidindo(por meio do rand) se o player deve ser preso ou não a chegar na polícia
    if(matriz_bairro_copia[personagem_l][personagem_c]== 'P')
    {
      int prisao = rand()%2;
      if(prisao==0)
      {
        printf("\nVocê foi preso!");
        return 0;
      }
      else if(prisao==1)
      {
        printf("\nVocê foi liberado, mas perdeu todos os seus produtos.");
        contador[1][0] = 0;
        contador[2][0] = 0;
        contador[3][0] = 0;
        contador[4][0] = 0;
      }
    }
    //Pegando jessie
    if(matriz_bairro_copia[personagem_l][personagem_c]=='J')
    {
      matriz_bairro[personagem_l][personagem_c]='.';
      jessie=1;
    }
    // Verificando qual mensagem deve ser exibida caso o player chegue a saída
    if(matriz_bairro_copia[personagem_l][personagem_c]=='S')
    {
      if(jessie==1)
      {
        if(contador[1][0] == 0 && contador[2][0] == 0 && contador[3][0] == 0 && contador[4][0] == 0)
        {
          printf("\nVocê não tem trabalho hoje! Fim de jogo...");
        }
        else if(contador[1][0] == 2 && contador[2][0] == 2 && contador[3][0] == 2 && contador[4][0] ==2)
        {
          printf("\nProdução dobrada! Fim de jogo...");
        }
        else
        {
          printf("Fim de jogo! Você terminou o jogo sem produção dobrada! ");
        }
        proxima_fase++;
        
      }
      else if(jessie==0)
      {
        printf("\n\ndVolte e pegue Jessie");
      }
      
    }

    system ("clear");

}while(proxima_fase == 2);
   
}



