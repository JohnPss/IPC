import java.util.ArrayList;
import java.util.Scanner;

import voult.enums.*;
import voult.model.*;
import voult.ui.Menu;
import voult.core.voult;

public class Main {
    public static void main(String[] args) throws Exception {
        voult voult101 = new voult();
        Scanner scanner = new Scanner(System.in);
        Menu menu = new Menu();

        int option;

        do {
            System.out.println("=== Escolha uma opção: ===");
            System.out.println("1: Cadastrar sobrevivente");
            System.out.println("2: Adicionar habilidade a um sobrevivente");
            System.out.println("3: Remover habilidade de um sobrevivente");
            System.out.println("4: Adicionar novo recurso ao Vault");
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

                    System.out.println("\nStatus: ");
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
                    System.out.println("\nSobrevivente cadastrado com sucesso!\n");
                    break;
                case 2:

                    if (voult101.getSobreviventes().isEmpty()) {
                        System.out.println("Cadastre algum sobrevivente primeiro.");
                        break;
                    }

                    System.out.println("Sobreviventes disponiveis: ");
                    voult101.exibirSobreviventes();

                    Sobrevivente sobrevivente = null;
                    while (sobrevivente == null) {
                        System.out.println("Digite o ID do sobrevivente: ");
                        String IDSobrevivente = scanner.next();

                        try {
                            sobrevivente = voult101.getSobrevivente(IDSobrevivente);
                        } catch (Exception e) {
                            System.out.println("Nome de sobrevivmente não encontrado. Digite novamente: ");
                        }
                    }

                    while (true) {
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

                        try {
                            if (sobrevivente.addHabilidade(habilidade)) {
                                System.out.println("Habilidade adicionada com sucesso!");
                            }
                        } catch (IllegalStateException e) {
                            System.out.println("Erro ao adicionar habilidade: " + e.getMessage());
                            break;
                        } catch (IllegalArgumentException e) {
                            System.out.println("A habilidade já existe: " + habilidade + ". Tente adicionar outra.");
                        }

                        System.out.println("Deseja adicionar outra habilidade? (Y/N)");
                        String optionHabilidade = scanner.next();

                        if (optionHabilidade.equalsIgnoreCase("N")) {
                            break;
                        }
                    }
                    break;
                case 3:
                    System.out.println("Sobreviventes:");
                    voult101.exibirSobreviventesHabilidades();

                    Sobrevivente sobreviventeH = null;
                    while (sobreviventeH == null) {
                        System.out.println("Digite o ID do sobrevivente: ");
                        String idSobrevivente = scanner.next();

                        try {
                            sobreviventeH = voult101.getSobrevivente(idSobrevivente);
                        } catch (Exception e) {
                            System.out.println("ID de sobrevivente não encontrado. Digite novamente: ");
                        }
                    }

                    if (sobreviventeH.getHabilidades().isEmpty()) {
                        System.out.println("O sobrevivente não possui habilidades para remover.");
                        break;
                    }

                    System.out.println("Habilidades do sobrevivente: ");
                    for (HabilidadeEnum hab : sobreviventeH.getHabilidades()) {
                        System.out.println("Número: " + hab.getValor() + " - " + hab);
                    }

                    HabilidadeEnum habilidadeR = null;
                    while (habilidadeR == null) {
                        System.out.println("Digite o número da habilidade que deseja remover: ");
                        int optionHabilidade = scanner.nextInt();
                        scanner.nextLine();

                        try {
                            habilidadeR = HabilidadeEnum.fromkey(optionHabilidade);
                            if (!sobreviventeH.getHabilidades().contains(habilidadeR)) {
                                System.out.println("O sobrevivente não possui esta habilidade. Tente novamente.");
                                habilidadeR = null;
                            }
                        } catch (IllegalArgumentException e) {
                            System.out.println("Número de habilidade inválido. Tente novamente.");
                        }
                    }

                    try {
                        sobreviventeH.removerHabilidade(habilidadeR);
                        System.out.println("Habilidade removida com sucesso!");
                    } catch (Exception e) {
                        System.out.println("Erro ao remover a habilidade: " + e.getMessage());
                    }
                    break;

                case 4:

                    System.out.println("Selecione o nome do recurso que deseja adicionar: ");
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

                    if (voult101.addRecurso(new Recurso(tipoRecurso, quantidade))) {
                        System.out.println("Recurso adicionado com sucesso!");
                    } else {
                        System.out.println("Recurso ja existe.");
                        try {
                            voult101.addQuantidadeEspecifica(new Recurso(tipoRecurso, quantidade));
                        } catch (Exception x) {
                            System.out.println("Ops, Algo deu errado!");
                        }
                        System.out.println("Os valores foram adicionados ao existente.");
                    }

                    break;
                case 5:
                    System.out.println("Recursos diponiveis:");
                    voult101.exibirRecursos();

                    TipoRecursoEnum tipo = null;
                    while (tipo == null) {
                        System.out.println("Selecione o numero do rescuso: ");
                        int optionRecurso = scanner.nextInt();
                        try {
                            tipo = TipoRecursoEnum.fromkey(optionRecurso);
                        } catch (IllegalArgumentException e) {
                            System.out.println("Numero de recurso inválido. Digite novamente: ");
                        }
                    }

                    System.out.println("Digite a quantidade a ser consumida: ");
                    int quantidadeConsumir = scanner.nextInt();
                    try {
                        voult101.consumirRecurso(tipo, quantidadeConsumir);
                    } catch (IllegalArgumentException e) {
                        System.out.println("Quantidade invalidada!");
                        break;
                    }

                    System.out.println("Recurso consumido com sucesso!");

                    break;
                case 6:
                    System.out.println("Digite o nome da missão:");
                    String nomeMissao = scanner.next();
                    System.out.println("Digite o objetivo da missão:");
                    String objetivoMissao = scanner.next();
                    System.out.println("Digite o local da missão:");
                    String localMissao = scanner.next();

                    Missao missao = new Missao(nomeMissao, objetivoMissao, localMissao, new ArrayList<>(), null);
                    while (missao.getStatus() == null) {
                        try {
                            menu.setStatusMissao(missao);
                        } catch (Exception e) {
                            System.out.println("Status inválido. Digite novamente: ");
                        }
                    }

                    try {
                        voult101.addMissao(missao);
                    } catch (Exception e) {
                        System.out.println("Nome de missão já cadastrada.");
                    }

                    if (missao.getStatus().equals(StatusMissaoEnum.SUCESSO)) {
                        System.out.println("A missão foi concluída. Existem recursos coletados? (Y/N)");
                        String temRecursos = scanner.next();

                        if (temRecursos.equalsIgnoreCase("Y")) {
                            ArrayList<Recurso> recursosColetados = new ArrayList<>();
                            while (true) {
                                System.out.println("Selecione o nome do recurso coletado: ");
                                TipoRecursoEnum.exibirRecursos();

                                TipoRecursoEnum tipoRecurso2 = null;
                                while (tipoRecurso2 == null) {
                                    System.out.println("Digite o número do tipo de recurso: ");
                                    int tipoRecursoInt = scanner.nextInt();
                                    try {
                                        tipoRecurso2 = TipoRecursoEnum.fromkey(tipoRecursoInt);
                                    } catch (IllegalArgumentException e) {
                                        System.out.println("Número de tipo de recurso inválido. Digite novamente: ");
                                    }
                                }

                                System.out.println("Digite a quantidade do recurso coletado: ");
                                int quantidade2 = scanner.nextInt();

                                recursosColetados.add(new Recurso(tipoRecurso2, quantidade2));

                                System.out.println("Deseja adicionar outro recurso? (Y/N)");
                                String optionRecurso = scanner.next();

                                if (optionRecurso.equalsIgnoreCase("N")) {
                                    break;
                                }
                            }

                            for (Recurso recurso : recursosColetados) {
                                if (voult101.addRecurso(recurso)) {
                                    System.out.println(
                                            "Recurso " + recurso.getNome() + " adicionado com sucesso!");
                                } else {
                                    System.out.println("Recurso " + recurso.getNome() + " já existe.");
                                    try {
                                        voult101.addQuantidadeEspecifica(recurso);
                                    } catch (Exception x) {
                                        System.out.println("Ops, algo deu errado ao atualizar a quantidade.");
                                    }
                                    System.out.println("Os valores foram adicionados ao recurso existente.");
                                }
                            }
                        } else {
                            System.out.println("Nenhum recurso coletado nesta missão.");
                        }
                    } else {
                        System.out.println("A missão não foi concluída, portanto, não há recursos para adicionar.");
                    }

                    break;
                case 7:
                    System.out.println("Missoes disponiveis");
                    voult101.exibirMissoes();

                    System.out.println("Digite o nome da missao:");
                    nomeMissao = scanner.next();
                    Missao missao2 = voult101.encontrarMissao(nomeMissao);

                    try {
                        menu.addSobreviventeMissaoPeloID(missao2, voult101.getSobreviventes());
                    } catch (IllegalArgumentException e) {
                        System.out.println(e.getMessage());
                    }

                    break;
                case 8:
                    voult101.exibirSobreviventesHabilidades();
                    break;
                case 9:
                    voult101.exibirRecursos();
                    break;
                case 10:
                    voult101.exibirMissoes();
                    break;
                case 11:
                    voult101.exibirMissoesRealizadas();

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
