# Publishing Instructions for Organizers

This guide explains how to publish the autograder as a Docker image while keeping test cases hidden.

## Overview

The strategy is to:
1. Build a Docker image containing the grader executable and test cases
2. Publish that image to Docker Hub (or another registry)
3. Distribute a public repo WITHOUT the `/grader` folder
4. Participants run the pre-built image, mounting their local `questions/` folder

## Step 1: Build and Publish the Docker Image

**Important:** Build a multi-platform image to support both AMD64 (Linux/Windows) and ARM64 (Apple Silicon) architectures.

```bash
# Login to Docker Hub first
docker login

# Create and use a new buildx builder (first time only)
docker buildx create --name multiplatform --use

# Build and push multi-platform image
docker buildx build \
  --platform linux/amd64,linux/arm64 \
  -t your-dockerhub-username/cgi-grader:latest \
  --push \
  .

# Note: --push is required when building multi-platform images
```

**Alternative (simpler, but larger image):**
```bash
# If buildx doesn't work, build for AMD64 only (most common)
docker buildx build \
  --platform linux/amd64 \
  -t your-dockerhub-username/cgi-grader:latest \
  --push \
  .
```

## Step 2: Create Public Repository

Create a copy of this repository that excludes:
- The `/grader` folder (contains source code and test cases)
- Solution files from `/questions/*/` folders

### Files to include in public repo:
```
questions/
  q1/
    description.md
    Solution.java
    solution.py
  q2/
    ...
run-grader-public.sh
run-grader-public.bat
run-grader-public.ps1
README.md (update with public instructions)
.dockerignore
```

### Create the public repo:

```bash
# In a new directory
mkdir cgi-coding-competition-public
cd cgi-coding-competition-public

# Copy necessary files
cp -r ../cgi-coding-competition/questions .
cp ../cgi-coding-competition/run-grader-public.* .
cp ../cgi-coding-competition/README.md .

# Remove any existing solutions (optional, if you want to provide starter code)
# Or keep them as templates

# Initialize git
git init
git add .
git commit -m "Initial public release"
git remote add origin https://github.com/yourusername/cgi-coding-competition-public.git
git push -u origin main
```

## Step 3: Update Public Scripts

Edit the public run scripts to reference your published Docker image:

In `run-grader-public.sh`, `run-grader-public.bat`, and `run-grader-public.ps1`, update:
```bash
IMAGE_NAME="your-dockerhub-username/cgi-grader:latest"
```

## Step 4: Update Public README

Update the README.md in the public repo to:
1. Remove the "Build the image" step
2. Reference the public run scripts instead
3. Mention that the image will be automatically pulled on first run

See example below:

```markdown
## How to Run the Autograder

> You need Docker installed. Get it [here](https://docs.docker.com/get-started/get-docker/)

**Clone the repo:**
\`\`\`bash
git clone https://github.com/yourusername/cgi-coding-competition-public
cd cgi-coding-competition-public
\`\`\`

**Write your solution:**
- Open either `Solution.java` or `solution.py` in the question folder
- Read `description.md` for the problem details

**Run the autograder:**

Linux/macOS:
\`\`\`bash
./run-grader-public.sh 1 python
\`\`\`

Windows (Command Prompt):
\`\`\`cmd
run-grader-public.bat 1 python
\`\`\`

Windows (PowerShell):
\`\`\`powershell
.\run-grader-public.ps1 1 python
\`\`\`

The Docker image will be automatically downloaded on first run.
```

## Security Notes

✅ **What's hidden:**
- Test case inputs and expected outputs (baked into the Docker image)
- Grader source code
- Test harness logic

✅ **What's public:**
- Question descriptions
- Solution template files
- Run scripts

⚠️ **Important:** The Docker image is binary, but determined participants could potentially:
- Extract the image layers
- Reverse engineer the grader executable
- Find test cases

For a competitive coding environment, this level of security is usually sufficient since the effort to reverse engineer typically exceeds the benefit.

## Updating the Grader

When you need to update test cases or fix bugs:

```bash
# Make changes to grader source or test cases
cd cgi-coding-competition

# Rebuild and push new multi-platform version
docker buildx build \
  --platform linux/amd64,linux/arm64 \
  -t your-dockerhub-username/cgi-grader:latest \
  --push \
  .

# Users will automatically get the new version on next pull
# Or they can force update with:
# docker pull your-dockerhub-username/cgi-grader:latest
```

## Testing Before Publishing

Test that the volume mounting works correctly:

```bash
# Build the image
docker build -t cgi-grader:latest .

# Test with volume mount (simulating public usage)
docker run --rm -v "$(pwd)/questions:/app/questions:ro" cgi-grader:latest --question 1 --lang python
```

If this works, publishing will work too!
