//Anthony Clint Pastorello - RA: 0050482011005
//Mylla Cristhina Rodrigues da Costa Abreu Korres - RA: 0050482011032

#define desafio
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

/*
	1 � Pesquise as fun��es de biblioteca abaixo que manipulam arquivos.

		 fopen();
		 fclose();
		 fwrite();
		 fread();
		 fseek();
		 exit(0);
*/

/*
	Biblioteca necess�ria: stdio.h

	* Fun��o fopen() => abertura de um arquivo em alto-n�vel.
	  Sua estrutura b�sica �:

	FILE fopen(const char *nome_arquivo, const char *modo_de_abertura);

	O 'nome_do_arquivo' determina qual arquivo dever� ser aberto.
	Este nome deve ser v�lido no S.O. que estiver sendo utilizado.
	O 'modo de abertura' diz � fun��o fopen() que tipo de uso voc�
	vai fazer do arquivo. A tabela abaixo mostra os modos v�lidos:
	 _________________________________________________________________
	|          |                                                      |
	|   Modo   |                     Significado                      |
	|__________|______________________________________________________|
	|		     |Abre um arquivo texto para leitura. Se o arquivo n�o  |
	|	  "r"   |existir, a opera��o falhar� e fopen() retornar� NULL. |
	|__________|______________________________________________________|
	|          |Abre um arquivo texto para grava��o. Se o arquivo j�  |
	|    "w"   |existir, elimina seu conte�do e recome�a a grava��o a |
	|          |partir de seu in�cio.                                 |
	|__________|______________________________________________________|
	|          |Abre um arquivo texto para grava��o, a partir de seu  |
	|   "a"    |final. Caso o arquivo n�o exista, ele ser� criado.    |
	|__________|______________________________________________________|
	|          |Abre um arquivo texto para atualiza��o, ou seja,tanto |
	|   "r+"   |tanto para leitura como grava��o. Caso o arquivo n�o  |
	|          |exista, a opera��o falhar� e fopen() retornar� NULL.  |
	|__________|______________________________________________________|
	|		     |Abre um arquivo texto para atualiza��o, ou seja, tanto|
	|   "w+"   |para leitura como grava��o. Se o arquivo j� existir,  |
	|          |seu conte�do ser� destru�do.                          |
	|__________|______________________________________________________|
	|          |Abre um arquivo texto para atualiza��o, gravando novos|
	|   "a+"   |dados a partir do final do arquivo. Caso o arquivo n�o|
	|          |exista, ele ser� criado.                              |
	|__________|______________________________________________________|
	|		     |Abre um arquivo para leitura em modo bin�rio. Caso o  |
	|	"rb"    |arquivo n�o existir, a opera��o ir� falhar e fopen()  |
	|          |retornar� NULL.                                       |
	|__________|______________________________________________________|
	|          |Abre um arquivo bin�rio para grava��o. Se o arquivo j�|
	|   "wb"   |existir, elimina seu conte�do e recome�a a grava��o a |
	|          |partir de seu in�cio.                                 |
	|__________|______________________________________________________|
	|          |Abre um arquivo bin�rio para grava��o, a partir de seu|
	|   "ab"   |final. Se o arquivo n�o existir, ele ser� criado.     |
	|__________|______________________________________________________|
	|          |Abre um arquivo bin�rio para atualiza��o, ou seja,    |
	|   "rb+"  |tanto para leitura como grava��o. Caso o arquivo n�o  |
	|          |exista, a opera��o falhar� e fopen() retornar� NULL.  |
	|__________|______________________________________________________|
	|          |Abre um arquivo bin�rio para atualiza��o, ou seja,    |
	|   "wb+"  |tanto para leitura como grava��o. Caso o arquivo j�   |
	|          |exista, seu conte�do ser� destru�do.                  |
	|__________|______________________________________________________|
	|          |Abre um arquivo bin�rio para atualiza��o, gravando    |
	|   "ab+"  |novos dados a partir do final do arquivo. Se o arquivo|
	|          |n�o existir, ele ser� criado.                         |
	|__________|______________________________________________________|


   * Fun��o fclose() => fecha o arquivo associado ao ponteiro FILE
     enviado como argumento.
	  Sua estrutura b�sica �:

	int fclose(FILE *ponteiro_arquivo);

	* Fun��o fwrite() => escreve/grava um bloco de bytes.
	  Sua estrutura �:

	unsigned fwrite(void *buffer,
               int tamanho_da_unidade,
               int numero_de_unidades,
               FILE *fp);

   * Fun��o fread() => l� um bloco de dados.
     Sua estrutura b�sica �:

   unsigned fread(void *buffer,
               int tamanho_da_unidade,
               int numero_de_unidades,
               FILE *fp);

   * Fun��o fseek() => permite movimentar a posi��o corrente de leitura
     e grava��o do arquivo para uma posi��o escolhida.

   fseek(fptr,0,0);

   A fun��o fseek() aceita tr�s argumentos:

   - O primeiro � o ponteiro para a estrutura FILE do arquivo. Ap�s
     chamada a fseek(), esse ponteiro ser�  movimentado para a posi��o
     que desejarmos.
   - O segundo arqumnto � chamado deslocamento, e consiste no n�mero de
     bytes que desejamos deslocar a partir da posi��o especificada pelo
     terceiro argumento.
   - O terceiro argumento chama-se posi��o. Existem tr�s possibilidades
     para este n�mero, as quais determinam de onde o deslocamento come�ar�
     a ser medido, a saber:
      ___________________________________________
     |               |         |                 |
     |   CONSTANTE   | POSI��O |   SIGNIFICADO   |
     |_______________|_________|_________________|
     |               |         |                 |
     |   SEEK_SET    |    0    |In�cio do arquivo|
     |_______________|_________|_________________|
     |               |         |                 |
     |   SEEK_CUR    |    1    |  Posi��o atual  |
     |_______________|_________|_________________|
     |               |         |                 |
     |   SEEK_END    |    2    |  Fim do arquivo |
     |_______________|_________|_________________|

     * Fun��o exit(0) => fecha todos os arquivos abertos e devolve o controle
       ao sistema operacional. Biblioteca necess�ria: stdlib.h
*/

