1. Factorial Program with Exception Handling
File: Factorial.java
import java.util.Scanner;

public class Factorial {

    // Array to store factorial values
    static long[] fact = new long[21];

    // Method to calculate factorial
    static long factorial(int x) {

        // Exception for negative number
        if (x < 0) {
            throw new IllegalArgumentException(
                "value of x must be positive"
            );
        }

        // Exception for overflow
        if (x >= fact.length) {
            throw new IllegalArgumentException(
                "result will overflow."
            );
        }

        // Reuse factorial if already calculated
        if (x == 0 || x == 1) {
            return 1;
        }

        if (fact[x] == 0) {
            fact[x] = x * factorial(x - 1);
        }

        return fact[x];
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {
            System.out.print("Enter a number: ");
            int n = sc.nextInt();

            long result = factorial(n);

            System.out.println("Factorial of " + n + " = " + result);

        } catch (IllegalArgumentException e) {

            System.out.println("Exception: " + e.getMessage());

        } finally {
            sc.close();
        }
    }
}

2. Program to Throw Exception for Invalid Email ID
File: EmailValidation.java
import java.util.Scanner;

public class EmailValidation {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {

            System.out.print("Enter Email ID: ");
            String email = sc.nextLine();

            // Basic email validation
            if (!(email.contains("@") &&
                  email.contains(".") &&
                  email.indexOf("@") < email.lastIndexOf("."))) {

                throw new Exception("Invalid Email ID");
            }

            System.out.println("Valid Email ID");

        } catch (Exception e) {

            System.out.println("Exception: " + e.getMessage());

        } finally {
            sc.close();
        }
    }
}



day---------5
  1. Abstract Class ThreeDObject
File: ThreeDObject.java
abstract class ThreeDObject {

    // Protected variables
    protected double dimension1;
    protected double dimension2;
    protected double dimension3;

    // Abstract methods
    abstract double wholeSurfaceArea();

    abstract double volume();
}
Class Box
File: Box.java
class Box extends ThreeDObject {

    Box(double l, double b, double h) {
        dimension1 = l;
        dimension2 = b;
        dimension3 = h;
    }

    double wholeSurfaceArea() {
        return 2 * ((dimension1 * dimension2)
                + (dimension2 * dimension3)
                + (dimension1 * dimension3));
    }

    double volume() {
        return dimension1 * dimension2 * dimension3;
    }
}
Class Cube
File: Cube.java
class Cube extends ThreeDObject {

    Cube(double side) {
        dimension1 = side;
    }

    double wholeSurfaceArea() {
        return 6 * dimension1 * dimension1;
    }

    double volume() {
        return dimension1 * dimension1 * dimension1;
    }
}
Class Cylinder
File: Cylinder.java
class Cylinder extends ThreeDObject {

    Cylinder(double r, double h) {
        dimension1 = r;
        dimension2 = h;
    }

    double wholeSurfaceArea() {
        return 2 * Math.PI * dimension1 * (dimension1 + dimension2);
    }

    double volume() {
        return Math.PI * dimension1 * dimension1 * dimension2;
    }
}
Class Cone
File: Cone.java
class Cone extends ThreeDObject {

    Cone(double r, double h) {
        dimension1 = r;
        dimension2 = h;
    }

    double wholeSurfaceArea() {

        double slantHeight =
                Math.sqrt((dimension1 * dimension1)
                + (dimension2 * dimension2));

        return Math.PI * dimension1
                * (dimension1 + slantHeight);
    }

    double volume() {
        return (1.0 / 3) * Math.PI
                * dimension1 * dimension1 * dimension2;
    }
}
Menu Driven Main Program
File: Main.java
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int choice;

        do {

            System.out.println("\n----- 3D OBJECT MENU -----");
            System.out.println("1. Box");
            System.out.println("2. Cube");
            System.out.println("3. Cylinder");
            System.out.println("4. Cone");
            System.out.println("5. Exit");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:

                    System.out.print("Enter length breadth height: ");
                    double l = sc.nextDouble();
                    double b = sc.nextDouble();
                    double h = sc.nextDouble();

                    Box box = new Box(l, b, h);

                    System.out.println("Volume = " + box.volume());
                    System.out.println("Surface Area = "
                                        + box.wholeSurfaceArea());
                    break;

                case 2:

                    System.out.print("Enter side: ");
                    double side = sc.nextDouble();

                    Cube cube = new Cube(side);

                    System.out.println("Volume = " + cube.volume());
                    System.out.println("Surface Area = "
                                        + cube.wholeSurfaceArea());
                    break;

                case 3:

                    System.out.print("Enter radius and height: ");
                    double r1 = sc.nextDouble();
                    double h1 = sc.nextDouble();

                    Cylinder cylinder =
                            new Cylinder(r1, h1);

                    System.out.println("Volume = "
                                        + cylinder.volume());

                    System.out.println("Surface Area = "
                                        + cylinder.wholeSurfaceArea());
                    break;

                case 4:

                    System.out.print("Enter radius and height: ");
                    double r2 = sc.nextDouble();
                    double h2 = sc.nextDouble();

                    Cone cone = new Cone(r2, h2);

                    System.out.println("Volume = "
                                        + cone.volume());

                    System.out.println("Surface Area = "
                                        + cone.wholeSurfaceArea());
                    break;

                case 5:
                    System.out.println("Program Ended");
                    break;

                default:
                    System.out.println("Invalid Choice");
            }

        } while (choice != 5);

        sc.close();
    }
}
Sample Output
----- 3D OBJECT MENU -----
1. Box
2. Cube
3. Cylinder
4. Cone
5. Exit
Enter your choice: 2

