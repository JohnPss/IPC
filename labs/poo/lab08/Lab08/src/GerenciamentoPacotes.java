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
                    clientes.exibirClientes();
                    System.out.println("Digite o CPF do cliente: ");
                    String CPF = scanner.nextLine();
                    Cliente cliente = clientes.buscarCliente(CPF);
                    if (cliente != null) {
                        System.out.println("Digite o codigo do pacote: ");
                        int codigoPacote = scanner.nextInt();
                        scanner.nextLine();
                        System.out.println("Digite a descrição do pacote: ");
                        String descricao = scanner.nextLine();
                        System.out.println("Digite a prioridade do pacote: 1 (Prioridade) 2, (Normal) ");

                        int prioridade = scanner.nextInt();
                        if (prioridade == 1 && prioridade == 2) {
                            System.out.println("Prioridade inválida!");
                            break;

                        }

                        Pacote pacote = new Pacote(codigoPacote, descricao, prioridade, CPF);
                        if (pacote.getPrioridade() == 1) {
                            filaPrioridade.adicionarPacote(pacote);
                        } else {
                            filaEntrada.adicionarPacote(pacote);
                        }
                    } else {
                        System.out.println("Cliente não encontrado!");
                    }
                    break;
                case 3:
                    if (!filaPrioridade.isEmpty()) {
                        Pacote pacote2 = filaPrioridade.removerPacote();
                        historico.adicionarAoHistorico(pacote2);
                        System.out.println("Pacote entregue com sucesso!");
                    } else if (!filaEntrada.isEmpty()) {
                        Pacote pacote2 = filaEntrada.removerPacote();
                        historico.adicionarAoHistorico(pacote2);
                        System.out.println("Pacote entregue com sucesso!");
                    } else {
                        System.out.println("Não há pacotes para serem entregues!");
                    }

                    break;
                case 4:
                    filaEntrada.exibirFila();

                    break;
                case 5:
                    filaPrioridade.exibirFila();
                    break;
                case 6:
                    historico.exibirHistorico();
                    break;
                case 7:
                    clientes.exibirClientes();
                    break;
                case 8:
                    return;
            }
        }
    }
}
