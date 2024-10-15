package aplications;

import java.util.HashMap;

import entities.funcionario;
import java.util.Scanner;

public class App {
    public static HashMap<Integer, funcionario> funcionarios = new HashMap<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Choose an option:");
            System.out.println("1. Register employee");
            System.out.println("2. List employees");
            System.out.println("3. Remove employees");
            System.out.println("4. Exit");
            int option = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (option) {
                case 1:
                    funcionario func = cadr.cadastrarFuncionarios();
                    if (func != null) {
                        funcionarios.put(func.getCpf(), func);
                        System.out.println("Employee registered with CPF: " + func.getCpf());
                    } else {
                        System.out.println("Failed to register employee.");
                    }
                    break;
                case 2:
                    for (funcionario f : funcionarios.values()) {
                        System.out.println("\n");
                        System.out.println(f);
                    }
                    break;
                case 3:
                    System.out.println("CPF:");
                    int cpff = scanner.nextInt();
                    scanner.nextLine(); // Consume newline
                    if (funcionarios.containsKey(cpff)) {
                        funcionarios.remove(cpff);
                        System.out.println("Employee removed with CPF: " + cpff);
                    } else {
                        System.out.println("Employee not found with CPF: " + cpff);
                    }
                    break;
                case 4:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid option. Please try again.");
                    break;
            }
        }

    }

}
