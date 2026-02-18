package q1;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Solution {
    public static void main(String[] args) {
        // open input.txt for reading
        Path inputPath = Paths.get("input.txt");

        try (BufferedReader br = Files.newBufferedReader(inputPath)) {
            String line;
            while ((line = br.readLine()) != null) {
                int value = Integer.parseInt(line.trim()); // int value of each lien

            }
        } catch (IOException e) {
            System.err.println("Failed to read input: " + e.getMessage());
        }
    }
}