Enter side: 5

Volume = 125.0
Surface Area = 150.0
2. Interface + Package Program
Package Structure
Pack1
│
├── Department.java
├── Hostel.java
└── Student.java

Driver.java
File: Department.java
package Pack1;

public interface Department {

    String depName = "CSE";
    String depHead = "Dr. Sharma";

    void getDepartmentData();

    void printDepartmentData();
}
File: Hostel.java
package Pack1;

import java.util.Scanner;

public class Hostel {

    protected String hostelName;
    protected String hostelLocation;
    protected int noOfRooms;

    public void getHostelData() {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Hostel Name: ");
        hostelName = sc.nextLine();

        System.out.print("Enter Hostel Location: ");
        hostelLocation = sc.nextLine();

        System.out.print("Enter Number of Rooms: ");
        noOfRooms = sc.nextInt();
    }

    public void printHostelData() {

        System.out.println("Hostel Name: " + hostelName);
        System.out.println("Hostel Location: "
                            + hostelLocation);

        System.out.println("Number of Rooms: "
                            + noOfRooms);
    }
}
File: Student.java
package Pack1;

import java.util.Scanner;

public class Student extends Hostel
                     implements Department {

    private String studentName;
    private int regNo;
    private String electiveSubject;
    private double avgMarks;

    // Student Data
    public void getData() {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Student Name: ");
        studentName = sc.nextLine();

        System.out.print("Enter Registration Number: ");
        regNo = sc.nextInt();

        sc.nextLine();

        System.out.print("Enter Elective Subject: ");
        electiveSubject = sc.nextLine();

        System.out.print("Enter Average Marks: ");
        avgMarks = sc.nextDouble();

        getHostelData();
    }

    public void printData() {

        System.out.println("\n----- STUDENT DETAILS -----");

        System.out.println("Student Name: "
                            + studentName);

        System.out.println("Registration No: "
                            + regNo);

        System.out.println("Elective Subject: "
                            + electiveSubject);

        System.out.println("Average Marks: "
                            + avgMarks);

        printHostelData();

        printDepartmentData();
    }

    // Interface Methods
    public void getDepartmentData() {

        // Already fixed values in interface
    }

    public void printDepartmentData() {

        System.out.println("Department Name: "
                            + depName);

        System.out.println("Department Head: "
                            + depHead);
    }
}
Driver Class Outside Package
File: Driver.java
import Pack1.Student;

public class Driver {

