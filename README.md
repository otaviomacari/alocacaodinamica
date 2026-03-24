# 📊 Sistema de Processamento de Notas em C

Um programa em linguagem C que realiza a leitura de um arquivo CSV contendo dados de alunos e suas respectivas notas, processa essas informações e gera um relatório completo com médias individuais e média geral da turma.

---

## 📌 Visão Geral

Este projeto demonstra conceitos fundamentais da linguagem C, incluindo:

- Estruturas (`struct`)
- Alocação dinâmica de memória (`malloc` / `free`)
- Manipulação de arquivos
- Processamento de strings

O sistema lê um arquivo `notas.csv`, interpreta os dados e exibe um relatório detalhado no terminal.

---

## 📂 Formato do Arquivo

O arquivo `notas.csv` deve estar no mesmo diretório do programa.

### Formato esperado:
```
Nome,Nota1,Nota2,Nota3,...
```

### Exemplo:
```
Joao,7.5,8.0,6.5
Maria,9.0,8.5,10.0,7.5
Carlos,5.0,6.0
```

---

## ⚙️ Funcionalidades

- Leitura de dados a partir de arquivo CSV
- Contagem automática de alunos
- Alocação dinâmica de memória para notas
- Cálculo de média individual por aluno
- Cálculo de média global da turma
- Impressão de relatório no terminal
- Liberação de memória (boas práticas)

---

## 🏗️ Estrutura

### Struct principal

```c
typedef struct {
    char nome[50];
    float *nota;
    int num_notas;
} Aluno;
```

---

## 🔧 Funções

- `contar_linhas()`: Conta quantos alunos existem no arquivo
- `carregar_dados()`: Lê e processa o CSV
- `imprimir_relatorio()`: Exibe os resultados
- `liberar()`: Libera a memória alocada

---

## ▶️ Compilação

```bash
gcc main.c -o programa
```

---

## ▶️ Execução

```bash
./programa
```

---

## 🖥️ Exemplo de Saída

```
===== RELATORIO DE NOTAS =====

Aluno: Joao
Nota 1: 7.50
Nota 2: 8.00
Nota 3: 6.50
Media: 7.33

Media global da turma: 7.33
```

---

## ⚠️ Limitações

- Não há validação de dados no arquivo
- Pode falhar com entradas mal formatadas
- Não trata erros detalhadamente

---

## 🚀 Melhorias Futuras

- Validação de entrada
- Ordenação por média
- Exportação para arquivo
- Estatísticas adicionais

---

## 🧠 Conceitos Aplicados

- Ponteiros
- Alocação dinâmica
- Manipulação de arquivos
- Estruturas em C

---

## 📄 Licença

Uso livre para fins acadêmicos e educacionais.
