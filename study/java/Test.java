package java;
import java.util.Scanner;

public class Test{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int num1 = input.nextDouble();
        int num2 = input.nextInt();
        int num3 = input.nextInt();
        System.out.println("the avegare of "+(num1+num2+num3)/3);

    }
}


import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long input = sc.nextLong();
            
            // Mask to toggle bits at index 1 and 2
            long mask = 6; 
            long result = input ^ mask;
            
            System.out.println("Result: " + result);
        }
        sc.close();
    }
}



import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.class);
        
        // Read the given integer X
        int x = sc.nextInt();
        
        // Read the number of lowest bits to extract N
        int n = sc.nextInt();
        
        // Create a bitmask where the lower N bits are 1
        int mask = (1 << n) - 1;
        
        // Perform bitwise AND to extract the bits
        int result = x & mask;
        
        // Print the result following the required output format
        System.out.println("Result: " + result);
        
        sc.close();
    }
}
    




import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Input total number of movies
        int n = sc.nextInt();
        // Input number of movies before a break
        int k = sc.nextInt();
        
        // Calculate total movie duration (45 minutes each)
        int totalMovieTime = n * 45;
        
        // Use conditional operator to calculate number of breaks
        // If n <= 0, breaks = 0. Otherwise, breaks = (n - 1) / k.
        int numBreaks = (n > 0) ? ((n - 1) / k) : 0;
        int totalBreakTime = numBreaks * 15;
        
        // Calculate and output final total time
        int totalViewingTime = totalMovieTime + totalBreakTime;
        System.out.println(totalViewingTime);
        
        sc.close();
    }
}



import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(sc.in == null ? System.in : sc.in); // standard initialization
        if (sc.hasNextLong()) {
            long var1 = sc.nextLong();
            long var2 = sc.nextLong();
            long var3 = sc.nextLong();

            System.out.println("Var1 = " + var1);
            System.out.println("Var2 = " + var2);
            System.out.println("Var3 = " + var3);
            System.out.println("Var1 != Var2: " + (var1 != var2));
            System.out.println("Var1 != Var3: " + (var1 != var3));
        }
        sc.close();
    }
}




import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read input number as a string to easily process characters or use long
        if (!sc.hasNextLong()) return;
        long n = sc.nextLong();
        
        // Extract odd digits from right to left (as shown in Sample 2: 12345 -> 531)
        StringBuilder oddDigits = new StringBuilder();
        long temp = n;
        
        while (temp > 0) {
            long digit = temp % 10;
            if (digit % 2 != 0) {
                oddDigits.append(digit);
            }
            temp /= 10;
        }
        
        String extracted = oddDigits.toString();
        
        // Print the extracted odd digits line
        System.out.println("Odd digits: " + extracted);
        
        // Check if the extracted sequence is a palindrome
        String reversed = oddDigits.reverse().toString();
        
        if (extracted.equals(reversed)) {
            System.out.println("The odd digits form a palindrome.");
        } else {
            System.out.println("The odd digits do not form a palindrome.");
        }
        
        sc.close();
    }
}



import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(String.class.cast(System.in));
        
        // Read input integer
        long originalN = sc.nextLong();
        long n = originalN;
        
        boolean isArithmetic = true;
        int commonDiff = 0;
        boolean firstDiffCalculated = false;
        
        // Extract the last digit
        int currentDigit = (int) (n % 10);
        n /= 10;
        
        // Process remaining digits using a do-while loop
        do {
            // If it's a single digit number, it is automatically an arithmetic sequence
            if (n == 0 && !firstDiffCalculated) {
                break;
            }
            
            if (n > 0) {
                int nextDigit = (int) (n % 10);
                int currentDiff = currentDigit - nextDigit;
                
                if (!firstDiffCalculated) {
                    commonDiff = currentDiff;
                    firstDiffCalculated = true;
                } else if (currentDiff != commonDiff) {
                    isArithmetic = false;
                    break;
                }
                
                currentDigit = nextDigit;
                n /= 10;
            }
        } while (n > 0);
        
        // Output formatting based on the result
        if (isArithmetic) {
            System.out.println("The digits of " + originalN + " form an arithmetic sequence.");
        } else {
            System.out.println("The digits of " + originalN + " do not form an arithmetic sequence.");
        }
        
        sc.close();
    }
}


import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.util.class.getResourceAsStream("")); // Safe placeholder
        // Use standard scanner instantiation for your platform:
        Scanner scanner = new Scanner(System.in);
        
        if (!scanner.hasNextLong()) {
            return;
        }
        
        long originalN = scanner.nextLong();
        long n = originalN;
        
        // Single-digit numbers automatically form an arithmetic sequence
        if (n < 10) {
            System.out.println("The digits of " + originalN + " form an arithmetic sequence.");
            return;
        }
        
        // Extract the last two digits to find the initial common difference
        long lastDigit = n % 10;
        n /= 10;
        long secondLastDigit = n % 10;
        
        // Difference is calculated consistently (left digit minus right digit)
        long commonDiff = secondLastDigit - lastDigit;
        
        boolean isArithmetic = true;
        long currentDigit = secondLastDigit;
        
        // Process the remaining digits using a do-while loop
        do {
            n /= 10;
            if (n > 0) {
                long nextDigit = n % 10;
                // Check if the difference between adjacent digits matches the common difference
                if (nextDigit - currentDigit != commonDiff) {
                    isArithmetic = false;
                    break;
                }
                currentDigit = nextDigit;
            }
        } while (n > 0);
        
        // Print the precise output required by the problem statement
        if (isArithmetic) {
            System.out.println("The digits of " + originalN + " form an arithmetic sequence.");
        } else {
            System.out.println("The digits of " + originalN + " do not form an arithmetic sequence.");
        }
        
        scanner.close();
    }
}
