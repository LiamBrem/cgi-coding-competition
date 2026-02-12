# Build the Docker image
docker build -t cgi-grader .

# Run with custom question and language
# Usage: .\run-grader.ps1 <question_number> <language>

param(
    [int]$Question = 1,
    [string]$Lang = "python"
)

docker run --rm cgi-grader --question $Question --lang $Lang
