import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class GerenciamentoPacotes {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ListaCliente clientes = new ListaCliente();
        FilaEntradaPacotes filaEntrada = new FilaEntradaPacotes();
        FilaPrioridadePacotes filaPrioridade = new FilaPrioridadePacotes();
        HistoricoPacotes historico = new HistoricoPacotes();

        while (true) {
            System.out.println("\n=== Menu ===");
            System.out.println("1. Adicionar novo cliente");
            System.out.println("2. Registrar novo pacote");
            System.out.println("3. Processar próximo pacote");
            System.out.println("4. Exibir fila de entrada");
            System.out.println("5. Exibir fila de prioridade");
            System.out.println("6. Exibir histórico");
            System.out.println("7. Exibir clientes");
            System.out.println("8. Sair");
            System.out.print("Escolha uma opção: ");

            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    System.out.print("Nome do cliente: ");
                    String nome = scanner.nextLine();
                    System.out.print("CPF: ");
                    String cpf = scanner.nextLine();
                    clientes.adicionarCliente(nome, cpf);
                    break;
                case 2:
                    System.out.print("CPF do cliente: ");
                    String cpfPacote = scanner.nextLine();
                    System.out.print("Pacote é prioritário? (S/N): ");
                    boolean isPrioritario = scanner.nextLine().equalsIgnoreCase("S");
                    clientes.buscarCliente(cpfPacote);

                    break;
                case 3:
                    Pacote pacoteProcessado = filaPrioridade.isEmpty() ? filaEntrada.poll() : filaPrioridade.poll();
                    if (pacoteProcessado != null) {
                        historico.add(pacoteProcessado);
                    }
                    break;
                case 4:
                    filaEntrada.forEach(System.out::println);
                    break;
                case 5:
                    filaPrioridade.forEach(System.out::println);
                    break;
                case 6:
                    historico.forEach(System.out::println);
                    break;
                case 7:
                    clientes.forEach(System.out::println);
                    break;
                case 8:
                    System.out.println("Programa encerrado.");
                    return;
            }
        }
    }
}
