//Anthony Clint Pastorello - RA: 0050482011005
//Mylla Cristhina Rodrigues da Costa Abreu Korres - RA: 0050482011032

#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

/*
   1 - Escreva um programa que tem a estrutura de dados abaixo. O programa tem as seguintes opções:

      1 – entra produto.
      2 – lista produtos na tela.
      3 – pesquisa um produto pelo nome.
      4 – pesquisar um produto pela 1. letra do nome.
      5 – pesquisar data de validade (mês/ano)
      6 – lista os produtos abaixo do estoque mínimo
      7 – movimenta quantidade em estoque (entrada e saída).
      8 – altera produto pesquisado pelo nome completo.
      9 – exclui produto pesquisado pelo nome completo.
      10 - saída pelo usuário

   Estrutura: nome, quantidade atual, quantidade de estoque mínimo, data de validade do produto.

   A única estrutura de dados do programa deve ser variável local na função main(). Portanto a passagem da estrutura para as funções utiliza ponteiro.

   Cada uma das opções do menu é uma função no programa.

   Todas as operações devem ser feitas direto no arquivo. (utilize a funcao fseek).

   O programa tem um único arquivo de dados. Não pode usar nenhum arquivo auxiliar.

   O programa deve ser finalizado pelo usuário.

   Não pode usar nenhuma função de biblioteca. Somente as funções de manipulação de arquivos.

*/

struct dados
{
   unsigned char nome[20];
   char dt_val[6];
   int qnt_min;
   int qnt_atual;
};

void INCLUIR(struct dados *p, FILE *KP);

void LISTAR(struct dados *p, FILE *KP);

int PESQUISAR(struct dados *p, FILE *KP); // PESQUISA PELO NOME

void BUSCAR(struct dados *p, FILE *KP); // BUSCA PELA 1ª LETRA DO NOME

void CONSULTAR(struct dados *p, FILE *KP); // CONSULTA A DATA DE VALIDADE

void LIMITE(struct dados *p, FILE *KP); // LISTA PRODUTOS ABAIXO DA QNT. MÍN.

void QUANTIDADE(struct dados *p, FILE *KP); // MOVIMENTA QNT. DE PRODUTOS

void ALTERAR(struct dados *p, FILE *KP);

void EXCLUIR(struct dados *p, FILE *KP);

void SAIR();

void ERRO(int x);

void LIMPAR(struct dados *p);

void main()
{
   int op;

   struct dados produtos;

   struct dados *p;

   p = &produtos;

   FILE *KP;

   for(;;)
   {
      system("color 1F");

      printf("\n\n\t\t\t>>> MENU <<<\n\n\n");

      printf("\t\t 1 - INCLUIR PRODUTOS\n\n");
      printf("\t\t 2 - LISTAR PRODUTOS\n\n");
      printf("\t\t 3 - PESQUISAR PRODUTO PELO NOME\n\n");
      printf("\t\t 4 - PESQUISAR PRODUTO PELA INICIAL\n\n");
      printf("\t\t 5 - PESQUISAR PRODUTO PELA VALIDADE\n\n");
      printf("\t\t 6 - LISTAR PRODUTOS COM BAIXO ESTOQUE\n\n");
      printf("\t\t 7 - MOVIMENTAR QUANTIDADE EM ESTOQUE\n\n");
      printf("\t\t 8 - ALTERAR PRODUTOS\n\n");
      printf("\t\t 9 - EXCLUIR PRODUTOS\n\n");
      printf("\t\t10 - SAIR\n\n");

      printf("\n\n\t\tESCOLHA: ");
      scanf("%d",&op);
      getchar();

      switch (op)
      {
      case 1:
         INCLUIR(p, KP);
         break;
      case 2:
         LISTAR(p, KP);
         break;
      case 3:
         PESQUISAR(p, KP); // PESQUISA PELO NOME
         break;
      case 4:
         BUSCAR(p, KP); // BUSCA PELA 1ª LETRA DO NOME
         break;
      case 5:
         CONSULTAR(p, KP); // CONSULTA A DATA DE VALIDADE
         break;
      case 6:
         LIMITE(p, KP); // LISTA PRODUTOS ABAIXO DA QNT. MÍN.
         break;
      case 7:
         QUANTIDADE(p, KP); // MOVIMENTA QNT. DE PRODUTOS
         break;
      case 8:
         ALTERAR(p, KP);
         break;
      case 9:
         EXCLUIR(p, KP);
         break;
      case 10:
         SAIR();
         break;
      default:
         ERRO(1); // VALOR INVÁLIDO
      }

      system("pause");
      system("cls");
   }
}

