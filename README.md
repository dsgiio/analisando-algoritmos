# analisando-algoritmos
Trabalho para a matéria de Estrutura de Dados


# INSTRUÇÕES COPILAR
cd src
gcc *.c -I ../include -o programa.exe
./programa.exe


# Estrutura dos Arquivos

### `arquivos.c / arquivos.h`
- Lê os números do arquivo `dados.txt`  
- Salva os tempos de execução em `resultados.csv`

### `utils.c / utils.h`
- Copia vetores para garantir testes iguais para todos os algoritmos

###  `ordenacao.c / ordenacao.h`
- **Cada integrante adiciona seu algoritmo aqui**
- Inserir **declaração** no `.h`  
- Inserir **implementação** no `.c`

###  `main.c`
- Controla o fluxo dos testes
- Mede tempos usando `clock()`
- Chama o algoritmo definido pelos integrantes

---

# Como adicionar seu algoritmo

1 - Adicione o nome da sua função no `ordenacao.h`:
```c
void quickSort(int* v, int left, int right);

2 - Implemente a função no ordenacao.c

3 - No main.c, chame sua função:
quickSort(vetor, 0, tamanho - 1);


# Arquivo de entrada
O arquivo dados.txt contém os números usados em todos os testes.
Ele é lido automaticamente.

# Resultados
Após executar, o arquivo: resultados.csv
terá o tempo de cada execução.

Abra no Excel → Inserir gráfico → Compare os algoritmos.