#!/bin/bash

# Build the Docker image
docker build -t cgi-grader .

# Run with custom question and language
# Usage: ./run-grader.sh <question_number> <language>
QUESTION=${1:-1}
LANG=${2:-python}

docker run --rm cgi-grader --question $QUESTION --lang $LANG
