#!/usr/bin/env pwsh

# Public runner script - uses pre-built Docker image
# Usage: .\run-grader-public.ps1 <question_number> <language>

$IMAGE_NAME = "liambrem/cgi-grader:latest"

$QUESTION = if ($args[0]) { $args[0] } else { "1" }
$LANG = if ($args[1]) { $args[1] } else { "python" }

docker run --rm `
  -v "${PWD}/questions:/app/questions:ro" `
  $IMAGE_NAME `
  --question $QUESTION --lang $LANG
