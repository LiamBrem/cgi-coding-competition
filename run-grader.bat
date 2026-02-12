@echo off
REM Build the Docker image
docker build -t cgi-grader .

REM Run with custom question and language
REM Usage: run-grader.bat <question_number> <language>

set QUESTION=%1
set LANG=%2

if "%QUESTION%"=="" set QUESTION=1
if "%LANG%"=="" set LANG=python

docker run --rm cgi-grader --question %QUESTION% --lang %LANG%
