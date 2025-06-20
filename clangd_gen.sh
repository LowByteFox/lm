#!/bin/sh

cat > .clangd <<EOF
CompileFlags:
  Add: [-xc, -I$(pwd)/include/, -nostdinc, -nostdlibinc]

Completion:
  HeaderInsertion: Never
EOF
