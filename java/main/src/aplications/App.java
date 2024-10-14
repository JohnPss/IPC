package aplications;

import java.util.HashMap;

import entities.funcionarios;
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        HashMap<Integer, funcionarios> funcionarios = new HashMap<>();

        while (true) {

            funcionarios func = cadr.cadastrarFuncionarios();
            if (func == null) {
                break;
            }

            funcionarios.put(func.getCpf(), func);
        }

        for (funcionarios func : funcionarios.values()) {
            System.out.println(func);
        }

        scanner.close();

    }
}

// System.out.println("1 - Cadastrar funcionário");System.out.println("2 -
// Listar funcionários");System.out.println("3 - Sair");System.out.print("Opção:
// ");

// int opcao = scanner.nextInt();scanner.nextLine();

// switch(opcao)
// {
// case 1:
// cadr cadastro = new cadr();
// funcionarios funcionario = cadastro.cadastrarFuncionarios();
// funcionarios.put(funcionario.getCpf(), funcionario);
// break;
// case 2:
// for (funcionarios func : funcionarios.values()) {
// System.out.println(func);
// }
// break;
// case 3:
// System.out.println("Saindo...");
// break;
// default:
// System.out.println("Opção inválida!");
// break;
// }

// if(opcao==3)
// {
// break;
// }
