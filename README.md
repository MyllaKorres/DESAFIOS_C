# DESAFIOS – LINGUAGEM DE PROGRAMAÇÃO 🐱‍💻

------

​																		2º SEMESTRE DE 2020

------

## <u>INSTRUÇÕES PROGRAMA  DESAFIO  1</u>

1) Pesquise as funções de biblioteca abaixo que manipulam arquivos.

​       fopen();

​      fclose();

​      fwrite();

​      fread();

​	  fseek(); 

​	  exit(0);

2) Escreva um programa que tenha **3 vetores nome[20]** e **3 vetores email[30]** declaradas como variáveis globais. 
Na função main() faça um menu com as seguintes funções: 

​	  1 – entrada de dados.

​	  2 – lista todos os dados na tela.

​	  3 – pesquisa um nome e mostra na tela

  	4 – pesquisa os nomes pela 1º letra e mostra todos na tela.

  	5 – altera  dados.

  	6 – exclui dados.

  	7 – saída

**Obs.:** O programa deve ser finalizado pelo usuário.

**Obs.:** Os 6 vetores devem ser escritos e lidos de um arquivo.

------

## <u>INSTRUÇÕES PROGRAMA  DESAFIO  2</u>

1) Escreva um programa que tem a estrutura de dados abaixo. O programa tem as seguintes opções:

  	1 – entra produto.

  	2 – lista produtos na tela.

  	3 – pesquisa um produto pelo nome.

  	4 – pesquisar um produto pela 1. letra do nome.

  	5 – pesquisar data de validade (mês/ano)

  	6 – lista os produtos abaixo do estoque mínimo

  	7 – movimenta quantidade em estoque (entrada e saída).

  	8 – altera produto pesquisado pelo nome completo.

  	9 – exclui produto pesquisado pelo nome completo.

  	10 – saída pelo usuário

**Estrutura:** nome, quantidade atual, quantidade de estoque mínimo, data de validade do produto. 

A única estrutura de dados do programa deve ser variável local na função main(). Portanto a passagem da estrutura para as funções utiliza ponteiro.

Cada uma das opções do menu é uma função no programa.

Todas as operações devem ser feitas direto no arquivo. (utilize a função fseek).

O programa tem um único arquivo de dados. Não pode usar nenhum arquivo auxiliar.

O programa deve ser finalizado pelo usuário.

Não pode usar nenhuma função de biblioteca. Somente as funções de manipulação de arquivos.