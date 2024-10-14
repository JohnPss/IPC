package aplications;

import java.util.Scanner;
import entities.funcionarios;

public class cadr {
    private static Scanner scanner = new Scanner(System.in);

    public static funcionarios cadastrarFuncionarios() {
        String nome;
        funcionarios funcionario = null;

        while (true) {

            System.out.print("Nome: ");
            nome = scanner.nextLine();

            // Se o nome for "0", encerra o loop e retorna o funcionário (null nesse caso)
            if (nome.equals("0")) {
                return funcionario;
            }

            System.out.print("CPF: ");
            Integer cpf = scanner.nextInt();
            scanner.nextLine(); // Consumir a quebra de linha após o número

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
            funcionario = new funcionarios(nome, cpf, email, telefone, salario, cargo);
            System.out.println("Funcionário cadastrado com sucesso!\n");

            // Saímos do loop após cadastrar um funcionário
            break;
        }

        // Retorna o objeto 'funcionario' criado
        return funcionario;
    }
}