#ifdef exemplo

void main()
{
   int i;
   char texto[50],txt;
   FILE *KP;

   setlocale(LC_ALL,"Portuguese");

   for(i=0; i<sizeof(texto); i++)
   {
      texto[i] = ' ';
   }

   KP = fopen("teste.txt","a+");

   if(KP == NULL)
   {
      printf("\nERRO ao abrir o arquivo!!!\n\n");
      system("pause");
      exit(1);
   }
   else
   {
      printf("Insira o texto a ser gravado: ");
      gets(texto);

      fwrite(texto,1,sizeof(texto),KP);

      fseek(KP,sizeof(texto),SEEK_SET);

      fread(&txt,sizeof(char),50,KP);

      printf("\nTEXTO LIDO DO ARQUIVO: %s",texto);

      fclose(KP);
   }
}

#endif // exemplo

/*
   2 - Escreva um programa que tenha 3 vetores nome[20] e 3 vetores
       email[30] declaradas como vari�veis globais. Na fun��o main()
       fa�a um menu com as seguintes fun��es:

       1 � entrada de dados.
       2 � lista todos os dados na tela.
       3 � pesquisa um nome e mostra na tela
       4 � pesquisa os nomes pela 1� letra e mostra todos na tela.
       5 � altera  dados.
       6 � exclui dados.
       7 � sa�da
*/

#ifdef desafio

char nome_1[20],nome_2[20],nome_3[20],email_1[30],email_2[30],email_3[30], busca[20], v;

int fs[3];

FILE *KP;

void cadastrar();

void lista();

int consultar();

void pesquisar();

void alterar();

void excluir();

void sair();

int conferir(int op);

void ler(int op);

void escrever(int op);

int tamanho(int op);

void ERRO(int op);

void PAUSA();

void limpar(int op);

void converter(int op);

void comparar();

void main()
{
   int op;

   setlocale(LC_ALL,"Portuguese");

   for(;;)
   {
      system("color 1F");

      printf("\n\t\t*** MENU ***\n");
      printf("\n\t   1 - CADASTRAR CLIENTE\n");
      printf("\n\t   2 - LISTA DE CLIENTES\n");
      printf("\n\t   3 - CONSULTA POR NOME COMPLETO\n");
      printf("\n\t   4 - CONSULTA PELA 1� LETRA DO NOME\n");
      printf("\n\t   5 - ALTERAR CADASTRO\n");
      printf("\n\t   6 - EXCLUIR CADASTRO\n");
      printf("\n\t   7 - SAIR\n");

      printf("\n\n\t   INSIRA A OP��O DESEJADA: ");
      scanf("%d",&op);

      switch (op)
      {
      case 1:
         cadastrar();
         break;
      case 2:
         lista();
         break;
      case 3:
         consultar();
         break;
      case 4:
         pesquisar();
         break;
      case 5:
         alterar();
         break;
      case 6:
         excluir();
         break;
      case 7:
         sair();
         break;
      default:
         ERRO(1); //OP��O INV�LIDA
      }

      PAUSA();
   }
}

