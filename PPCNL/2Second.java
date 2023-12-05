// NAME : HARSHAL PATIL
// ROLL NO : 44 

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Publication {
    protected String title;
    protected double price;

    public Publication(String title, double price) {
        this.title = title;
        this.price = price;
    }

    public void display() {
        System.out.println("Title: " + title);
        System.out.println("Price: $" + price);
    }
}

class Book extends Publication {
    private int pageCount;

    public Book(String title, double price, int pageCount) {
        super(title, price);
        this.pageCount = pageCount;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Page Count: " + pageCount);
    }
}

class AudioCassette extends Publication {
    private int playTimeMinutes;

    public AudioCassette(String title, double price, int playTimeMinutes) {
        super(title, price);
        this.playTimeMinutes = playTimeMinutes;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Play Time (minutes): " + playTimeMinutes);
    }
}

public class Second {
    private static List<Book> books = new ArrayList<>();
    private static List<AudioCassette> cassettes = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Add Book");
            System.out.println("2. Add Audio Cassette");
            System.out.println("3. Display Books");
            System.out.println("4. Display Cassettes");
            System.out.println("5. Exit");

            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            try {
                switch (choice) {
                    case 1:
                        addBook();
                        break;
                    case 2:
                        addAudioCassette();
                        break;
                    case 3:
                        displayBooks();
                        break;
                    case 4:
                        displayCassettes();
                        break;
                    case 5:
                        System.out.println("Exiting the program.");
                        scanner.close();
                        System.exit(0);
                    default:
                        System.out.println("Invalid choice. Please enter a valid option.");
                }
            } catch (Exception e) {
                System.out.println("Exception caught: " + e.getMessage());
                clearData();
            }
        }
    }

    private static void addBook() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Book Title: ");
        String title = scanner.nextLine();
        System.out.print("Enter Book Price: $");
        double price = scanner.nextDouble();
        System.out.print("Enter Page Count: ");
        int pageCount = scanner.nextInt();

        Book book = new Book(title, price, pageCount);
        books.add(book);
        System.out.println("Book added successfully!");
    }

    private static void addAudioCassette() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Cassette Title: ");
        String title = scanner.nextLine();
        System.out.print("Enter Cassette Price: $");
        double price = scanner.nextDouble();
        System.out.print("Enter Play Time (minutes): ");
        int playTimeMinutes = scanner.nextInt();

        AudioCassette cassette = new AudioCassette(title, price, playTimeMinutes);
        cassettes.add(cassette);
        System.out.println("Audio Cassette added successfully!");
    }

    private static void displayBooks() {
        if (books.isEmpty()) {
            System.out.println("No books available.");
        } else {
            System.out.println("Available Books:");
            for (Book book : books) {
                book.display();
                System.out.println("------------");
            }
        }
    }

    private static void displayCassettes() {
        if (cassettes.isEmpty()) {
            System.out.println("No cassettes available.");
        } else {
            System.out.println("Available Cassettes:");
            for (AudioCassette cassette : cassettes) {
                cassette.display();
                System.out.println("------------");
            }
        }
    }

    private static void clearData() {
       
    }
}