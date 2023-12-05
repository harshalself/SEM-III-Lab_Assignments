// NAME : HARSHAL PATIL
// ROLL NO : 44 

import java.util.Scanner;

class UserValidationException extends Exception {
    public UserValidationException(String message) {
        super(message);
    }
}

class User {
    int age;
    double income;
    String city;
    boolean hasFourWheeler;

    public User(int age, double income, String city, boolean hasFourWheeler) {
        this.age = age;
        this.income = income;
        this.city = city;
        this.hasFourWheeler = hasFourWheeler;
    }

    public void validateUser() throws UserValidationException {
        StringBuilder errorMessage = new StringBuilder();

        if (age < 18 || age > 55) {
            errorMessage.append("Invalid age. Age should be between 18 and 55.\n");
        }

        if (income < 50000 || income > 100000) {
            errorMessage.append("Invalid income. Income should be between Rs. 50,000 and Rs. 1,00,000 per month.\n");
        }

        String[] validCities = {"Pune", "Mumbai", "Bangalore", "Chennai"};
        boolean validCity = false;
        for (String valid : validCities) {
            if (city.equalsIgnoreCase(valid)) {
                validCity = true;
                break;
            }
        }

        if (!validCity) {
            errorMessage.append("Invalid city. User should stay in Pune, Mumbai, Bangalore, or Chennai.\n");
        }

        if (!hasFourWheeler) {
            errorMessage.append("User must have a 4-wheeler.\n");
        }

        if (errorMessage.length() > 0) {
            throw new UserValidationException(errorMessage.toString());
        }
    }
}

public class Third {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter age: ");
        int age = scanner.nextInt();

        System.out.print("Enter income: ");
        double income = scanner.nextDouble();

        System.out.print("Enter city: ");
        String city = scanner.next();

        System.out.print("Does the user have a 4-wheeler? (true/false): ");
        boolean hasFourWheeler = scanner.nextBoolean();

        User user = new User(age, income, city, hasFourWheeler);

        try {
            user.validateUser();
            System.out.println("User is valid.");
        } catch (UserValidationException e) {
            System.out.println("User Validation Exception:\n" + e.getMessage());
        }
    }
}