void cadastrar()
{
   int cont = 4;

   if(conferir(1) == 2 && conferir(2) == 2 && conferir(3) == 2) // CONFERE SE TODAS OS NOMES EST�O PREENCHIDOS
   {
      ERRO(2); // BANCO DE DADOS CHEIO
   }
   else
   {
      if(conferir(1) == 1) // SE NOME_1 VAZIO
      {
         cont = 1;
      }
      else if(conferir(2) == 1) // SE NOME_2 VAZIO
      {
         cont = 2;
      }
      else if(conferir(3) == 1) // SE NOME_3 VAZIO
      {
         cont = 3;
      }

      if(cont <4)
      {
         getchar();

         do
         {
            system("cls");

            system("color 1F");

            printf("\n\t\t*** CADASTRO ***\n");
            printf("\n\tInforme o nome do cliente: ");

            limpar(1); // LIMPA NOME_1
            limpar(2); // LIMPA NOME_2
            limpar(3); // LIMPA NOME_3

            switch(cont)
            {
            case 1:
               gets(nome_1);
               break;
            case 2:
               gets(nome_2);
               break;
            case 3:
               gets(nome_3);
               break;
            }

            if(tamanho(1) == 1) // VERIFICA TAMANHO DO NOME
            {
               ERRO(3); // TAMANHO MAIOR QUE O LIMITE

               PAUSA();
            }
            else
            {
               KP = fopen("clientes.txt","r+");

               if(KP == NULL)
               {
                  KP = fopen("clientes.txt","w+");
               }

               switch(cont)
               {
                  case 1:
                     escrever(1); // ESCREVE NO ARQUIVO NOME_1
                     break;
                  case 2:
                     escrever(2); // ESCREVE NO ARQUIVO NOME_1
                     break;
                  case 3:
                     escrever(3); // ESCREVE NO ARQUIVO NOME_1
                     break;
               }
            }
         }while(tamanho(1) == 1);

         do
         {
            system("color 1F");

            printf("\n\tInforme o email do cliente: ");

            limpar(4); // LIMPA EMAIL_1
            limpar(5); // LIMPA EMAIL_1
            limpar(6); // LIMPA EMAIL_1

            switch(cont)
            {
            case 1:
               gets(email_1);
               break;
            case 2:
               gets(email_2);
               break;
            case 3:
               gets(email_3);
               break;
            }

            if(tamanho(2) == 1) // VERIFICA TAMANHO DO EMAIL
            {
               ERRO(4); // TAMANHO MAIOR QUE O LIMITE

               PAUSA();

               printf("\n\t\t*** CADASTRO ***\n");

               switch(cont)
               {
               case 1:
                  printf("\n\tInforme o nome do %d� cliente: %s\n", cont, nome_1);
                  break;
               case 2:
                  printf("\n\tInforme o nome do %d� cliente: %s\n", cont, nome_2);
                  break;
               case 3:
                  printf("\n\tInforme o nome do %d� cliente: %s\n", cont, nome_3);
                  break;
               }
            }
            else
            {
               switch(cont)
               {
               case 1:
                  escrever(4); // ESCREVE NO ARQUIVO EMAIL_1
                  break;
               case 2:
                  escrever(5); // ESCREVE NO ARQUIVO EMAIL_1
                  break;
               case 3:
                  escrever(6); // ESCREVE NO ARQUIVO EMAIL_1
                  break;
               }

               fclose(KP);

               system("color A0");

               printf("\n\n\tDados salvos com sucesso!!!\n\n");
            }
         }while(tamanho(2) == 1);
      }
   }
}

