param(
    [int]$Question = 1,
    [string]$Lang = "python"
)

# Build the Docker image
docker build -t cgi-grader .

# Run with custom question and language
# Usage: .\run-grader.ps1 <question_number> <language>
docker run --rm cgi-grader --question $Question --lang $Lang