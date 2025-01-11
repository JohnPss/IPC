import java.util.Scanner;

import voult.enums.*;
import voult.model.*;
import voult.core.voult;

public class Main {
    public static void main(String[] args) throws Exception {
        voult voult101 = new voult();
        Scanner scanner = new Scanner(System.in);
        int option;

        do {
            System.out.println("=== Escolha uma opção: ===");
            System.out.println("1: Cadastrar sobrevivente");
            System.out.println("2: Adicionar habilidade a um sobrevivente");
            System.out.println("3: Remover habilidade de um sobrevivente");
            System.out.println("4: Adicionar recurso ao Vault");
            System.out.println("5: Consumir recurso");
            System.out.println("6: Registrar missão");
            System.out.println("7: Adicionar sobrevivente a uma missão");
            System.out.println("8: Exibir sobreviventes do Vault");
            System.out.println("9: Exibir recursos do Vault");
            System.out.println("10: Exibir missões realizadas");
            System.out.println("11: Exibir sobreviventes cadastrados em uma missão");
            System.out.println("12: Sair");
            option = scanner.nextInt();

            switch (option) {
                case 1:
                    System.out.println("Digite o nome do sobrevivente: ");
                    String nome = scanner.next();

                    System.out.println("Digite a idade do sobrevivente: ");
                    int idade = scanner.nextInt();
                    scanner.nextLine();

                    System.out.println("Status: ");
                    StatusSobreviventeEnum.exibirStatus();

                    StatusSobreviventeEnum sts = null;
                    while (sts == null) {
                        System.out.println("Digite o numero do status: ");
                        int status = scanner.nextInt();
                        try {
                            sts = StatusSobreviventeEnum.fromkey(status);
                        } catch (IllegalArgumentException e) {
                            System.out.println("Numero de status inválido. Digite novamente: ");
                        }
                    }

                    voult101.addSobrevivente(new Sobrevivente(nome, idade, sts));
                    System.out.println("Sobrevivente cadastrado com sucesso!");
                    break;
                case 2:

                    Sobrevivente sobrevivente = null;
                    while (sobrevivente == null) {
                        System.out.println("Digite o nome do sobrevivente: ");
                        String nomeSobrevivente = scanner.next();

                        try {
                            sobrevivente = voult101.getSobrevivente(nomeSobrevivente);
                        } catch (Exception e) {
                            System.out.println("Nome de sobrevivmente não encontrado. Digite novamente: ");
                        }
                    }

                    System.out.println("Habilidades: ");
                    HabilidadeEnum.exibirHabilidades();

                    HabilidadeEnum habilidade = null;
                    while (habilidade == null) {
                        System.out.println("Digite o numero da habilidade: ");
                        int habilidadeInt = scanner.nextInt();
                        try {
                            habilidade = HabilidadeEnum.fromkey(habilidadeInt);
                        } catch (IllegalArgumentException e) {
                            System.out.println("Numero de habilidade inválido. Digite novamente: ");
                        }
                    }

                    sobrevivente.addHabilidade(habilidade);
                    System.out.println("Habilidade adicionada com sucesso!");

                    break;
                case 3:
                    // sendo usando 2 vezes o mesmo código, podemos criar uma função para reutilizar
                    Sobrevivente sobreviventeH = null;
                    while (sobreviventeH == null) {
                        System.out.println("Digite o nome do sobrevivente: ");
                        String nomeSobrevivente = scanner.next();

                        try {
                            sobreviventeH = voult101.getSobrevivente(nomeSobrevivente);
                        } catch (Exception e) {
                            System.out.println("Nome de sobrevivmente não encontrado. Digite novamente: ");
                        }
                    }

                    System.out.println("Habilidades do sobrevivente: ");
                    for (HabilidadeEnum hab : sobreviventeH.getHabilidades()) {
                        System.out.println("Numero: " + hab.getValor() + ": " + hab);
                    }

                    HabilidadeEnum habilidadeR = null;
                    while (habilidadeR == null) {
                        System.out.println("Selecione o numero da habilidade que deseja retirar: ");
                        int optionHabilidade = scanner.nextInt();
                        scanner.nextLine();

                        try {
                            habilidadeR = HabilidadeEnum.fromkey(optionHabilidade);
                        } catch (IllegalArgumentException e) {
                            System.out.println("Numero de habilidade invalida: ");
                        }
                    }

                    sobreviventeH.removerHabilidade(habilidadeR);
                    System.out.println("Habilidade removida com sucesso!");

                    break;
                case 4:

                    System.out.println("Selecione o nome do recuso que deseja adicionar: ");
                    TipoRecursoEnum.exibirRecursos();

                    TipoRecursoEnum tipoRecurso = null;
                    while (tipoRecurso == null) {
                        System.out.println("Digite o numero do tipo de recurso: ");
                        int tipoRecursoInt = scanner.nextInt();
                        try {
                            tipoRecurso = TipoRecursoEnum.fromkey(tipoRecursoInt);
                        } catch (IllegalArgumentException e) {
                            System.out.println("Numero de tipo de recurso inválido. Digite novamente: ");
                        }
                    }

                    System.out.println("Digite a quantidade do recurso: ");
                    int quantidade = scanner.nextInt();

                    voult101.addRecurso(new Recurso(tipoRecurso, quantidade));
                    System.out.println("Recurso adicionado com sucesso!");

                    break;
                case 5:
                    // Consumir recurso
                    break;
                case 6:
                    // Registrar missão
                    break;
                case 7:
                    // Adicionar sobrevivente a uma missão
                    break;
                case 8:
                    voult101.exibirSobreviventes();
                    break;
                case 9:
                    // Exibir recursos do Vault
                    break;
                case 10:
                    // Exibir missões realizadas
                    break;
                case 11:
                    // Exibir sobreviventes cadastrados em uma missão
                    break;
                case 12:
                    System.out.println("Saindo...");
                    break;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
                    break;
            }
        } while (option != 12);

        scanner.close();

    }
}
