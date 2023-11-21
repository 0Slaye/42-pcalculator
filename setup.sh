#!/bin/bash

RC_FILE="$HOME/.zshrc"

# set up the alias
if ! grep "pcalculator=" "$RC_FILE" &> /dev/null; then
	printf "\nalias pcalculator=%s/pcalculator/pcalculator\n" "$HOME" >> "$RC_FILE"
	echo "Setup done."
fi