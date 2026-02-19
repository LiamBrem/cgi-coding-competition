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

## Getting the questions ready to go:

> if you don't have docker install it [here](https://docs.docker.com/get-started/get-docker/)

**Clone the repo:**
```bash
git clone https://github.com/LiamBrem/cgi-coding-competition (<- CHANGE BY EVENT)
```

**CD into the folder:**
```bash
cd cgi-coding-competition
```
Now you're ready to **START CODING!**

## How does it work 🤨

- Each question has it's own folder (as you can see if you open up the 'questions' folder).
- And there's already some files for you to write your code in!
- Open up either the `Solution.java` or `solution.py` <- this is where your code goes.
- There's also a `description.md` that explains each problem...because you have to know what to do, obviously.
- When you think your solution is right, you're going to run one of the commands below vvv
- If you pass, you'll get a super special secretive code which is what you'll put in the google form and is how you'll be scored


**Build the image:**
```bash
docker build -t cgi-grader .
```

**Run the grader:**
```bash
docker run --rm cgi-grader --question 1 --lang python
```

**Or use the helper script:**
> This builds and runs the grader at the same time!

Linux/macOS:
```bash
./run-grader.sh 1 python
```

Windows (Command Prompt):
```cmd
run-grader.bat 1 python
```

Windows (PowerShell):
```powershell
.\run-grader.ps1 1 python
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

---

### [HERE]() is the form to submit all of your codes
### Good Luck!
