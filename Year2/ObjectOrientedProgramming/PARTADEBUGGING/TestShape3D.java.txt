// TestShape3D.java
// TEST 2 - Question 1
// SECJ2154 - 2022/2023-2
// Name : Damiya Aina binti Basir Abd Shammad
// Matric No : A23CS0220

import java.util.ArrayList;
import java.util.Scanner;

public class TestShape3D {
    public static void main(String[] args) {
        boolean exit = false;
        String choice;
        Scanner scan = new Scanner(System.in);

        ArrayList<Object> objList = new ArrayList<>();
        Shape3D s3d = new Shape3D();

        System.out.println("Test Shape 3D class");

        while (!exit) {
            System.out.print("\nEnter your choice [cylinder | sphere | exit]: ");
            choice = scan.nextLine();

            if (choice.equalsIgnoreCase("cylinder")) {
                objList.add(s3d.createCylinder(scan));
            } else if (choice.equalsIgnoreCase("sphere")) {
                objList.add(s3d.createSphere(scan));
            } else if (choice.equalsIgnoreCase("exit")) {
                exit = true;
            }
        }

        for (int i = 0; i < objList.size(); i++) {
            if (objList.get(i) instanceof Cylinder) {
                Cylinder obj = (Cylinder) objList.get(i);
                System.out.printf("Object #%d Type: Cylinder, Volume: %.3f\n", (i + 1), obj.getVolume());
            } else if (objList.get(i) instanceof Sphere) {
                Sphere obj = (Sphere) objList.get(i);
                System.out.printf("Object #%d Type: Sphere, Volume: %.3f\n", (i + 1), obj.getVolume());
            }
        }

        System.out.printf("TOTAL VOLUME = %.2f\n", s3d.TOTAL_VOLUME);
    }
}


class Shape3D {
    public static final double PI = 3.14;
    public double TOTAL_VOLUME = 0.0;

    public Cylinder createCylinder(Scanner scn) {
        System.out.println("Create Cylinder...");
        System.out.print("Radius: ");
        double r = scn.nextDouble();

        System.out.print("Height: ");
        double h = scn.nextDouble();
        scn.nextLine(); // Clear buffer

        Cylinder cyl = new Cylinder(r, h);
        TOTAL_VOLUME += cyl.getVolume();
        return cyl;
    }

    public Sphere createSphere(Scanner scn) {
        System.out.println("Create Sphere...");
        System.out.print("Radius: ");
        double r = scn.nextDouble();
        scn.nextLine(); // Clear buffer

        Sphere sph = new Sphere(r);
        TOTAL_VOLUME += sph.getVolume();
        return sph;
    }
}


class Cylinder {
    private double radius, height;

    // Constructor
    public Cylinder() {
        this.radius = 0.0;
        this.height = 0.0;
    }

    // Overloaded constructor
    public Cylinder(double r, double h) {
        this.radius = r;
        this.height = h;
    }

    public double getVolume() {
        return Shape3D.PI * Math.pow(radius, 2) * height;
    }
}


class Sphere {
    private double radius;

    // Constructor
    public Sphere(double r) {
        this.radius = r;
    }

    public double getVolume() {
        return (4.0 / 3.0) * Shape3D.PI * Math.pow(radius, 3);
    }
}
