# CGI Coding Competition 
CSC + CGI

### CGI: Operation Trusted Outcomes 🔴

You are a newly recruited CGI Partner on your first week inside the Global Digital Response Team.

CGI operates across 400+ locations worldwide, delivering insights-driven IT solutions. But today, something unusual is happening.

A coordinated cyber event, codenamed “Shadow ROI,” is attempting to disrupt CGI client systems across multiple industries. Financial services, healthcare, logistics, and energy sectors are at risk.

The leadership team activates an internal simulation:

“To protect our clients, you must demonstrate mastery of data, logic, and resilience. Each system you stabilize unlocks the next.”

Each problem represents a real-world CGI challenge:
- Data validation
- Log analysis
- Decision modeling
- Infrastructure protection
- Strategic optimization

By solving each task, you'll restore part of CGI’s global digital infrastructure.

*Are you up for the challenge?*

---

## Getting Started

### Running in Codespaces:

Click the green codespace button in the top right corner and create a new codespace.

### Running Locally:

> if you don't have docker install it [here](https://docs.docker.com/get-started/get-docker/)

**Clone the repo:**
```bash
git clone https://github.com/LiamBrem/cgi-coding-competition-public
```

**CD into the folder:**
```bash
cd cgi-coding-competition
```

**Build the image:**
```bash
docker build -t cgi-grader .
```

**Run the grader:**
```bash
docker run --rm cgi-grader --question 1 --lang python
```

Or use the helper script below ⬇️

Now you're ready to **START CODING!**

## How does it work 🤨

- Each question has it's own folder (as you can see if you open up the 'questions' folder).
- And there's already some files for you to write your code in!
- Open up either the `Solution.java` or `solution.py` <- this is where your code goes.
- There's also a `description.md` that explains each problem...because you have to know what to do, obviously.
- When you think your solution is right, you're going to run one of the commands below vvv
- If you pass, you'll get a super special secretive code which is what you'll put in the google form and is how you'll be scored

## Running your code

**CODESPACES**/Linux/macOS:
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

## Example Output

```
Question 1 Results:
Test 1: PASS
Test 2: PASS
Test 3: FAIL (expected 42, got 41)
Score: 8/10
Code: apbdjhnasopiufh
```

Fix your code and run again until all tests pass!
---

### [Submit Your Codes Here]()
### Good Luck!
