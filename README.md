# CGI Coding Competition


### GI: Operation Trusted Outcomes

You are a newly recruited CGI Partner on your first week inside the Global Digital Response Team.

CGI operates across 400+ locations worldwide, delivering insights-driven IT solutions. But today, something unusual is happening.

A coordinated cyber event — codenamed “Shadow ROI” — is attempting to disrupt CGI client systems across multiple industries. Financial services, healthcare, logistics, energy — all sectors are at risk.

The leadership team activates an internal simulation:

“To protect our clients, you must demonstrate mastery of data, logic, and resilience. Each system you stabilize unlocks the next.”

Each problem represents a real-world CGI challenge:

Data validation

Log analysis

Decision modeling

Infrastructure protection

Strategic optimization

By solving each task, students “restore” part of CGI’s global digital infrastructure.


---

## Running with Docker

> if you don't have docker install it [here](https://docs.docker.com/get-started/get-docker/)

**Build the image:**
```bash
docker build -t cgi-grader .
```

**Run the grader:**
```bash
docker run --rm cgi-grader --question 1 --lang python
```

**Or use the helper script:**

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