void INCLUIR(struct dados *p, FILE *KP)
{
   system("cls");

   KP = fopen("controle.txt","a");

   LIMPAR(p);

   printf("\n\n\t\t\t>>> CADASTRO DE PRODUTO <<<\n\n");

   printf("\n\t\tInsira o nome do produto: ");
   gets(p->nome);

   do
   {
      printf("\n\n\t\tInsira a quantidade do produto: ");
      scanf("%d",&p->qnt_atual);

      if(p->qnt_atual < 0)
      {
         ERRO(1); // VALOR INVÁLIDO

         system("pause");
         system("cls");
         system("color 1F");

         printf("\n\n\t\t\t>>> CADASTRO DE PRODUTO <<<\n\n");

         printf("\n\t\tInsira o nome do produto: %s\n", p->nome);
      }
   }while(p->qnt_atual < 0);

   do
   {
      printf("\n\n\t\tInsira a quantidade minima do produto: ");
      scanf("%d",&p->qnt_min);

      if(p->qnt_min < 0)
      {
         ERRO(1); // VALOR INVÁLIDO

         system("pause");
         system("cls");
         system("color 1F");

         printf("\n\n\t\t\t>>> CADASTRO DE PRODUTO <<<\n\n");

         printf("\n\t\tInsira o nome do produto: %s\n", p->nome);
         printf("\n\n\t\tInsira a quantidade do produto: %d\n", p->qnt_atual);
      }
   }while(p->qnt_min < 0);

   printf("\n\n\t\tInsira a data de validade (MM/AA) do produto: ");
   getchar();
   gets(p->dt_val);

   fwrite(p,sizeof(*p),1,KP);

   fclose(KP);

   printf("\n\n\t\t");
}

void LISTAR(struct dados *p, FILE *KP)
{
   int i;

   KP = fopen("controle.txt","r");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      system("cls");

      printf("\n\n\t\t\t>>> LISTA DE PRODUTOS <<<\n\n");

      printf("\n\t\t __________________________________________________________");
      printf("\n\t\t|                      |            |           |          |");
      printf("\n\t\t|         NOME         | QNT. ATUAL | QNT. MIN. | VALIDADE |");
      printf("\n\t\t|______________________|____________|___________|__________|");

      for(;;)
      {
         i = fread(p,sizeof(*p),1,KP);

         if(i == 1)
         {
            if(p->nome[0] != '*')
            {
               printf("\n\t\t|                      |            |           |          |");
               printf("\n\t\t| %-20s |    %-5d   |    %-5d  |  %-6s  |", p->nome, p->qnt_atual, p->qnt_min, p->dt_val);
               printf("\n\t\t|______________________|____________|___________|__________|");
            }
         }
         else
         {
            break;
         }
      }

      fclose(KP);

      printf("\n\n\n\n\t\t");
   }
}

