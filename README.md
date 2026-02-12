# CGI Coding Competition

## Running with Docker

**Build the image:**
```bash
docker build -t cgi-grader .
```

**Run the grader:**
```bash
docker run --rm cgi-grader --question 1 --lang python
```

**Or use the helper script:**
```bash
./run-grader.sh 1 python
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
