#!/bin/bash

# Nome do executável gerado pelo Makefile
COMPILADOR="./compilador"

# Arquivos de teste
INPUT_FILE="tests/if_test/if_test.c"
EXPECTED_FILE="tests/if_test/if_expected.txt"
TEMP_OUTPUT="/tmp/test_output.txt"

# Verifica se o compilador existe
if [ ! -f "$COMPILADOR" ]; then
    echo "Erro: Compilador '$COMPILADOR' não encontrado. Compile o projeto com 'make' primeiro."
    exit 1
fi

# Executa o compilador, redirecionando a saída para um arquivo temporário
cat "$INPUT_FILE" | $COMPILADOR > "$TEMP_OUTPUT"

# Compara a saída gerada com a saída esperada, ignorando diferenças de espaço em branco
if diff -w -B "$TEMP_OUTPUT" "$EXPECTED_FILE"; then
  echo "✅ Teste passou!"
  # rm $TEMP_OUTPUT # Descomente para limpar o arquivo temporário em caso de sucesso
else
  echo "❌ Teste falhou! Diferenças abaixo (Esperado vs. Obtido):"
  diff --side-by-side -W 200 "$EXPECTED_FILE" "$TEMP_OUTPUT"
fi