int PESQUISAR(struct dados *p, FILE *KP)
{
   int i, j, cont = 0;
   unsigned char pesq[20] = "\0";

   KP = fopen("controle.txt","r");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      system("cls");

      printf("\n\n\t\t\t>>> PESQUISA DE PRODUTO <<<\n\n");

      printf("\n\t\tInsira o nome do produto: ");
      gets(pesq);

      for(;;)
      {
         i = fread(p,sizeof(*p),1,KP);

         if(i == 1)
         {
            if(p->nome[0] != '*')
            {
               for (j = 0; p->nome[j] != '\0'; j++)
               {
                  if (p->nome[j] != pesq[j])
                  {
                     break;
                  }
               }
            }

            cont++;

            if (p->nome[j] == '\0' && pesq[j] == '\0')
            {
               printf("\n\t\t __________________________________________________________");
               printf("\n\t\t|                      |            |           |          |");
               printf("\n\t\t|         NOME         | QNT. ATUAL | QNT. MIN. | VALIDADE |");
               printf("\n\t\t|______________________|____________|___________|__________|");
               printf("\n\t\t|                      |            |           |          |");
               printf("\n\t\t| %-20s |    %-5d   |    %-5d  |  %-6s  |", p->nome, p->qnt_atual, p->qnt_min, p->dt_val);
               printf("\n\t\t|______________________|____________|___________|__________|\n\n\n\t\t");

               fclose(KP);

               return (cont);
            }
         }
         else
         {
            break;
         }
      }

      ERRO(3); // PRODUTO NÃO ENCONTRADO

      fclose(KP);

      return (-1);
   }
}

void BUSCAR(struct dados *p, FILE *KP)
{
   int i, cont=0;
   unsigned char busca ;

   KP = fopen("controle.txt","r");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      system("cls");

      printf("\n\n\t\t\t>>> PESQUISA DE PRODUTO PELA INICIAL <<<\n\n");

      printf("\n\t\tInsira a primeira letra do nome do produto: ");
      busca = getchar();

      for(;;)
      {
         i = fread(p,sizeof(*p),1,KP);

         if(i == 1)
         {
            if(p->nome[0] != '*')
            {
               if (p->nome[0] == busca)
               {
                  if(cont == 0)
                  {
                     printf("\n\t\t __________________________________________________________");
                     printf("\n\t\t|                      |            |           |          |");
                     printf("\n\t\t|         NOME         | QNT. ATUAL | QNT. MIN. | VALIDADE |");
                     printf("\n\t\t|______________________|____________|___________|__________|");

                     cont++;
                  }

                  printf("\n\t\t|                      |            |           |          |");
                  printf("\n\t\t| %-20s |    %-5d   |    %-5d  |  %-6s  |", p->nome, p->qnt_atual, p->qnt_min, p->dt_val);
                  printf("\n\t\t|______________________|____________|___________|__________|");
               }
            }
         }
         else
         {
            break;
         }
      }

      printf("\n\n\n\n\t\t");

      if(cont == 0)
      {
         ERRO(3); // PRODUTO NÃO ENCONTRADO
      }

      fclose(KP);
   }
}

void CONSULTAR(struct dados *p, FILE *KP)
{
   int i, j, cont=0;
   char validade[6];

   KP = fopen("controle.txt","r");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      system("cls");

      printf("\n\n\t\t\t>>> PESQUISA DE PRODUTO PELA VALIDADE <<<\n\n");

      printf("\n\t\tInsira a data de validade (MM/AA): ");
      gets(validade);

      for(;;)
      {
         i = fread(p,sizeof(*p),1,KP);

         if(i == 1)
         {
            if(p->nome[0] != '*')
            {
               for (j = 0; p->dt_val[j] != '\0'; j++)
               {
                  if (p->dt_val[j] != validade[j])
                  {
                     break;
                  }
               }

               if(p->dt_val[j] == '\0' && validade[j] == '\0')
               {
                  if(cont == 0)
                  {
                     printf("\n\t\t __________________________________________________________");
                     printf("\n\t\t|                      |            |           |          |");
                     printf("\n\t\t|         NOME         | QNT. ATUAL | QNT. MIN. | VALIDADE |");
                     printf("\n\t\t|______________________|____________|___________|__________|");

                     cont++;
                  }

                  printf("\n\t\t|                      |            |           |          |");
                  printf("\n\t\t| %-20s |    %-5d   |    %-5d  |  %-6s  |", p->nome, p->qnt_atual, p->qnt_min, p->dt_val);
                  printf("\n\t\t|______________________|____________|___________|__________|");
               }
            }
         }
         else
         {
            break;
         }
      }

      printf("\n\n\n\n\t\t");

      fclose(KP);

      if(cont == 0)
      {
         ERRO(3); // PRODUTO NÃO ENCONTRADO
      }
   }
}

