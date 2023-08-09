#!/bin/bash

# Check that $PYFILE is set with the Python file name
if [ -z "$PYFILE" ]
then
    echo "Please set the PYFILE environment variable with the Python script name" >&2
    exit 1
fi

# Run the Python script
python $PYFILE
