package aplications;

import java.util.Scanner;
import entities.funcionario;

public class cadr {
    private static Scanner scanner = new Scanner(System.in);

    public static funcionario cadastrarFuncionarios() {
        String nome;
        funcionario funcionario = null;

        while (true) {

            System.out.print("Nome: ");
            nome = scanner.nextLine();

            if (nome.equals("0")) {
                return funcionario;
            }

            System.out.print("CPF: ");
            Integer cpf = scanner.nextInt();
            scanner.nextLine();

            System.out.print("Email: ");
            String email = scanner.nextLine();

            System.out.print("Telefone: ");
            String telefone = scanner.nextLine();

            System.out.print("Salário: ");
            Double salario = scanner.nextDouble();
            scanner.nextLine(); // Consumir a quebra de linha após o salário

            System.out.print("Cargo: ");
            String cargo = scanner.nextLine();

            // Cria o objeto 'funcionarios' com os dados fornecidos
            funcionario = new funcionario(nome, cpf, email, telefone, salario, cargo);
            System.out.println("Funcionário cadastrado com sucesso!\n");

            // Saímos do loop após cadastrar um funcionário
            break;
        }

        // Retorna o objeto 'funcionario' criado
        return funcionario;
    }

}
