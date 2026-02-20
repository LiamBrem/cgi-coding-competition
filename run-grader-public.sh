#!/bin/bash

# Public runner script - uses pre-built Docker image
# Usage: ./run-grader-public.sh <question_number> <language>

# Change this to your published image name (e.g., yourdockerhub/cgi-grader:latest)
IMAGE_NAME="liambrem/cgi-grader:latest"

QUESTION=${1:-1}
LANG=${2:-python}

# Mount the local questions directory into the container
docker run --rm \
  -v "$(pwd)/questions:/app/questions:ro" \
  $IMAGE_NAME \
  --question $QUESTION --lang $LANG