    public static void main(String[] args) {

        Student s = new Student();

        s.getData();

        s.printData();
    }
}
Compilation
javac Pack1/*.java
javac Driver.java
Run
java Driver








  day4=---1. Method Overloading Program (abs Methods)
File: MyClass.java
class MyClass {

    // Absolute value for integer
    int abs(int x) {

        if (x < 0)
            return -x;
        else
            return x;
    }

    // Absolute value for float
    float abs(float x) {

        if (x < 0)
            return -x;
        else
            return x;
    }

    // Absolute value for double
    double abs(double x) {

        if (x < 0)
            return -x;
        else
            return x;
    }

    public static void main(String[] args) {

        MyClass obj = new MyClass();

        System.out.println("Absolute value of Integer: "
                            + obj.abs(-25));

        System.out.println("Absolute value of Float: "
                            + obj.abs(-12.5f));

        System.out.println("Absolute value of Double: "
                            + obj.abs(-99.456));
    }
}
Sample Output
Absolute value of Integer: 25
Absolute value of Float: 12.5
Absolute value of Double: 99.456
2. Telephone Billing System
Call Rate Table
Call Type	Day Time (6 AM – 10 PM)	Night Time (10:01 PM – 5:59 AM)
Local Call	Rs 0.5 / 3 min	Rs 0.25 / 3 min
STD to 011	Rs 1.5 / 2 min	Rs 0.5 / 2 min
STD to 022	Rs 1.5 / 2 min	Rs 0.5 / 2 min
STD to 044	Rs 0.75 / 2 min	Rs 0.4 / 2 min
Local Call Class
File: LocalCall.java
class LocalCall {

    int duration;
    boolean isDay;

    LocalCall(int duration, boolean isDay) {
        this.duration = duration;
        this.isDay = isDay;
    }

    double calculateBill() {

        int units = (int)Math.ceil(duration / 3.0);

        if (isDay)
            return units * 0.5;
        else
            return units * 0.25;
    }
}
Long Distance Call Class
File: LongCall.java
class LongCall {

    int duration;
    String stdCode;
    boolean isDay;

    LongCall(int duration,
             String stdCode,
             boolean isDay) {

        this.duration = duration;
        this.stdCode = stdCode;
        this.isDay = isDay;
    }

    double calculateBill() {

        int units = (int)Math.ceil(duration / 2.0);

        double rate = 0;

        if (stdCode.equals("011")) {

            if (isDay)
                rate = 1.5;
            else
                rate = 0.5;
        }

        else if (stdCode.equals("022")) {

            if (isDay)
                rate = 1.5;
            else
                rate = 0.5;
        }

        else if (stdCode.equals("044")) {

            if (isDay)
                rate = 0.75;
            else
                rate = 0.4;
        }

        return units * rate;
    }
}
Driver Program
File: TelephoneBill.java
public class TelephoneBill {

    public static void main(String[] args) {

        // Local Call
        LocalCall lc =
                new LocalCall(10, true);

        System.out.println("Local Call Bill = Rs "
                            + lc.calculateBill());

        // STD Call
        LongCall std =
                new LongCall(8, "044", false);

        System.out.println("STD Call Bill = Rs "
                            + std.calculateBill());
    }
}
Sample Output
Local Call Bill = Rs 2.0
STD Call Bill = Rs 1.6
3. Educational Institution Database Using Inheritance
Base Class: Staff
File: Staff.java
class Staff {

    protected int code;
    protected String name;

    Staff(int code, String name) {

        this.code = code;
        this.name = name;
    }

    void display() {

        System.out.println("Code : " + code);
        System.out.println("Name : " + name);
    }
}
Teacher Class
File: Teacher.java
class Teacher extends Staff {

    private String subject;
    private String publication;

    Teacher(int code, String name,
            String subject,
            String publication) {

        super(code, name);

        this.subject = subject;
        this.publication = publication;
    }

    void display() {

        super.display();

        System.out.println("Subject : " + subject);
        System.out.println("Publication : "
                            + publication);
    }
}
Officer Class
File: Officer.java
class Officer extends Staff {

    private String grade;

    Officer(int code,
            String name,
            String grade) {

        super(code, name);

        this.grade = grade;
    }

    void display() {

        super.display();

        System.out.println("Grade : " + grade);
    }
}
Typist Class
File: Typist.java
class Typist extends Staff {

    protected int speed;

    Typist(int code,
           String name,
           int speed) {

        super(code, name);

        this.speed = speed;
    }

    void display() {

        super.display();

        System.out.println("Typing Speed : "
                            + speed);
    }
}
Regular Typist Class
File: RegularTypist.java
class RegularTypist extends Typist {

    private double remuneration;

    RegularTypist(int code,
                   String name,
                   int speed,
                   double remuneration) {

        super(code, name, speed);

        this.remuneration = remuneration;
    }

    void display() {

        super.display();

        System.out.println("Remuneration : "
                            + remuneration);
    }
}
Casual Typist Class
File: CasualTypist.java
class CasualTypist extends Typist {

    private double dailyWages;

    CasualTypist(int code,
                  String name,
                  int speed,
                  double dailyWages) {

        super(code, name, speed);

        this.dailyWages = dailyWages;
    }

    void display() {

        super.display();

        System.out.println("Daily Wages : "
                            + dailyWages);
    }
}
Driver Program
File: Institution.java
public class Institution {

    public static void main(String[] args) {

        Teacher t =
            new Teacher(101,
                        "Rahul",
                        "Java",
                        "ABC Publication");

        Officer o =
            new Officer(102,
                        "Amit",
                        "A");

        RegularTypist rt =
            new RegularTypist(103,
                              "Riya",
                              45,
                              25000);

        CasualTypist ct =
            new CasualTypist(104,
                             "Karan",
                             40,
                             800);

        System.out.println("\n--- Teacher Details ---");
        t.display();

        System.out.println("\n--- Officer Details ---");
        o.display();

        System.out.println("\n--- Regular Typist Details ---");
        rt.display();

        System.out.println("\n--- Casual Typist Details ---");
        ct.display();
    }
}
