import collections.HistoricoPedidos;
import collections.FilaPedidos;
import collections.ListaProdutos;
import exceptions.EmptyOrderException;
import exceptions.InsufficientStockException;
import exceptions.ProductNotFoundException;
import model.Pedido;
import model.Produto;

import java.util.List;
import java.util.Scanner;

public class Main {
    private static ListaProdutos<Produto> listaProdutos = new ListaProdutos<>();
    private static FilaPedidos<Pedido> filaPedidos = new FilaPedidos<>();
    private static HistoricoPedidos<Pedido> historicoPedidos = new HistoricoPedidos<>();
    private static Scanner scanner = new Scanner(System.in);
    private static int nextOrderId = 1;
    private static int nextProductId = 1;

    public static void main(String[] args) {
        while (true) {
            try {
                displayMenu();
                int choice = scanner.nextInt();
                scanner.nextLine();

                switch (choice) {
                    case 1:
                        cadastrarProduto();
                        break;
                    case 2:
                        registrarPedido();
                        break;
                    case 3:
                        processarProximoPedido();
                        break;
                    case 4:
                        exibirProdutos();
                        break;
                    case 5:
                        exibirPedidosPendentes();
                        break;
                    case 6:
                        exibirHistorico();
                        break;
                    case 7:
                        System.out.println("Encerrando o programa...");
                        return;
                    default:
                        System.out.println("Opção inválida!");
                }
            } catch (Exception e) {
                System.out.println("Erro: " + e.getMessage());
                scanner.nextLine();
            }
        }
    }

    private static void displayMenu() {
        System.out.println("\n=== Menu ===");
        System.out.println("1. Cadastrar um novo produto");
        System.out.println("2. Registrar um novo pedido");
        System.out.println("3. Processar o próximo pedido");
        System.out.println("4. Exibir produtos cadastrados");
        System.out.println("5. Exibir pedidos pendentes");
        System.out.println("6. Exibir histórico de pedidos concluídos");
        System.out.println("7. Sair");
        System.out.print("Escolha uma opção: ");
    }

    private static void cadastrarProduto() {
        System.out.print("Nome do produto: ");
        String nome = scanner.nextLine();

        System.out.print("Preço (ou enter para usar o padrão R$10,00): ");
        String precoStr = scanner.nextLine();

        System.out.print("Estoque inicial (ou enter para usar o padrão 5): ");
        String estoqueStr = scanner.nextLine();

        Produto produto;
        if (precoStr.isEmpty() && estoqueStr.isEmpty()) {
            produto = new Produto(nextProductId, nome);
        } else {
            double preco = precoStr.isEmpty() ? 10.0 : Double.parseDouble(precoStr);
            int estoque = estoqueStr.isEmpty() ? 5 : Integer.parseInt(estoqueStr);
            produto = new Produto(nextProductId, nome, preco, estoque);
        }

        listaProdutos.adicionarProduto(produto);
        nextProductId++;
        System.out.println("Produto cadastrado com sucesso!");
    }

    private static void registrarPedido() throws InsufficientStockException, EmptyOrderException {
        System.out.print("Nome do cliente: ");
        String clienteNome = scanner.nextLine();

        Pedido pedido = new Pedido(nextOrderId, clienteNome);

        System.out.println("\nProdutos disponíveis:");
        List<Produto> produtos = listaProdutos.getTodosProdutos();
        if (produtos.isEmpty()) {
            System.out.println("Nenhum produto cadastrado!");
            return;
        }
        produtos.forEach(System.out::println);

        while (true) {
            System.out.print("ID do produto (0 para finalizar): ");
            int produtoId = scanner.nextInt();
            scanner.nextLine();

            if (produtoId == 0)
                break;

            try {
                Produto produto = listaProdutos.acharProduto(produtoId);
                pedido.addProduto(produto);
                System.out.println("Produto adicionado ao pedido!");
            } catch (ProductNotFoundException e) {
                System.out.println("Produto não encontrado!");
            }
        }

        if (pedido.getProdutos().isEmpty()) {
            throw new EmptyOrderException("Não é possível criar um pedido vazio!");
        }

        filaPedidos.addPedido(pedido);
        nextOrderId++;
        System.out.println("Pedido registrado com sucesso!");
    }

    private static void processarProximoPedido() {
        Pedido pedido = filaPedidos.processarProximoPedido();
        if (pedido != null) {
            historicoPedidos.addPedido(pedido);
            System.out.println("Pedido " + pedido.getCodigoPedido() + " processado!");
            System.out.println("Cliente: " + pedido.getClienteNome());
        } else {
            System.out.println("Não há pedidos pendentes!");
        }
    }

    private static void exibirProdutos() {
        List<Produto> produtos = listaProdutos.getTodosProdutos();
        if (produtos.isEmpty()) {
            System.out.println("Nenhum produto cadastrado!");
            return;
        }

        System.out.println("\nProdutos cadastrados:");
        produtos.forEach(System.out::println);
    }

    private static void exibirPedidosPendentes() {
        List<Pedido> pedidosPendentes = filaPedidos.getPedidos();
        if (pedidosPendentes.isEmpty()) {
            System.out.println("Nenhum pedido pendente!");
            return;
        }

        System.out.println("\nPedidos pendentes:");
        pedidosPendentes.forEach(pedido -> {
            System.out.println("Pedido #" + pedido.getCodigoPedido());
            System.out.println("Cliente: " + pedido.getClienteNome());
            System.out.println("Produtos: ");
            pedido.getProdutos().forEach(
                    produto -> System.out
                            .println("  - " + produto.getDrescicao() + " (R$ " + produto.getPreco() + ")"));
            System.out.println("Valor total: R$ " + pedido.getValorTotal());
            System.out.println("--------------------");
        });
    }

    private static void exibirHistorico() {
        List<Pedido> pedidosProcessados = historicoPedidos.getHistoricoPedidos();
        if (pedidosProcessados.isEmpty()) {
            System.out.println("Nenhum pedido processado!");
            return;
        }

        System.out.println("\nHistórico de pedidos:");
        pedidosProcessados.forEach(pedido -> {
            System.out.println("Pedido #" + pedido.getCodigoPedido());
            System.out.println("Cliente: " + pedido.getClienteNome());
            System.out.println("Produtos: ");
            pedido.getProdutos().forEach(
                    produto -> System.out
                            .println("  - " + produto.getDrescicao() + " (R$ " + produto.getPreco() + ")"));
            System.out.println("Valor total: R$ " + pedido.getValorTotal());
            System.out.println("--------------------");
        });
    }
}