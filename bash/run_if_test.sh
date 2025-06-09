#!/bin/bash

INPUT_FILE="tests/if_test/if_test.c"
EXPECTED_FILE="tests/if_test/if_expected.txt"
OUTPUT=$(cat "$INPUT_FILE" | ./parser_exec)

EXPECTED=$(cat "$EXPECTED_FILE")

if diff -w -B /tmp/test_output.txt "$EXPECTED_FILE"; then
  echo "✅ Teste passou!"
else
  echo "❌ Teste falhou! Diferenças abaixo:"
  diff -w -B "$EXPECTED_FILE" /tmp/test_output.txt
fi