void lista()
{
   if(conferir(0) == 0)
   {
      ERRO(5); // LISTA VAZIA - ARQUIVO N�O EXISTE
   }
   else if(conferir(1) == 1 && conferir(2) == 1 && conferir(3) == 1)
   {
      ERRO(5); // LISTA VAZIA - ARQUIVO EXISTE POR�M N�O TEM CLIENTES
   }
   else
   {
      KP = fopen("clientes.txt","r+");

      system("cls");
      printf("\n\t\t\t*** LISTA ***\n");
      printf("\n\t ______________________________________________________");
      printf("\n\t|                      |                               |");
      printf("\n\t|         NOME         |             EMAIL             |");
      printf("\n\t|______________________|_______________________________|");

      if(conferir(1) == 1) // NOME_1 VAZIO
      {
         printf("\n\t|                      |                               |");
         printf("\n\t|                      |                               |");
         printf("\n\t|______________________|_______________________________|");
      }
      else // NOME_1 PREENCHIDO
      {
         ler(1);
         printf("\n\t|                      |                               |");
         printf("\n\t| %-20s | %-30s|",nome_1, email_1);
         printf("\n\t|______________________|_______________________________|");
      }

      if(conferir(2) == 1) // NOME_2 VAZIO
      {
         printf("\n\t|                      |                               |");
         printf("\n\t|                      |                               |");
         printf("\n\t|______________________|_______________________________|");
      }
      else // NOME_2 PREENCHIDO
      {
         ler(2);
         printf("\n\t|                      |                               |");
         printf("\n\t| %-20s | %-30s|",nome_2, email_2);
         printf("\n\t|______________________|_______________________________|");
      }

      if(conferir(3) == 1) // NOME_3 VAZIO
      {
         printf("\n\t|                      |                               |");
         printf("\n\t|                      |                               |");
         printf("\n\t|______________________|_______________________________|");
      }
      else // NOME_3 PREENCHIDO
      {
         ler(3);
         printf("\n\t|                      |                               |");
         printf("\n\t| %-20s | %-30s|",nome_3, email_3);
         printf("\n\t|______________________|_______________________________|");
      }

      printf("\n\n");
      fclose(KP);
   }
}

int consultar()
{
   if(conferir(0) == 0)
   {
      ERRO(5); // LISTA VAZIA - ARQUIVO N�O EXISTE
   }
   else if(conferir(1) == 1 && conferir(2) == 1 && conferir(3) == 1)
   {
      ERRO(5); // LISTA VAZIA - ARQUIVO EXISTE POR�M N�O TEM CLIENTES
   }
   else
   {
      getchar();

      do
      {
         system("cls");

         system("color 1F");

         limpar(7); // LIMPA BUSCA

         printf("\n\t\t*** BUSCA POR NOME COMPLETO ***\n");
         printf("\n\tInforme o nome do cliente a ser pesquisado: ");
         gets(busca);

         converter(4); // CONVERTE PARA MAI�SCULO

         if(tamanho(1) == 1) //VERIFICA TAMANHO DA BUSCA
         {
            ERRO(3); // TAMANHO MAIOR QUE O LIMITE

            printf("\n\t");
            system("pause");
         }
      }while(tamanho(1) == 1);

      comparar(); // COMPARA BUSCA COM NOMES

      if(fs[0] == 0 && fs[1] == 0 && fs[2] == 0)
      {
         ERRO(6); // CLIENTE N�O ENCONTRADO

         return (0); // RETORNA CLIENTE N�O ENCONTRADO
      }
      else
      {
         KP = fopen("clientes.txt","r+");

         printf("\n\n\t\t\t>>> RESULTADO DA BUSCA <<<\n");
         printf("\n\t ______________________________________________________");
         printf("\n\t|                      |                               |");
         printf("\n\t|         NOME         |             EMAIL             |");
         printf("\n\t|______________________|_______________________________|");

         if(fs[0] == 1) // BUSCA = NOME_1
         {
            ler(1); // L� NOME_1 DO ARQUIVO
            printf("\n\t|                      |                               |");
            printf("\n\t| %-20s | %-30s|",nome_1, email_1);
            printf("\n\t|______________________|_______________________________|\n\n");

            fs[0] = 0;

            return (1); // RETORNA CLIENTE ENCONTRADO
         }
         if(fs[1] == 1) // BUSCA = NOME_2
         {
            ler(2); // L� NOME_2 DO ARQUIVO
            printf("\n\t|                      |                               |");
            printf("\n\t| %-20s | %-30s|",nome_2, email_2);
            printf("\n\t|______________________|_______________________________|\n\n");

            fs[1] = 0;

            return (2); // RETORNA CLIENTE ENCONTRADO
         }
         if(fs[2] == 1) // BUSCA = NOME_3
         {
            ler(3); // L� NOME_3 DO ARQUIVO
            printf("\n\t|                      |                               |");
            printf("\n\t| %-20s | %-30s|",nome_3, email_3);
            printf("\n\t|______________________|_______________________________|\n\n");

            fs[2] = 0;

            return (3); // RETORNA CLIENTE ENCONTRADO
         }

         fclose(KP);
      }
   }
}