void LIMITE(struct dados *p, FILE *KP)
{
   int i, cont = 0;

   KP = fopen("controle.txt","r");

   if(KP == NULL )
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      for(;;)
      {
         i = fread(p,sizeof(*p),1,KP);

         if(i == 1)
         {
            if(p->nome[0] != '*')
            {
               if(p->qnt_atual < p->qnt_min)
               {
                  cont++;
               }
            }
         }
         else
         {
            break;
         }
      }

      if(cont == 0)
      {
         ERRO(2); // LISTA VAZIA
      }
      else
      {
         system("cls");

         printf("\n\n\t\t\t>>> LISTA DE PRODUTOS INDISPONIVEIS <<<\n\n");

         printf("\n\t\t __________________________________________________________");
         printf("\n\t\t|                      |            |           |          |");
         printf("\n\t\t|         NOME         | QNT. ATUAL | QNT. MIN. | VALIDADE |");
         printf("\n\t\t|______________________|____________|___________|__________|");

         fseek(KP,0,0);

         for(;;)
         {
            i = fread(p,sizeof(*p),1,KP);

            if(i == 1)
            {
               if(p->nome[0] != '*')
               {
                  if(p->qnt_atual < p->qnt_min)
                  {
                     printf("\n\t\t|                      |            |           |          |");
                     printf("\n\t\t| %-20s |    %-5d   |    %-5d  |  %-6s  |", p->nome, p->qnt_atual, p->qnt_min, p->dt_val);
                     printf("\n\t\t|______________________|____________|___________|__________|");
                  }
               }
            }
            else
            {
               break;
            }
         }

         printf("\n\n\n\n\t\t");

         fclose(KP);
      }
   }
}

void QUANTIDADE(struct dados *p, FILE *KP)
{
    int k, y, alt;
   KP = fopen("controle.txt","r+");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      k = PESQUISAR(p, KP);

      if(k == -1)
      {
         system("pause");

         ERRO(4); // PROCESSO CANCELADO
      }
      else
      {
         LIMPAR(p);

         KP = fopen("controle.txt","r+");

         y = sizeof(*p)*(k-1);

         fseek(KP,y,0);

         fread(p,sizeof(*p),1,KP);


         do
         {
            fseek(KP,y,0);
            fread(p,sizeof(*p),1,KP);

            printf("\n\t\t\t>>> ALTERA QUANTIDADE DE PRODUTO <<<\n\n");

            printf("\n\n\t\tInsira o acrescimo ou decrescimo: ");
            scanf("%d",&alt);

            p->qnt_atual += alt;

            if((*p).qnt_atual < 0)
            {
               ERRO(5); // ESTOQUE NEGATIVO

               system("pause");
               system("cls");
               system("color 1F");
            }
         }while((*p).qnt_atual < 0);

         y = sizeof(*p)*(k-1);

         fseek(KP,y,0);

         fwrite(p,sizeof(*p),1,KP);

         fclose(KP);

         printf("\n\n\n\t\t");
      }
   }
}

