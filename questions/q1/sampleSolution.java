package q1;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class sampleSolution {
    public static void main(String[] args) {
        // open input.txt for reading
        Path inputPath = Paths.get("input.txt");
        double total = 0;

        try (BufferedReader br = Files.newBufferedReader(inputPath)) {
            String line;
            while ((line = br.readLine()) != null) {
                int value = Integer.parseInt(line.trim());
                total += value;


            }
        } catch (IOException e) {
            System.err.println("Failed to read input: " + e.getMessage());
        }

        System.out.println((int) total);
    }
}