void pesquisar()
{
   if(conferir(0) == 0)
   {
      ERRO(5); // LISTA VAZIA - ARQUIVO N�O EXISTE
   }
   else if(conferir(1) == 1 && conferir(2) == 1 && conferir(3) == 1)
   {
      ERRO(5); // LISTA VAZIA - ARQUIVO EXISTE POR�M N�O TEM CLIENTES
   }
   else
   {
      KP = fopen("clientes.txt","r+");

      system("cls");

      system("color 1F");

      printf("\n\t\t** BUSCA PELA 1� LETRA DO NOME **\n\n");
      printf("\tInforme a 1� letra do nome do cliente a ser pesquisado: ");
      getchar();
      v=getchar();

      converter(5); // CONVERTE PARA MAI�SCULO - V

      ler(1); // L� CLIENTE 1
      ler(2); // L� CLIENTE 2
      ler(3); // L� CLIENTE 3

      converter(1); // CONVERTE PARA MAI�SCULO - NOME_1
      converter(2); // CONVERTE PARA MAI�SCULO - NOME_2
      converter(3); // CONVERTE PARA MAI�SCULO - NOME_3

      if(v != nome_1[0] && v != nome_2[0] && v != nome_3[0])
      {
         ERRO(6); // CLIENTE N�O ENCONTRADO
      }
      else
      {
         printf("\n\n\t\t\t>>> RESULTADO DA BUSCA <<<\n");
         printf("\n\t ______________________________________________________");
         printf("\n\t|                      |                               |");
         printf("\n\t|         NOME         |             EMAIL             |");
         printf("\n\t|______________________|_______________________________|");

         if(v == nome_1[0]) // COMPARA 1� LETRA DO NOME_1
         {
            ler(1);
            printf("\n\t|                      |                               |");
            printf("\n\t| %-20s | %-30s|",nome_1, email_1);
            printf("\n\t|______________________|_______________________________|");
         }

         if(v == nome_2[0]) // COMPARA 1� LETRA DO NOME_2
         {
            ler(2);
            printf("\n\t|                      |                               |");
            printf("\n\t| %-20s | %-30s|",nome_2, email_2);
            printf("\n\t|______________________|_______________________________|");
         }

         if(v == nome_3[0]) // COMPARA 1� LETRA DO NOME_3
         {
            ler(3);
            printf("\n\t|                      |                               |");
            printf("\n\t| %-20s | %-30s|",nome_3, email_3);
            printf("\n\t|______________________|_______________________________|");
         }

         printf("\n\n");
      }

      fclose(KP);
   }
}

void alterar()
{
   int op, cli;

   if(conferir(0) == 0)
   {
      ERRO(5); // LISTA VAZIA - ARQUIVO N�O EXISTE
   }
   else if(conferir(1) == 1 && conferir(2) == 1 && conferir(3) == 1)
   {
      ERRO(5); // LISTA VAZIA - ARQUIVO EXISTE POR�M N�O TEM CLIENTES
   }
   else
   {
      KP = fopen("clientes.txt","r+");

      system("cls");

      printf("\n\t\t\t*** ALTERA��O DE DADOS ***\n");
      printf("\n\tPrimeiro ser� realizada uma busca do cliente que ter� os dados alterados.\n\n\n\t");

      system("pause");

      cli = consultar(); // BUSCA CLIENTE

      PAUSA();

      if(cli == 0)
      {
         ERRO(7); // ALTERA��O CANCELADA
      }
      else
      {
         printf("\n\t\t\t*** ALTERA��O DE DADOS ***\n");
         printf("\n\t1. NOME\n\n\t2. EMAIL\n\n\t3. NOME e EMAIL\n");
         printf("\n\tEscolha o que deseja alterar: ");
         scanf("%d",&op);
         getchar();

         printf("\n");

         if(op < 1 || op > 3)
         {
            ERRO(1); // OP��O INV�LIDA
         }

         if(op == 1 || op == 3) // ALTERA NOME
         {
            do
            {
               system("color 1F");

               printf("\n\tInforme o novo nome do cliente: ");

               switch(cli)
               {
               case 1:
                  limpar(1); // LIMPA NOME_1
                  gets(nome_1);
                  break;
               case 2:
                  limpar(2); // LIMPA NOME_2
                  gets(nome_2);
                  break;
               case 3:
                  limpar(3); // LIMPA NOME_3
                  gets(nome_3);
                  break;
               }

               if(tamanho(1) == 1) // VERIFICA TAMANHO DO NOME
               {
                  ERRO(3); // TAMANHO MAIOR QUE O LIMITE

                  PAUSA();

                  printf("\n\t\t\t*** ALTERA��O DE DADOS ***\n");
               }
               else
               {
                  KP = fopen("clientes.txt","r+");

                  switch(cli)
                  {
                  case 1:
                     escrever(1); // ESCREVE NO ARQUIVO NOME_1
                     break;
                  case 2:
                     escrever(2); // ESCREVE NO ARQUIVO NOME_2
                     break;
                  case 3:
                     escrever(3); // ESCREVE NO ARQUIVO NOME_3
                     break;
                  }
               }
            }while(tamanho(1) == 1);
         }
         if(op == 2 || op == 3) // ALTERA EMAIL
         {
            do
            {
               system("color 1F");

               printf("\n\tInforme o novo email do cliente: ");

               switch(cli)
               {
               case 1:
                  limpar(4);
                  gets(email_1);
                  break;
               case 2:
                  limpar(5);
                  gets(email_2);
                  break;
               case 3:
                  limpar(6);
                  gets(email_3);
                  break;
               }

               if (tamanho(2) == 1) // VERIFICA TAMANHO DO EMAIL
               {
                  ERRO(4); // TAMANHO MAIOR QUE O LIMITE

                  PAUSA();

                  switch(cli)
                  {
                  case 1:
                     printf("\n\t\t\t*** ALTERA��O DE DADOS ***\n");
                     printf("\n\tInforme o novo nome do cliente: %s\n", nome_1);
                     break;
                  case 2:
                     printf("\n\t\t\t*** ALTERA��O DE DADOS ***\n");
                     printf("\n\tInforme o novo nome do cliente: %s\n", nome_2);
                     break;
                  case 3:
                     printf("\n\t\t\t*** ALTERA��O DE DADOS ***\n");
                     printf("\n\tInforme o novo nome do cliente: %s\n", nome_3);
                     break;
                  }
               }
               else
               {
                  switch(cli)
                  {
                  case 1:
                     escrever(4); // ESCREVE NO ARQUIVO EMAIL_1
                     break;
                  case 2:
                     escrever(5); // ESCREVE NO ARQUIVO EMAIL_2
                     break;
                  case 3:
                     escrever(6); // ESCREVE NO ARQUIVO EMAIL_3
                     break;
                  }
               }
            }while(tamanho(2) == 1);
         }

         fclose(KP);

         system("color A0");

         printf("\n\n\tDados alterados com sucesso!!!\n\n");
      }
   }
}

