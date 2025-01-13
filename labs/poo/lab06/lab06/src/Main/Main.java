package Main;

import java.util.*;

import Veiculo.*;
import Motorista.*;

public class Main {
    private static Map<String, Motorista> motoristas = new HashMap<>();
    private static Map<String, Veiculo> veiculos = new HashMap<>();
    private static List<Viagem> viagens = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        while (true) {
            System.out.println("\n=== Sistema de Gerenciamento de Veículos e Motoristas ===");
            System.out.println("1. Cadastrar Motorista");
            System.out.println("2. Cadastrar Veículo");
            System.out.println("3. Registrar Viagem");
            System.out.println("4. Exibir Detalhes de uma Viagem");
            System.out.println("5. Excluir Motorista");
            System.out.println("6. Excluir Veículo");
            System.out.println("7. Sair");
            System.out.print("Escolha uma opção: ");

            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    cadastrarMotorista();
                    break;
                case 2:
                    cadastrarVeiculo();
                    break;
                case 3:
                    registrarViagem();
                    break;
                case 4:
                    exibirDetalhesViagem();
                    break;
                case 5:
                    excluirMotorista();
                    break;
                case 6:
                    excluirVeiculo();
                    break;
                case 7:
                    System.out.println("Encerrando o programa...");
                    return;
                default:
                    System.out.println("Opção inválida!");
            }
        }
    }

    private static void cadastrarMotorista() {
        System.out.print("Nome: ");
        String nome = scanner.nextLine();
        System.out.print("CPF: ");
        String cpf = scanner.nextLine();
        System.out.print("Habilitação (A/B/C): ");
        String habilitacao = scanner.nextLine().toUpperCase();

        Motorista motorista = new Motorista(nome, cpf, habilitacao);
        motoristas.put(cpf, motorista);
        System.out.println("Motorista cadastrado com sucesso!");
    }

    private static void cadastrarVeiculo() {
        System.out.print("Placa: ");
        String placa = scanner.nextLine();
        System.out.print("Modelo: ");
        String modelo = scanner.nextLine();
        System.out.print("Capacidade: ");
        int capacidade = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Tipo de veículo:");
        System.out.println("1. Moto");
        System.out.println("2. Carro");
        System.out.println("3. Caminhão");
        System.out.print("Escolha: ");
        int tipo = scanner.nextInt();
        scanner.nextLine();

        Veiculo veiculo = null;
        switch (tipo) {
            case 1:
                System.out.print("Cilindrada (cc): ");
                int cilindrada = scanner.nextInt();
                veiculo = new Moto(placa, modelo, capacidade, cilindrada);
                break;
            case 2:
                System.out.print("Número de Assentos: ");
                int assentos = scanner.nextInt();
                veiculo = new Carro(placa, modelo, capacidade, assentos);
                break;
            case 3:
                System.out.print("Capacidade Máxima (toneladas): ");
                double capacidadeMaxima = scanner.nextDouble();
                veiculo = new Caminhao(placa, modelo, capacidade, capacidadeMaxima);
                break;
            default:
                System.out.println("Tipo inválido!");
                return;
        }

        veiculos.put(placa, veiculo);
        System.out.println("Veículo cadastrado com sucesso!");
    }

    private static void registrarViagem() {
        if (motoristas.isEmpty() || veiculos.isEmpty()) {
            System.out.println("É necessário ter motoristas e veículos cadastrados!");
            return;
        }

        System.out.print("CPF do motorista: ");
        String cpf = scanner.nextLine();
        System.out.print("Placa do veículo: ");
        String placa = scanner.nextLine();
        System.out.print("Distância (km): ");
        double distancia = scanner.nextDouble();
        scanner.nextLine();

        Motorista motorista = motoristas.get(cpf);
        Veiculo veiculo = veiculos.get(placa);

        if (motorista == null || veiculo == null) {
            System.out.println("Motorista ou veículo não encontrado!");
            return;
        }

        boolean habilitacaoCompativel = verificarHabilitacao(motorista, veiculo);
        if (!habilitacaoCompativel) {
            System.out.println("Motorista não possui habilitação adequada para este veículo!");
            return;
        }

        Viagem viagem = new Viagem(motorista, veiculo, distancia);
        viagens.add(viagem);
        System.out.println("Viagem registrada com sucesso!");
    }

    private static boolean verificarHabilitacao(Motorista motorista, Veiculo veiculo) {
        String habilitacao = motorista.getHabilitacao();
        if (veiculo instanceof Moto && !habilitacao.equals("A"))
            return false;
        if (veiculo instanceof Carro && !habilitacao.equals("B"))
            return false;
        if (veiculo instanceof Caminhao && !habilitacao.equals("C"))
            return false;
        return true;
    }

    private static void exibirDetalhesViagem() {
        if (viagens.isEmpty()) {
            System.out.println("Não há viagens registradas!");
            return;
        }

        System.out.println("\nViagens disponíveis:");
        for (int i = 0; i < viagens.size(); i++) {
            Viagem v = viagens.get(i);
            System.out.println(i + ". " + v.getMotorista().getNome() + " - " + v.getVeiculo().getPlaca());
        }

        System.out.print("Escolha o número da viagem: ");
        int index = scanner.nextInt();
        scanner.nextLine();

        if (index >= 0 && index < viagens.size()) {
            System.out.println("\n" + viagens.get(index).getDetalhes());
        } else {
            System.out.println("Índice inválido!");
        }
    }

    private static void excluirMotorista() {
        System.out.print("CPF do motorista a ser excluído: ");
        String cpf = scanner.nextLine();

        if (motoristas.remove(cpf) != null) {
            viagens.removeIf(v -> v.getMotorista().getCpf().equals(cpf));
            System.out.println("Motorista excluído com sucesso!");
        } else {
            System.out.println("Motorista não encontrado!");
        }
    }

    private static void excluirVeiculo() {
        System.out.print("Placa do veículo a ser excluído: ");
        String placa = scanner.nextLine();

        if (veiculos.remove(placa) != null) {
            viagens.removeIf(v -> v.getVeiculo().getPlaca().equals(placa));
            System.out.println("Veículo excluído com sucesso!");
        } else {
            System.out.println("Veículo não encontrado!");
        }
    }
}
