# CGI Coding Competition 
CSC + CGI

### CGI: Operation Trusted Outcomes 🔴

You are a newly recruited CGI Partner on your first week inside the Global Digital Response Team.

CGI operates across 400+ locations worldwide, delivering insights-driven IT solutions. But today, something unusual is happening.

A coordinated cyber event, codenamed "Shadow ROI," is attempting to disrupt CGI client systems across multiple industries. Financial services, healthcare, logistics, and energy sectors are at risk.

The leadership team activates an internal simulation:

"To protect our clients, you must demonstrate mastery of data, logic, and resilience. Each system you stabilize unlocks the next."

Each problem represents a real-world CGI challenge:
- Data validation
- Log analysis
- Decision modeling
- Infrastructure protection
- Strategic optimization

By solving each task, you'll restore part of CGI's global digital infrastructure.

*Are you up for the challenge?*

---

## Getting Started

> You need Docker installed. Get it [here](https://docs.docker.com/get-started/get-docker/)

**Clone the repo:**
```bash
git clone https://github.com/YOUR-USERNAME/cgi-coding-competition
cd cgi-coding-competition
```

Now you're ready to **START CODING!**

## How does it work 🤨

- Each question has its own folder (open up the 'questions' folder to see them).
- Each folder contains:
  - `description.md` - explains the problem
  - `Solution.java` - write your Java solution here
  - `solution.py` - write your Python solution here
- Choose your preferred language and write your code
- Run the autograder to test your solution
- Get a special code when you pass all tests!

## Running the Autograder

**Run the grader:**

Linux/macOS:
```bash
./run-grader-public.sh <question_number> <language>
```

Windows (Command Prompt):
```cmd
run-grader-public.bat <question_number> <language>
```

Windows (PowerShell):
```powershell
.\run-grader-public.ps1 <question_number> <language>
```

**Examples:**
```bash
# Test question 1 with Python
./run-grader-public.sh 1 python

# Test question 2 with Java
./run-grader-public.sh 2 java

# Test question 5 with Python
./run-grader-public.sh 5 python
```

**First run:** The Docker image will be automatically downloaded (this may take a minute).

**Subsequent runs:** Much faster since the image is cached locally!

## Example Output

```
Question 1 (python)
==============================

Test 1: PASS
Test 2: PASS
Test 3: FAIL (expected 42, got 41)

Score: 2/3
```

Fix your code and run again until all tests pass!

---

### [Submit Your Codes Here](YOUR-FORM-LINK)
### Good Luck! 🚀
