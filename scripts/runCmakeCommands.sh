#!/bin/bash
output=$(cd build && cmake .. 2>&1)
if [[ "$output" == *"Generating done"* ]]; then
    make -C build
fi