void excluir()
{
   int cli;

   if(conferir(0) == 0)
   {
      ERRO(5); // LISTA VAZIA - ARQUIVO N�O EXISTE
   }
   else if(conferir(1) == 1 && conferir(2) == 1 && conferir(3) == 1)
   {
      ERRO(5); // LISTA VAZIA - ARQUIVO EXISTE POR�M N�O TEM CLIENTES
   }
   else
   {
      system("cls");

      system("color 1F");

      printf("\n\t\t\t*** EXCLUS�O DE CADASTRO ***\n");
      printf("\n\tPrimeiro ser� realizada uma busca do cliente a ser exclu�do.\n\n\n\t");

      system("pause");

      cli = consultar(); // BUSCA CLIENTE

      PAUSA();

      if(cli == 0)
      {
         ERRO(8); // EXCLUS�O CANCELADA
      }
      else
      {
         printf("\n\t\t\t*** EXCLUS�O DE CADASTRO ***\n");
         printf("\n\n\n\tEXCLUINDO CADASTRO...\n");

         switch(cli)
         {
         case 1:
            limpar(1); // LIMPA NOME_1
            limpar(4); // LIMPA EMAIL_1
            KP = fopen("clientes.txt","r+");
            escrever(1); // ESCREVE NO ARQUIVO NOME_1
            escrever(4); // ESCREVE NO ARQUIVO EMAIL_1
            break;
         case 2:
            limpar(2); // LIMPA NOME_2
            limpar(5); // LIMPA EMAIL_2
            KP = fopen("clientes.txt","r+");
            escrever(2); // ESCREVE NO ARQUIVO NOME_2
            escrever(5); // ESCREVE NO ARQUIVO EMAIL_2
            break;
         case 3:
            limpar(3); // LIMPA NOME_3
            limpar(6); // LIMPA EMAIL_3
            KP = fopen("clientes.txt","r+");
            escrever(3); // ESCREVE NO ARQUIVO NOME_3
            escrever(6); // ESCREVE NO ARQUIVO EMAIL_3
            break;
         }

         fclose(KP);

         system("color A0");

         printf("\n\n\tCadastro exclu�do com sucesso!!!\n\n");
      }
   }
}

void sair()
{
   system("color 70");

   system("cls");

   printf("\n\n\n\t\t*** PROGRAMA FINALIZADO ***\n\n\n");

   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

   exit(0);
}

