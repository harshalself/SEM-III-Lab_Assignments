// NAME : HARSHAL PATIL
// ROLL NO : 44 

import java.util.Scanner;

class Person {
    String name;
    long phoneNo;

    void showDetails() {
        System.out.println("Name of Person: " + name);
        System.out.println("Phone number of Person: " + phoneNo);
    }
}

class AcademicPerformance extends Person {
    float percentage;
    String degree;
    Scanner sc = new Scanner(System.in);

    AcademicPerformance() {
        System.out.println("Enter percentage of Person:");
        percentage = sc.nextFloat();
		
			
		if(percentage>=0 && percentage<=100){
		}
		else{
                System.out.println("Invalid Percentage! Enter Again");
                percentage = sc.nextFloat();
		}
			
        sc.nextLine(); 
        System.out.println("Enter degree of Person:");
        degree = sc.nextLine();
    }

    void showAcademics() {
        System.out.println("Degree of Person: " + degree);
        System.out.println("Percentage of Person: " + percentage);
    }

    public void finalize() {
        System.out.println("Object Destroyed!");
    }
}

class SportsPerformance extends Person {
    float score;
    String sportName;

    void showSports() {
        System.out.println("Score of Person: " + score);
        System.out.println("Sports Name: " + sportName);
    }
}

public class First{

    public static void main(String[] args) {

        AcademicPerformance a1 = new AcademicPerformance();
        SportsPerformance s1 = new SportsPerformance();

        Scanner sc1 = new Scanner(System.in);

        System.out.println("Enter Phone number of Person:");
        a1.phoneNo = sc1.nextLong();
        sc1.nextLine(); 
        System.out.println("Enter Name of Person:");
        a1.name = sc1.nextLine();
        
        System.out.println("Enter Score:");
        s1.score = sc1.nextFloat();
        sc1.nextLine(); 
        System.out.println("Enter Name of Sports:");
        s1.sportName = sc1.nextLine();

        a1.showDetails();
        a1.showAcademics();
        s1.showSports();
    }
}