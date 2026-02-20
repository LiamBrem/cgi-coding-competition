@echo off
REM Public runner script - uses pre-built Docker image
REM Usage: run-grader-public.bat <question_number> <language>

REM Change this to your published image name (e.g., yourdockerhub/cgi-grader:latest)
set IMAGE_NAME=liambrem/cgi-grader:latest

set QUESTION=%1
set LANG=%2

if "%QUESTION%"=="" set QUESTION=1
if "%LANG%"=="" set LANG=python

docker run --rm -v "%cd%/questions:/app/questions:ro" %IMAGE_NAME% --question %QUESTION% --lang %LANG%