int conferir(int op)
{
   int resp;

   KP = fopen("clientes.txt","r+");

   if(op == 0) // CONFERE SE ARQUIVO EXISTE
   {
      if(KP == NULL)
      {
         return (0); // ARQUIVO N�O EXISTE
      }
      else
      {
         return (1); // ARQUIVO J� EXISTE
      }
   }
   else
   {
      switch(op)
      {
      case 1: // CONFERE SE NOME_1 EST� VAZIO
         ler(1);
         if(nome_1[0] != '\0')
         {
            resp = 2; // PELO MENOS UM ESPA�O PREENCHIDO
         }
         else
         {
            resp = 1; // VAZIO
         }
         break;
      case 2: // CONFERE SE NOME_2 EST� VAZIO
         ler(2);
         if(nome_2[0] != '\0')
         {
            resp = 2; // PELO MENOS UM ESPA�O PREENCHIDO
         }
         else
         {
            resp = 1; // VAZIO
         }
         break;
      case 3: // CONFERE SE NOME_3 EST� VAZIO
         ler(3);
         if(nome_3[0] != '\0')
         {
            resp = 2; // PELO MENOS UM ESPA�O PREENCHIDO
         }
         else
         {
            resp = 1; // VAZIO
         }
         break;
      }

      fclose(KP);

      return(resp);
   }
}

void ler(int op)
{
   switch(op)
   {
   case 1: // L� NOME_1 E EMAIL_1
      fseek(KP,0,SEEK_SET);
      fread(&nome_1,sizeof(char),20,KP);
      fseek(KP,60,SEEK_SET);
      fread(&email_1,sizeof(char),30,KP);
      break;
   case 2: // L� NOME_2 E EMAIL_2
      fseek(KP,20,SEEK_SET);
      fread(&nome_2,sizeof(char),20,KP);
      fseek(KP,90,SEEK_SET);
      fread(&email_2,sizeof(char),30,KP);
      break;
   case 3: // L� NOME_3 E EMAIL_3
      fseek(KP,40,SEEK_SET);
      fread(&nome_3,sizeof(char),20,KP);
      fseek(KP,120,SEEK_SET);
      fread(&email_3,sizeof(char),30,KP);
      break;
   }
}

void escrever(int op)
{
   switch(op)
   {
   case 1: // ESCREVE NOME_1
      fseek(KP,0,SEEK_SET);
      fwrite(nome_1,1,20,KP);
      break;
   case 2: // ESCREVE NOME_2
      fseek(KP,20,SEEK_SET);
      fwrite(nome_2,1,20,KP);
      break;
   case 3: // ESCREVE NOME_3
      fseek(KP,40,SEEK_SET);
      fwrite(nome_3,1,20,KP);
      break;
   case 4: // ESCREVE EMAIL_1
      fseek(KP,60,SEEK_SET);
      fwrite(email_1,1,30,KP);
      break;
   case 5: // ESCREVE EMAIL_2
      fseek(KP,90,SEEK_SET);
      fwrite(email_2,1,30,KP);
      break;
   case 6: // ESCREVE EMAIL_3
      fseek(KP,120,SEEK_SET);
      fwrite(email_3,1,30,KP);
      break;
   }
}

int tamanho(int op)
{
   int i, resp;

   switch(op)
   {
   case 1: //VERIFICA O TAMANHO DE NOME
      if(nome_1[19] != '\0' || nome_2[19] != '\0' || nome_3[19] != '\0' || busca[19] != '\0')
      {
         resp = 1; // TAMANHO MAIOR QUE O LIMITE
      }
      else
      {
         resp = 0; // TAMANHO OK
      }
      break;
   case 2: //VERIFICA TAMANHO DO EMAIL
      if(email_1[29] != '\0' || email_2[29] != '\0' || email_3[29] != '\0')
      {
         resp = 1; // TAMANHO MAIOR QUE O LIMITE
      }
      else
      {
         resp = 0; // TAMANHO OK
      }
      break;
   }
   return (resp);
}

void ERRO(int op)
{
   system("cls");
   system("color 4F");
   printf("\n\t\t   *** ATEN��O ***\n\n");

   switch(op)
   {
   case 1: // OP��O INV�LIDA
      printf("\n\tOP��O INV�LIDA!!!\n");
      break;
   case 2: // BANCO DE DADOS CHEIO
      printf("\n\tN�o � poss�vel cadastrar mais que 3 clientes!!!\n");
      printf("\n\tExclua um cliente para poder cadastrar outro.\n\n");
      break;
   case 3: // TAMANHO MAIOR - NOME
      printf("\n\tO nome n�o pode ter mais que 19 caracteres!!!\n");
      break;
   case 4: // TAMANHO MAIOR - EMAIL
      printf("\n\tO email n�o pode ter mais que 29 caracteres!!!\n");
      break;
   case 5: // LISTA VAZIA
      printf("\n\tLISTA VAZIA!!!\n");
      printf("\n\tAinda n�o foi cadastrado nenhum cliente.\n\n");
      break;
   case 6: //CLIENTE N�O ENCONTRADO
      printf("\n\tCliente n�o encontrado!!!\n\n");
      break;
   case 7: // ALTERA��O CANCELADA
      printf("\n\t>>> ALTERA��O CANCELADA <<<\n\n");
      break;
   case 8: //EXCLUS�O CANCELADA
      printf("\n\t>>> EXCLUS�O CANCELADA <<<\n\n");
      break;
   }
}

