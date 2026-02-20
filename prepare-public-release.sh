#!/bin/bash

# Script to prepare a public release of the competition
# This creates a copy without the grader source code

set -e

PUBLIC_DIR="../cgi-coding-competition-public"

echo "Creating public release directory..."
mkdir -p "$PUBLIC_DIR"

echo "Copying questions directory..."
cp -r questions "$PUBLIC_DIR/"

echo "Copying public run scripts..."
cp run-grader-public.sh "$PUBLIC_DIR/"
cp run-grader-public.bat "$PUBLIC_DIR/"
cp run-grader-public.ps1 "$PUBLIC_DIR/"

echo "Copying README..."
cp README.md "$PUBLIC_DIR/README.md"

echo "Copying .dockerignore (optional)..."
[ -f .dockerignore ] && cp .dockerignore "$PUBLIC_DIR/" || true

echo ""
echo "Public release created at: $PUBLIC_DIR"
echo ""
echo "Next steps:"
echo "1. Update IMAGE_NAME in the public run scripts with your Docker Hub username"
echo "2. Update the form link in README.md"
echo "3. Optionally remove or reset solution files in questions/*/"
echo "4. Initialize git repo and push to GitHub"
echo ""
echo "Commands:"
echo "  cd $PUBLIC_DIR"
echo "  # Edit run-grader-public.* files to set IMAGE_NAME"
echo "  git init"
echo "  git add ."
echo "  git commit -m 'Initial public release'"
echo "  git remote add origin YOUR_REPO_URL"
echo "  git push -u origin main"