void ALTERAR(struct dados *p, FILE *KP)
{
   int k, y;

   KP = fopen("controle.txt","r+");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      k = PESQUISAR(p, KP);

      if(k == -1)
      {
         system("pause");

         ERRO(4); // PROCESSO CANCELADO
      }
      else
      {
         LIMPAR(p);

         printf("\t\t\t>>> ALTERA PRODUTO <<<\n\n");

         printf("\n\t\tInsira o nome do produto: ");
         gets(p->nome);

         do
         {
         printf("\n\n\t\tInsira a quantidade do produto: ");
         scanf("%d",&p->qnt_atual);

         if(p->qnt_atual < 0)
         {
            ERRO(1); // VALOR INVÁLIDO

            system("pause");
            system("cls");
            system("color 1F");

            printf("\n\n\t\t\t>>> CADASTRO DE PRODUTO <<<\n\n");

            printf("\n\t\tInsira o nome do produto: %s\n", p->nome);
         }
         }while(p->qnt_atual < 0);

         do
         {
            printf("\n\n\t\tInsira a quantidade minima do produto: ");
            scanf("%d",&p->qnt_min);

            if(p->qnt_min < 0)
            {
               ERRO(1); // VALOR INVÁLIDO

               system("pause");
               system("cls");
               system("color 1F");

               printf("\n\n\t\t\t>>> CADASTRO DE PRODUTO <<<\n\n");

               printf("\n\t\tInsira o nome do produto: %s\n", p->nome);
               printf("\n\n\t\tInsira a quantidade do produto: %d\n", p->qnt_atual);
            }
         }while(p->qnt_min < 0);

         printf("\n\n\t\tInsira a data de validade (MM/AA) do produto: ");
         getchar();
         gets(p->dt_val);

         KP = fopen("controle.txt","r+");

         y = sizeof(*p)*(k-1);

         fseek(KP,y,0);

         fwrite(p,sizeof(*p),1,KP);

         fclose(KP);

         printf("\n\n\t\t");
      }
   }
}

void EXCLUIR(struct dados *p, FILE *KP)
{
   int k, y;

   KP = fopen("controle.txt","r+");

   if(KP == NULL)
   {
      ERRO(2); // LISTA VAZIA
   }
   else
   {
      k = PESQUISAR(p, KP);

      if(k == -1)
      {
         system("pause");

         ERRO(4); // PROCESSO CANCELADO
      }
      else
      {
         LIMPAR(p);

         p->nome[0] = '*';
         p->qnt_atual = 0;
         p->qnt_min = 0;
         p->dt_val[0] = '*';

         KP = fopen("controle.txt","r+");

         y = sizeof(*p)*(k-1);

         fseek(KP,y,0);

         fwrite(p,sizeof(*p),1,KP);

         fclose(KP);

         printf("\n\t\t\t>>> PRODUTO EXCLUIDO <<<\n\n");

         printf("\n\n\t\t");
      }
   }
}

void SAIR()
{
   system("cls");
   system("color 70");

   printf("\n\n\n\n\n\n\n\n\n\n");
   printf("\n\t\t\t>>> PROGRAMA FINALIZADO <<<\n\n\n");
   printf("\n\n\n\n\n\n\n\n\n\n\n\n");

   exit(0);
}

void ERRO(int x)
{
   system("cls");
   system("color 4F");

   if(x == 1)
   {
      printf("\n\n\t\t\t>>> ERRO <<<\n\n\n");
      printf("\n\t\tVALOR INVALIDO!!!\n\n\n\n\t\t");
   }
   else if (x == 2)
   {
      printf("\n\n\t\t\t>>> ERRO <<<\n\n\n");
      printf("\n\t\tLISTA VAZIA!!!\n\n\n\n\t\t");
   }
   else if (x == 3)
   {
      printf("\n\n\t\t\t>>> ERRO <<<\n\n\n");
      printf("\n\t\tPRODUTO NAO ENCONTRADO!!!\n\n\n\n\t\t");
   }
   else if (x == 4)
   {
      printf("\n\n\t\t\t>>> ERRO <<<\n\n\n");
      printf("\n\t\tPROCESSO CANCELADO!!!\n\n\n\n\t\t");
   }
   else
   {
      printf("\n\n\t\t\t>>> ERRO <<<\n\n\n");
      printf("\n\t\tO ESTOQUE NAO PODE SER NEGATIVO!!!\n\n\n\n\t\t");
   }
}

void LIMPAR(struct dados *p)
{
   int i;

   for(i=0; i<20; i++)
   {
      p->nome[i] = '\0'; // LIMPA CÓDIGO PRODUTO

      p->dt_val[i] = '\0'; // LIMPA DESCRIÇÃO PRODUTO
   }
}