void PAUSA()
{
   printf("\n\t");
   system("pause");
   system("cls");
}

void limpar(int op)
{
   int i;

   for(i=0; i<30; i++)
   {
      if(op == 1) // LIMPA NOME_1
      {
         nome_1[i] = '\0';
      }
      else if(op == 2) // LIMPA NOME_2
      {
         nome_2[i] = '\0';
      }
      else if(op == 3) // LIMPA NOME_3
      {
         nome_3[i] = '\0';
      }
      else if(op == 4) // LIMPA EMAIL_1
      {
         email_1[i] = '\0';
      }
      else if(op == 5) // LIMPA EMAIL_2
      {
         email_2[i] = '\0';
      }
      else if(op == 6) // LIMPA EMAIL_3
      {
         email_3[i] = '\0';
      }
      else // LIMPA BUSCA
      {
         busca[i] = '\0';
      }
   }
}

void converter(int op)
{
   int i;

   for(i=0;i<20;i++)
   {
      switch(op)
      {
      case 1:
         if(nome_1[i] >= 'a' && nome_1[i] <= 'z')
         {
            nome_1[i] = (nome_1[i]-'a')+'A';
         }
         break;
      case 2:
         if(nome_2[i] >= 'a' && nome_2[i] <= 'z')
         {
            nome_2[i] = (nome_2[i]-'a')+'A';
         }
         break;
      case 3:
         if(nome_3[i] >= 'a' && nome_3[i] <= 'z')
         {
            nome_3[i] = (nome_3[i]-'a')+'A';
         }
         break;
      case 4:
         if(busca[i] >= 'a' && busca[i] <= 'z')
         {
            busca[i] = (busca[i]-'a')+'A';
         }
         break;
      }
   }

   if(op == 5)
   {
      if(v >= 'a' && v <= 'z')
      {
         v = (v-'a')+'A';
      }
   }
}

void comparar()
{
   int a = 1, b = 1, c = 1, j;

   if(conferir(0) == 0)
   {
      ERRO(5); // LISTA VAZIA - ARQUIVO N�O EXISTE
   }
   else if(conferir(1) == 1 && conferir(2) == 1 && conferir(3) == 1)
   {
      ERRO(5); // LISTA VAZIA - ARQUIVO EXISTE POR�M N�O TEM CLIENTES
   }
   else
   {
      KP = fopen("clientes.txt","r+");

      if(conferir(1) == 2) // CONFERE NOME_1 PREENCHIDO
      {
         ler(1); // L� NOME_1

         converter(1);

         j = 0;

         while(j < 20 && a == 1) // COMPARA NOME_1 E BUSCA
         {
            if(busca[j] != nome_1[j])
            {
               a = 0; //BUSCA DIFERENTE NOME_1
            }
            else
            {
               j += 1;
            }
         }

         fs[0] = a; // RETORNA SE � IGUAL OU N�O
      }
      if(conferir(2) == 2) // CONFERE NOME_2 PREENCHIDO
      {
         ler(2); // L� NOME_2

         converter(2);

         j = 0;

         while(j < 20 && b == 1) // COMPARA NOME_2 E BUSCA
         {
            if(busca[j] != nome_2[j])
            {
               b = 0; //BUSCA DIFERENTE NOME_2
            }
            else
            {
               j += 1;
            }
         }

         fs[1] = b; // RETORNA SE � IGUAL OU N�O
      }
      if(conferir(3) == 2) // CONFERE NOME_3 PREENCHIDO
      {
         ler(3); // L� NOME_2

         converter(3);

         j = 0;

         while(j < 20 && c == 1) // COMPARA NOME_3 E BUSCA
         {
            if(busca[j] != nome_3[j])
            {
               c = 0; //BUSCA DIFERENTE NOME_3
            }
            else
            {
               j += 1;
            }
         }

         fs[2] = c; // RETORNA SE � IGUAL OU N�O
      }

      fclose(KP);
   }
}

#endif // desafio
