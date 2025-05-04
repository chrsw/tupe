#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <home_directory_path>"
  exit 1
fi

home_dir="$1"

find . -type f -print0 | while IFS= read -r -d $'\0' file; do
  if file "$file" | grep -qE 'text/plain|ASCII'; then
    grep -r -F "$home_dir" "$file"
  fi
done
