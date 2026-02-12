import java.io.*;
import java.util.*;

public class example {
    public static void main(String[] args) throws IOException {

        // Option 1: Read all lines into a list
        List<String> lines = new ArrayList<>();
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        String line;
        while ((line = br.readLine()) != null) {
            lines.add(line.trim());
        }
        br.close();

        // lines.get(0) is the first line, lines.get(1) is the second, etc.

        // Option 2: Process line by line while reading
        br = new BufferedReader(new FileReader("input.txt"));
        while ((line = br.readLine()) != null) {
            line = line.trim();
            System.out.println(line);
        }
        br.close();

        // Common patterns:
        // Read a single integer from a line
        int n = Integer.parseInt(lines.get(0));

        // Read two integers from one line (e.g., "10 20")
        String[] parts = lines.get(0).split(" ");
        int a = Integer.parseInt(parts[0]);
        int b = Integer.parseInt(parts[1]);

        // Read a line with a name and a number (e.g., "Alice 42")
        String name = parts[0];
        int score = Integer.parseInt(parts[1]);
    }
}
